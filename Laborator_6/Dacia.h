#pragma once
#include "Car.h"
#include <string>
class Dacia :
    public Car
{
public:
    int Speed(int w);
    int Consum(int w);
    int Fuel();
    std::string Name();
    Dacia();
};

