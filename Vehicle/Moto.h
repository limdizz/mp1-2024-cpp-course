#pragma once
#include "Vehicle.h"

class Moto : public Vehicle
{
    int energy;

public:
    Moto(int w, int p, int e);
    void print() override;
};
