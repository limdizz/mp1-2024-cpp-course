#pragma once

class Vehicle
{
protected:
    int wheels;
    int passengers;

public:
    Vehicle(int _w, int _p);
    virtual ~Vehicle() = default;
    virtual void print() = 0;
};
