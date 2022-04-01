#include "Mazda.h"
#include <string>
Mazda::Mazda()
{
	this->fuel_cap = 30;
	this->fuel_consum[0] = 4;
	this->fuel_consum[1] = 4;
	this->fuel_consum[2] = 5;
	this->avg_speed[0] = 80;//Rain
	this->avg_speed[1] = 100;//Sun
	this->avg_speed[2] = 70;//Snow
	this->type = "Mazda";
}
int Mazda::Speed(int w)
{
	return this->avg_speed[w];
}
int Mazda::Consum(int w)
{
	return this->fuel_consum[w];
}
int Mazda::Fuel()
{
	return this->fuel_cap;
}
std::string Mazda::Name()
{
	return this->type;
}