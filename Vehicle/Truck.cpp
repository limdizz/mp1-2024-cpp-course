#include "Truck.h"
#include <iostream>

Truck::Truck(int w, int p, int c) : Vehicle(w, p) { cargo = c; }

void Truck::print()
{
	std::cout << "TRUCK: Number of wheels: " << wheels << ", number of passengers: " << passengers << ", cargo: " << cargo << "kg" << std::endl;
}