#include "Circuit.h"
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>
Circuit::Circuit()
{
	nmax = 100;
	n = l = w = 0;
	v = (Car**)(malloc(nmax * sizeof(Car*)));
}
void Circuit::SetLength(int L)
{
	l = L;
}
void Circuit::SetWeather(Weather vreme)
{
	w = (int)vreme;
}
bool Circuit::AddCar(Car* masina)
{
	if (n < nmax)
	{
		v[n] = masina;
		n++;
		return 1;
	}
	else return 0;
}
void Circuit::Race()
{
	//sort descresc pe baza v[i].avg_speed[w];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (this->v[i]->Speed(this->w) < this->v[j]->Speed(this->w))
				std::swap(v[i], v[j]);
}
void Circuit::ShowFinalRanks()
{
	float time;
	int fail = 0;
	for (int i = 0; i < n; i++)
	{
		time = (float)l/(float)v[i]->Speed(w);
		if (time * v[i]->Consum(this->w) <= v[i]->Fuel())
		{
			printf("locul %d: %.2f h, ", i + 1 - fail, time);
			std::cout << v[i]->Name() << '\n';
		}
		else fail++;
	}
}
void Circuit::ShowWhoDidNotFinish()
{
	printf("\nNu au terminat:\n");
	float time;
	for (int i = 0; i < n; i++)
	{
		time = (float)l / (float)v[i]->Speed(w);
		if (time * v[i]->Consum(this->w) > v[i]->Fuel())
		{
			std::cout << v[i]->Name();
			printf(", ar fi terminat in %.2f h\n", time);
		}
	}
}
