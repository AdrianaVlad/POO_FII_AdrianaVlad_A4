#pragma once
#include "Elem.h"
#include "Iterator.h"
template <typename T1, typename T2>
class Map : public Elem<T1,T2>
{
	int n = 0,x;
	Elem<T1,T2> v[100];
public:
	Elem<T1,T2>& operator [] (T1 i)
	{
		v[n++].key = i;
		return v[n-1];
	}
	Iterator<T1,T2> begin()
	{
		Iterator<T1,T2> it;
		for (int i = 0; i < n; i++)
		{
			it.v[i] = v[i];
		}
		x = 0;
		it.i=&x;
		return it;
	}
	Iterator<T1,T2> end()
	{
		Iterator<T1,T2> it;
		it.i = &n;
		return it;
	}
};

