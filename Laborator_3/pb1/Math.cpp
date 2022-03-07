#include "Math.h"
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>
int Math :: Add(int x , int y)
{
	return x + y;
}
int Math :: Add(int x, int y, int z)
{
	return x + y + z;
}
int Math :: Add(double x, double y)
{
	return (int)(x + y);
}
int Math :: Add(double x, double y, double z)
{
	return (int)(x + y + z);
}
int Math :: Mul(int x, int y)
{
	return x * y;
}
int Math :: Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math :: Mul(double x, double y)
{
	return (int)(x * y);
}
int Math :: Mul(double x, double y, double z)
{
	return (int)(x * y * z);
}
int Math :: Add(int count, ...)
{
	va_list x;
	va_start(x, count);
	int s=0;
	for (int i = 0; i < count; i++)
		s += va_arg(x, int);
	va_end(x);
	return s;
}
char* Math ::  Add(const char* x, const char* y)
{
	if ((x == nullptr) || (y == nullptr))
		return nullptr;
	int i,sizenou = strlen(x) + strlen(y);
	char* s = (char*)malloc(sizenou + 1);
	for (i = 0; i < strlen(x); i++)
		s[i] = x[i];
	for (i = 0; i < strlen(y); i++)
		s[i + strlen(x)] = y[i];
	s[sizenou] = '\0';
	return s;
}