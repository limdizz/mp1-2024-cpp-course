#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle
{
	int number_of_speeds;

public:
	Bicycle(int w, int p, int nos);
	void print();
};
