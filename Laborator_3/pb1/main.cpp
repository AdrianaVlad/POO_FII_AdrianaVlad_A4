#include <iostream>
#include <stdlib.h>
#include "Math.h"
using namespace std;
int main()
{
	Math m;
	printf("%d\n", m.Add(2, 3));
	printf("%d\n", m.Add(2, 3, 4));
	printf("%d\n", m.Add(2.5, 3.5));
	printf("%d\n", m.Add(2.5, 3.5, 4.5));
	printf("%d\n", m.Mul(2, 3));
	printf("%d\n", m.Mul(2, 3, 4));
	printf("%d\n", m.Mul(2.5, 3.5));
	printf("%d\n", m.Mul(2.5, 3.5, 4.5));
	printf("%d\n", m.Add(5,1,2,3,4,5));
	printf("%s\n", m.Add("abcd","efg"));
	system("pause");
	return 0;
}