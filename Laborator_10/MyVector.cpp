#include "MyVector.h"
#include "functional"
#include <iostream>
bool MyVector::Add(int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (v[i] == x)
			break;
	if (i < n)
		return 0;
	v[n++] = x;
	return 1;
}
bool MyVector::Delete(int index)
{
	int i;
	if (index >= n)
		return 0;
	for (i=index; i < n; i++)
		v[i] = v[i + 1];
	n--;
	return 1;
}
void MyVector::Iterate(int(*fct)(int x))
{
	int i;
	for (i = 0; i < n; i++)
	{
		v[i] = fct(v[i]);
	}
}
void MyVector::Filter(bool(*fct)(int x))
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (fct(v[i]))
			this->Delete(i);
	}
}
void MyVector::Afisare()
{
	std::cout << '\n';
	for (int i = 0; i < n; i++)
		std::cout << v[i] << ' ';
}