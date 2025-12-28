#include <iostream>
#include "Warehouse.h"
#include "Receipt.h"
#include "Product.h"

int main()
{
    Warehouse w;

    w.add(Product(1, "Bread", 30, 20, 0));
    w.add(Product(2, "Milk", 70, 15, 10));
    w.add(Product(3, "Cheese", 300, 5, 15));

    w.print();

    Receipt r;

    std::string name;
    int count;

    while (true)
    {
        std::cout << "\nEnter product name (or exit): ";
        std::cin >> name;
        if (name == "exit")
            break;

        std::cout << "Count: ";
        std::cin >> count;

        try
        {
            r.addFromWarehouse(w, name, count);
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }

        r.print();
        w.print();
    }

    std::cout << "\nThe final receipt:";
    r.print();

    return 0;
}
