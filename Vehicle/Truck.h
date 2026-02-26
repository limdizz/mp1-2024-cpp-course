#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
	int cargo;

public:
	Truck(int w, int p, int c);
	void print();
};