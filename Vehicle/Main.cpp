#include <iostream>
#include "Truck.h"
#include "Vehicle.h"
#include "Moto.h"
#include "Bicycle.h"
#include "Bus.h"
#include "Car.h"

int main()
{
	Car car1(4, 4, sedan);
	Moto motocycle(2, 2, 15);
	Truck truck(4, 8, 2000);
	Bicycle bike(2, 1, 18);
	Bus autobus(6, 60, 17, passenger);

	car1.print();
	motocycle.print();
	truck.print();
	bike.print();
	autobus.print();
}