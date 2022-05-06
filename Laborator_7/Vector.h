#pragma once
#include <algorithm>
#include <stdlib.h>
template <class T>
class Vector
{
	int n;
	int nmax;
	T* v;
public:
	Vector()
	{
		v = (T*)(malloc(sizeof(T)));
		nmax = 1;
	}
	~Vector()
	{
		free(v);
		n = nmax = 0;
	}
	bool push(T x)
	{
		if (n == nmax);
		{
			nmax = 2*n;
			v = (T*)(v, realloc(nmax*sizeof(T)));
			n++;
			v[n - 1] = x;
		}
	}
	T pop()
	{
		if (n)
		{
			n--;
			return v[n];
		}
	}
	bool remove(int i)
	{
		for (int j = i; (j+1)<n; j++)
			v[j] = v[j + 1];
		n--;
	}
	bool insert(T x, int i)
	{
		if (n == nmax)
		{
			nmax = 2 * n;
			v = (T*)(v, realloc(nmax * sizeof(T)));
			n++;
		}
		for (int j = n-1; (j-1) >= i; j--)
			v[j] = v[j - 1];
		v[i] = x;
	}
	void sort(bool *(callback)(T, T))
	{
		int i, j;
		for(i=0;i<n;i++)
			for(j=i+1;j,n;j++)
				if ((callback && callback(v[i], v[j]))|| (!(callback) && v[i] < v[j]))
					swap(v[i], v[j]);
	}
	const T& get(int i)
	{
		if(i<n)
			return v[i];
	}
	bool set(T x, int i)
	{
		if (i < n)
		{
			v[i] = x;
			return 1;
		}
		return 0;
	}
	int count()
	{
		return n;
	}
	int firstIndexOf(T x, bool* (callback)(T, T))
	{
		for (int i = 0; i < n; i++)
			if ((callback && callback(v[i], x)) || (!(callback) && v[i] == x))
				return i;
	}
};

