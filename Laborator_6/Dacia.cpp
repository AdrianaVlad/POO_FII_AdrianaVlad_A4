#include "Dacia.h"
#include <string>
Dacia::Dacia()
{
	this->fuel_cap = 50;
	this->fuel_consum[0] = 6;
	this->fuel_consum[1] = 5;
	this->fuel_consum[2] = 7;
	this->avg_speed[0] = 70;//Rain
	this->avg_speed[1] = 90;//Sun
	this->avg_speed[2] = 60;//Snow
	this->type = "Dacia";
}
int Dacia::Speed(int w)
{
	return this->avg_speed[w];
}
int Dacia::Consum(int w)
{
	return this->fuel_consum[w];
}
int Dacia::Fuel()
{
	return this->fuel_cap;
}
std::string Dacia::Name()
{
	return this->type;
}