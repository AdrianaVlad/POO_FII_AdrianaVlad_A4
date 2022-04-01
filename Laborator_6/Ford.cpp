#include "Ford.h"
#include <string>
Ford::Ford()
{
	this->fuel_cap = 10;
	this->fuel_consum[0] = 10;
	this->fuel_consum[1] = 10;
	this->fuel_consum[2] = 10;
	this->avg_speed[0] = 65;//Rain
	this->avg_speed[1] = 80;//Sun
	this->avg_speed[2] = 70;//Snow
	this->type = "Ford";
}
int Ford::Speed(int w)
{
	return this->avg_speed[w];
}
int Ford::Consum(int w)
{
	return this->fuel_consum[w];
}
int Ford::Fuel()
{
	return this->fuel_cap;
}
std::string Ford::Name()
{
	return this->type;
}