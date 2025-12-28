#pragma once
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Warehouse.h"

class Receipt
{
private:
    std::vector<Product> list;

public:
    void addFromWarehouse(Warehouse &w, const std::string &name, int count);

    void remove(const std::string &name);

    double calculateTotalSum() const;

    void print() const;

    void clear();

    size_t size() const;

    bool empty() const;
};