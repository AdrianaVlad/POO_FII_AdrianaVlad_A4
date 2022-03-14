
#include "Sort.h"
#include <iostream>
using namespace std;
int aux[] = { 1,7,2,6,3,5,4 };
char cuv[] = "10,40,100,5,70";
int main()
{
	Sort a(10, 30, 70); a.Print();
	Sort b; b.Print();
	Sort c(aux, 7); c.Print();
	Sort d(5, 8, 7, 6, 5, 4); d.Print();
	Sort e(cuv); e.Print();
	printf("%d\n",d.GetElementsCount());
	printf("%d\n",d.GetElementFromIndex(3));
	a.InsertSort(1); a.Print();
	b.BubbleSort(0); b.Print();
	c.QuickSort(1); c.Print();
	return 0;
}