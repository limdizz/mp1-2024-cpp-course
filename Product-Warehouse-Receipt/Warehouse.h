#pragma once
#include <vector>
#include "Product.h"
#include <stdexcept>
#include <iostream>

class Warehouse
{
private:
    std::vector<Product> products;

public:
    void add(const Product &product);

    int find(const std::string &name) const;

    bool checkAvailable(const std::string &name, int need) const;

    void take(const std::string &name, int count);

    void print() const;

    const std::vector<Product> &getProducts() const;

    friend class Receipt;
};