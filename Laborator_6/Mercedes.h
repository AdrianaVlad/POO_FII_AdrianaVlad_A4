#pragma once
#include "Car.h"
#include <string>
class Mercedes :
    public Car
{
public:
    int Speed(int w);
    int Consum(int w);
    int Fuel();
    std::string Name();
    Mercedes();
};
