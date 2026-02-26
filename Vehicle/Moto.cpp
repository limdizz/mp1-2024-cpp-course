#include "Moto.h"
#include <iostream>

Moto::Moto(int w, int p, int e)
    : Vehicle(w, p), energy(e)
{
}

void Moto::print()
{
    std::cout << "MOTO: Number of wheels: " << wheels
              << ", number of passengers: " << passengers
              << ", power: " << energy << " horsepowers" << std::endl;
}