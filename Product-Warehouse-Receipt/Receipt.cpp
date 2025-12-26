#include "Receipt.h"

void Receipt::addFromWarehouse(Warehouse& w, const std::string& name, int count) {
    if (!w.checkAvailable(name, count)) {
        throw std::logic_error("Недостаточно товара на складе или товара нет");
    }

    // Находим товар на складе
    int idx = w.find(name);
    if (idx == -1) {
        throw std::logic_error("Товара нет на складе");
    }

    // Получаем товар со склада
    const std::vector<Product>& products = w.getProducts();
    const Product& warehouseProduct = products[idx];

    // Проверяем, есть ли уже такой товар в чеке
    bool found = false;
    for (auto& item : list) {
        if (item.getName() == name) {
            item.addCount(count);
            found = true;
            break;
        }
    }

    if (!found) {
        Product newProduct = warehouseProduct;
        newProduct.setCount(count);
        list.push_back(newProduct);
    }

    w.take(name, count);
}

void Receipt::remove(const std::string& name) {
    auto it = std::remove_if(list.begin(), list.end(),
        [&](const Product& t) { return t.getName() == name; });
    list.erase(it, list.end());
}

double Receipt::calculateTotalSum() const {
    double sum = 0;
    for (const auto& item : list) {
        sum += item.calculateTotalPrice();
    }
    return sum;
}

void Receipt::print() const {
    std::cout << "\n=== ЧЕК ===\n";
    if (list.empty()) {
        std::cout << "Чек пуст\n";
    }
    else {
        for (const auto& item : list) {
            item.print();
        }
    }
    std::cout << "ИТОГО: " << calculateTotalSum() << " руб." << std::endl;
}

void Receipt::clear() {
    list.clear();
}

size_t Receipt::size() const {
    return list.size();
}

bool Receipt::empty() const {
    return list.empty();
}