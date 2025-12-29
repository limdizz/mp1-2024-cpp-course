#include <iostream>
#include "Exception.h"
#include "Vector.h"

int main()
{
    bool confirmation = true;
    while (confirmation)
    {
        try
        {
            int usize1, usize2, uindex;
            std::cout << "Enter size of vector v1: ";
            std::cin >> usize1;

            Vector v1(usize1);
            std::cout << "Enter values for vector v1: ";
            std::cin >> v1;
            std::cout << std::endl;

            std::cout << "Enter size of vector v2: ";
            std::cin >> usize2;

            Vector v2(usize2);
            std::cout << "Enter values for vector v2: ";
            std::cin >> v2;
            std::cout << std::endl;

            std::cout << "v1: " << v1 << std::endl;
            std::cout << "v2: " << v2 << std::endl
                      << std::endl;

            Vector v3 = v1 + v2;
            std::cout << "v1 + v2: " << v3 << std::endl;

            Vector v4 = v1 - v2;
            std::cout << "v1 - v2: " << v4 << std::endl
                      << std::endl;

            Vector v5 = ++v1;
            std::cout << "++v1: " << v5 << std::endl;
            Vector v6 = v2++;
            std::cout << "v2++: " << v6 << std::endl;

            double dotProduct = v1 * v2;
            std::cout << "v1 * v2: " << dotProduct << std::endl
                      << std::endl;

            bool t = v1 < v2;
            std::cout << "v1 < v2: " << t << std::endl;
            bool t1 = v1 > v2;
            std::cout << "v1 > v2: " << t1 << std::endl;
            bool t2 = (v1 == v2);
            std::cout << "v1 = v2: " << t2 << std::endl;
            bool t3 = (v1 != v2);
            std::cout << "v1 != v2: " << t3 << std::endl
                      << std::endl;

            Vector scaledVector = v1 * 2.0;
            std::cout << "v1 * 2.0: " << scaledVector << std::endl;

            Vector scaledVector2 = 3.0 * v2;
            std::cout << "3.0 * v2: " << scaledVector2 << std::endl;

            double lengthV1 = v1.length();
            std::cout << "Length of v1: " << lengthV1 << std::endl;

            scaledVector2.resize(2);
            std::cout << "Resized vector with resize(2): " << scaledVector2 << std::endl;

            scaledVector2.pushback(10);
            scaledVector2.pushback(20);
            std::cout << "New vector with pushed 10 and 20: " << scaledVector2 << std::endl
                      << std::endl;

            std::cout << "Enter index for " << scaledVector2 << " element position: " << std::endl;
            std::cin >> uindex;
            std::cout << "Operator[] tries to return the value from the position " << uindex << std::endl;
            std::cout << scaledVector2[uindex] << std::endl
                      << std::endl;

            Vector v10(3);
            std::cout << "Vector v10(3) initialized" << std::endl;
            std::cout << "Vector v10(3) is tried to be resized with value -1" << std::endl;
            v10.resize(-1);
        }
        catch (const Exception &ex)
        {
            std::cout << "Exception caught: " << ex << std::endl;
        }

        std::cout << "Enter 1 if you want to create vectors again or 0 to quit: " << std::endl;
        std::cin >> confirmation;
        std::cout << std::endl;
    }
}
