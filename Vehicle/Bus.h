#pragma once
#include "Vehicle.h"
#include "Enums.h"

class Bus : public Vehicle
{
protected:
	int bus_length;
	BusPurpose purpose;

public:
	Bus(int w, int p, int bl, BusPurpose bp);
	void print() override;
};
