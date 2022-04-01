#include "Mercedes.h"
#include <string>
Mercedes::Mercedes()
{
	this->fuel_cap = 70;
	this->fuel_consum[0] = 9;
	this->fuel_consum[0] = 7;
	this->fuel_consum[0] = 8;
	this->avg_speed[0] = 50;//Rain
	this->avg_speed[1] = 80;//Sun
	this->avg_speed[2] = 70;//Snow
	this->type = "Mercedes";
}
int Mercedes::Speed(int w)
{
	return this->avg_speed[w];
}
int Mercedes::Consum(int w)
{
	return this->fuel_consum[w];
}
int Mercedes::Fuel()
{
	return this->fuel_cap;
}
std::string Mercedes::Name()
{
	return this->type;
}