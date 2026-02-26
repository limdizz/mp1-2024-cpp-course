#include "Car.h"
#include <iostream>

Car::Car(int w, int p, CarType t)
    : Vehicle(w, p), type(t)
{
}

void Car::print()
{
    std::string typeStr;
    switch (type)
    {
    case sedan:
        typeStr = "sedan";
        break;
    case hatch:
        typeStr = "hatch";
        break;
    case van:
        typeStr = "van";
        break;
    }

    std::cout << "CAR: Number of wheels: " << wheels
              << ", number of passengers: " << passengers
              << ", type of car: " << typeStr << std::endl;
}