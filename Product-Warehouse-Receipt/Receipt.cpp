#include "Receipt.h"

void Receipt::addFromWarehouse(Warehouse &w, const std::string &name, int count)
{
    if (!w.checkAvailable(name, count))
    {
        throw std::logic_error("The product is out of stock or there is no product");
    }

    int idx = w.find(name);
    if (idx == -1)
    {
        throw std::logic_error("The product is out of stock");
    }

    const std::vector<Product> &products = w.getProducts();
    const Product &warehouseProduct = products[idx];

    bool found = false;
    for (auto &item : list)
    {
        if (item.getName() == name)
        {
            item.addCount(count);
            found = true;
            break;
        }
    }

    if (!found)
    {
        Product newProduct = warehouseProduct;
        newProduct.setCount(count);
        list.push_back(newProduct);
    }

    w.take(name, count);
}

void Receipt::remove(const std::string &name)
{
    auto it = std::remove_if(list.begin(), list.end(),
                             [&](const Product &t)
                             { return t.getName() == name; });
    list.erase(it, list.end());
}

double Receipt::calculateTotalSum() const
{
    double sum = 0;
    for (const auto &item : list)
    {
        sum += item.calculateTotalPrice();
    }
    return sum;
}

void Receipt::print() const
{
    std::cout << "\n=== RECEIPT ===\n";
    if (list.empty())
    {
        std::cout << "The receipt is empty\n";
    }
    else
    {
        for (const auto &item : list)
        {
            std::cout << item;
        }
    }
    std::cout << "TOTAL: " << calculateTotalSum() << " RUB" << std::endl;
}

void Receipt::clear()
{
    list.clear();
}

size_t Receipt::size() const
{
    return list.size();
}

bool Receipt::empty() const
{
    return list.empty();
}