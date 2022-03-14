#include "Sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
Sort::Sort(int n, int mini, int maxi)
{
	size = n;
	v = (int*)malloc((n) * sizeof(int));
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < n; i++)
		v[i]=mini + rand() % (maxi - mini + 1);

}
Sort::Sort()
{
	size = 10;
	v = new int[10]{ 1,10,2,9,3,8,4,7,5,6 };
}
Sort::Sort(int v2[], int n)
{
	size = n;
	v = (int*)malloc((n) * sizeof(int));
	for (int i = 0; i < n; i++)
		v[i] = v2[i];
}
Sort::Sort(int n, ...)
{
	size = n;
	v = (int*)malloc((n) * sizeof(int));
	va_list x;
	va_start(x, n);
	for (int i = 0; i < n; i++)
		v[i] = va_arg(x, int);
	va_end(x);
}
Sort::Sort(char v2[])
{
	char* p;
	int x, j, n = 0, i=0;
	for (j = 0; v2[j]; j++)
		if (v2[j] == ',')
			n++;
	size=n+1;
	v = (int*)malloc((n) * sizeof(int));
	p = strtok(v2, ",");
	while (p)
	{
		for (x = 0, j = 0; p[j]; j++)
			x = x * 10 + p[j] - '0';
		v[i++] = x;
		p = strtok(NULL, ",");
	}
}
void Sort::InsertSort(bool ascendent)
{
	int i, k, j;
	if (ascendent)
	{
		for (i = 1; i < size; i++)
		{
			k = v[i];
			j = i - 1;
			while (j >= 0 && v[j] > k)
			{
				v[j + 1] = v[j];
				j = j - 1;
			}
			v[j + 1] = k;
		}
	}
	else
	{
		for (i = 1; i < size; i++)
		{
			k = v[i];
			j = i - 1;
			while (j >= 0 && v[j] < k)
			{
				v[j + 1] = v[j];
				j = j - 1;
			}
			v[j + 1] = k;
		}
	}
}
int Partitie(int v[], int st, int dr, bool ascendent)
{
	int piv = v[dr];
	int i = st - 1;
	if (ascendent)
	{
		for (int j = st; j < dr; j++)
		{
			if (v[j] < piv)
			{
				i++;
				std::swap(v[i], v[j]);
			}
		}
	}
	else
	{
		for (int j = st; j < dr; j++)
		{
			if (v[j] > piv)
			{
				i++;
				std::swap(v[i], v[j]);
			}
		}
	}
	std::swap(v[i + 1], v[dr]);
	return i + 1;
}
void QuickRecurs(int v[], int st, int dr, bool ascendent)
{
	if (st < dr)
	{
		int piv = Partitie(v, st, dr, ascendent);
		QuickRecurs(v, st, piv - 1, ascendent);
		QuickRecurs(v, piv + 1, dr, ascendent);
	}
}
void Sort::QuickSort(bool ascendent)
{
	QuickRecurs(v, 0, size-1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	int i, j;
	if (ascendent)
	{
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (v[j] > v[j+1])
					std::swap(v[j], v[j+1]);
	}
	else
	{
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (v[j] < v[j+1])
					std::swap(v[j], v[j+1]);
	}

}
void Sort::Print()
{
	for (int i = 0; i < size; i++)
		printf("%d ", v[i]);
	printf("\n");
}
int  Sort::GetElementsCount()
{
	return size;
}
int  Sort::GetElementFromIndex(int index)
{
	if (index >= size)
		return 0;
	return v[index];
}