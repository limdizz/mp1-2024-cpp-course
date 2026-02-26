#include "Bicycle.h"
#include <iostream>

Bicycle::Bicycle(int w, int p, int nos) : Vehicle(w, p) { number_of_speeds = nos; }

void Bicycle::print()
{
	std::cout << "BICYCLE: Number of wheels: " << wheels << ", number of passengers: " << passengers << ", number of speeds: " << number_of_speeds << std::endl;
}