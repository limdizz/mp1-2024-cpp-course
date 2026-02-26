#include "Bus.h"
#include <string>
#include <iostream>

Bus::Bus(int w, int p, int bl, BusPurpose bp) : Vehicle(w, p) { purpose = bp, bus_length = bl; }

void Bus::print()
{
	std::string BusPurpose;
	switch (purpose)
	{
	case passenger:
		BusPurpose = "passenger";
		break;
	case cargo:
		BusPurpose = "cargo";
		break;
	case school:
		BusPurpose = "school";
		break;
	}
	std::cout << "BUS: " << "Number of wheels: " << wheels << ", number of passengers: " << passengers << ", bus purpose: " << BusPurpose << ", bus length: " << bus_length << "m" << std::endl;
}