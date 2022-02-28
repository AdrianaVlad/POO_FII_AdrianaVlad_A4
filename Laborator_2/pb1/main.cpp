#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList v;
	v.Init();
	v.Add(13);
	v.Add(7);
	v.Add(10);
	v.Add(50);
	v.Sort();
	v.Print();
	for (int i = 1; v.Add(i); i++);
	v.Print();
	v.Sort();
	v.Print();
	return 0;
}