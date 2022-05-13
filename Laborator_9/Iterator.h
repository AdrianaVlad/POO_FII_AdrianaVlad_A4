#pragma once
#include "Elem.h"
template <typename T1, typename T2>
struct Returnat {
	T1 key;
	T2 value;
	int i;
};

template <typename T1, typename T2>
class Iterator
{
public:
	Elem<T1, T2> v[100];
	int *i;
	Iterator& operator++()
	{
		(*i)++;
		return *this;
	}
	bool operator != (Iterator& it)
	{
		return (*it.i) != (*i);
	}
	Returnat<T1, T2> operator * ()
	{
		Returnat<T1, T2> r;
		r.key = v[(*i)].key;
		r.value = v[(*i)].value;
		r.i = *i;
		return r;
	}
};

