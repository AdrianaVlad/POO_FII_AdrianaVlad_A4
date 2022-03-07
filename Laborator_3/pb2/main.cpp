#include <iostream>
#include <stdlib.h>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas c(150,100);
	c.DrawCircle(50, 75, 10, '*');
	c.Print();
	c.FillCircle(50, 75, 10, '*');
	c.Print();
	c.DrawRect(10, 10, 90, 90, '*');
	c.Print();
	c.FillRect(10, 10, 90, 90, '*');
	c.Print();
	c.SetPoint(50, 75, '*');
	c.Print();
	c.DrawLine(10, 10, 90, 90, '*');
	c.Print();
	c.Clear();
	return 0;
}