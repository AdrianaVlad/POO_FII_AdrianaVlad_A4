#include <iostream>
float operator""_Kelvin(const char * c)
{
	float x = 0;
	for (int i = 0; c[i]; i++)
	{
		x = x * 10 + c[i] - '0';
	}
	return (float)(x - 273.15);
}
float operator""_Fahrenheit(const char * c)
{
	float x = 0;
	for (int i = 0; c[i]; i++)
	{
		x = x * 10 + c[i] - '0';
	}
	return (float)((x - 32)/1.8);
}
int main()
{
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	std::cout << a << ' ' << b;
	return 0;
}