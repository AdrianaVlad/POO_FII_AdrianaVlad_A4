#include "Toyota.h"
#include <string>
Toyota::Toyota()
{
	this->fuel_cap = 40;
	this->fuel_consum[0] = 7;
	this->fuel_consum[1] = 6;
	this->fuel_consum[1] = 7;
	this->avg_speed[0] = 60;//Rain
	this->avg_speed[1] = 90;//Sun
	this->avg_speed[2] = 70;//Snow
	this->type = "Toyota";
}
int Toyota::Speed(int w)
{
	return this->avg_speed[w];
}
int Toyota::Consum(int w)
{
	return this->fuel_consum[w];
}
int Toyota::Fuel()
{
	return this->fuel_cap;
}
std::string Toyota::Name()
{
	return this->type;
}