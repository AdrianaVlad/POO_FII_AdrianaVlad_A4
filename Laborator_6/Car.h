#pragma once
#include <string>
class Car
{
protected:	
	int fuel_cap, fuel_consum[4], avg_speed[4];
	std::string type;
public:
	virtual int Speed(int w) = 0;
	virtual int Consum(int w) = 0;
	virtual int Fuel() = 0;
	virtual std::string Name() = 0;
};

