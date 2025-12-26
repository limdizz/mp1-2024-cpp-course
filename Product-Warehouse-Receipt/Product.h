#pragma once
#include <iostream>
#include <exception>
#include <string>

class Product {
    int id;
    std::string name;
    double price;
    int count;
    int sale;  

public:
    Product(int _id = 0, std::string _name = "", double _price = 0.0, int _count = 0, int _sale = 0);
    Product(const Product& other);

    bool operator==(const Product& other) const;
    bool operator<(const Product& other) const;
    Product operator+=(const Product& other);
    Product& operator-=(const Product& other);

    double calculateTotalPrice() const;
    void print() const;

    std::string getName() const;
    int getId() const;
    int getCount() const;
    double getPrice() const;
    int getSale() const;

    void addCount(int c);
    void subCount(int c);
    void setCount(int c);

    friend class Receipt;
    friend class Warehouse;
};

