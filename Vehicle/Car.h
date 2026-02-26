#pragma once
#include "Vehicle.h"
#include "Enums.h"
#include <string>

class Car : public Vehicle
{
protected:
    CarType type;

public:
    Car(int w, int p, CarType t);
    void print() override;
};
