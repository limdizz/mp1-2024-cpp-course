#include "Product.h"
#include <string>

double Product::calculateTotalPrice() const {
    double total = price * count;
    if (sale > 0 && sale <= 100) {
        total = total * (100.0 - sale) / 100.0;
    }
    return total;
}

Product::Product(int _id, std::string _name, double _price,
    int _count, int _sale)
    : id(_id), name(_name), price(_price), count(_count), sale(_sale) {
}

Product::Product(const Product& other)
    : id(other.id), name(other.name), price(other.price),
    count(other.count), sale(other.sale) {
}

bool Product::operator==(const Product& other) const {
    return id == other.id && name == other.name &&
        std::abs(price - other.price) < 0.001 && sale == other.sale;
}

bool Product::operator<(const Product& other) const {
    return calculateTotalPrice() < other.calculateTotalPrice();
}

Product Product::operator+=(const Product& other) {
    if (*this == other) {
        count += other.count;
    }
    return *this;
}

Product& Product::operator-=(const Product& other) {
    if (*this == other) {
        count -= other.count;
        if (count < 0) {
            throw std::logic_error("Count < 0");
        }
    }
    return *this;
}

void Product::print() const {
    double total = calculateTotalPrice();
    std::cout << "ID: " << id << ", Name: " << name
        << ", Price: " << price << ", Count: " << count
        << ", Sale: " << sale << "%, Sum: " << total << std::endl;
}

std::string Product::getName() const { return name; }
int Product::getId() const { return id; }
int Product::getCount() const { return count; }
double Product::getPrice() const { return price; }
int Product::getSale() const { return sale; }

void Product::addCount(int c) {
    if (c < 0) throw std::logic_error("Ќельз€ добавить отрицательное количество");
    count += c;
}

void Product::subCount(int c) {
    if (c < 0) throw std::logic_error("Ќельз€ вычесть отрицательное количество");
    if (count - c < 0)
        throw std::logic_error("ќстаток стал отрицательным");
    count -= c;
}

void Product::setCount(int c) {
    if (c < 0)
        throw std::logic_error(" оличество не может быть отрицательным");
    count = c;
}