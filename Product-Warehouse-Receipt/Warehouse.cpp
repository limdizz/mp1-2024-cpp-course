#include "Warehouse.h"

void Warehouse::add(const Product& product) {
    products.push_back(product);
}

int Warehouse::find(const std::string& name) const {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].getName() == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool Warehouse::checkAvailable(const std::string& name, int need) const {
    int idx = find(name);
    if (idx == -1) return false;
    return products[idx].getCount() >= need;
}

void Warehouse::take(const std::string& name, int count) {
    int idx = find(name);
    if (idx == -1) {
        throw std::logic_error("Товара нет на складе");
    }
    products[idx].subCount(count);
}

void Warehouse::print() const {
    std::cout << "\n=== Склад ===\n";
    if (products.empty()) {
        std::cout << "Склад пуст\n";
    }
    else {
        for (const auto& product : products) {
            product.print();
        }
    }
}

const std::vector<Product>& Warehouse::getProducts() const {
    return products;
}