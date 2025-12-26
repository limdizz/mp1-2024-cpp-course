#include <iostream>
#include "Warehouse.h"
#include "Receipt.h"
#include "Product.h"
#include <windows.h>

int main()
{
    SetConsoleCP(1251);       // Устанавливает кодировку ВВОДА (cin)
    SetConsoleOutputCP(1251);

    Warehouse w;

    w.add(Product(1, "Хлеб", 30, 20, 0));
    w.add(Product(2, "Молоко", 70, 15, 10));
    w.add(Product(3, "Сыр", 300, 5, 15));

    w.print();

    Receipt r;

    std::string name;
    int count;

    while (true) {
        std::cout << "\nВведите товар (или exit): ";
        std::cin >> name;
        if (name == "exit") break;

        std::cout << "Количество: ";
        std::cin >> count;

        try {
            r.addFromWarehouse(w, name, count);
        }
        catch (std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

        r.print();
        w.print();
    }

    std::cout << "\nФинальный чек:";
    r.print();

    return 0;
}

