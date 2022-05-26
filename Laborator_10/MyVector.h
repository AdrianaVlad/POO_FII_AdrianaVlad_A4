#pragma once
#include <functional>
class MyVector
{
	int n=0;
	int v[100];
public:
	bool Add(int x);
	bool Delete(int index);
	void Iterate(int(*fct)(int x));
	void Filter(bool(*fct)(int x));
	void Afisare();
};

