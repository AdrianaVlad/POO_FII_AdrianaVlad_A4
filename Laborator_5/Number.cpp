#include "Number.h"
#include <cstring>
#include <iostream>
Number::Number(const char* value, int base)
{
	baza = base;
	val = new char[strlen(value)+1];
	memcpy(val, value, strlen(value) + 1);
}
Number::Number(int n)
{
	int i, p;
	baza = 10;
	for (i = 0, p = 1; p <= n; i++, p *= 10);
	val = new char[i+1];
	val[i] = '\0';
	for (--i; i>=0; i--)
	{
		val[i] = n % 10+'0';
		n /= 10;
	}
}
Number::Number(const char* n)
{
	baza = 10;
	val = new char[strlen(n) + 1];
	memcpy(val, n, strlen(n) + 1);
}
Number::~Number()
{
	delete this->val;
	this->val = nullptr;
	baza = 0;
}
Number::Number(const Number& n)
{
	val=nullptr;
	val = new char[strlen(n.val) + 1];
	memcpy(val, n.val, strlen(n.val) + 1);
	baza = n.baza;
}
Number::Number(Number && n)
{
	val=nullptr;
	val = new char[strlen(n.val) + 1];
	memcpy(val, n.val, strlen(n.val) + 1);
	baza = n.baza;
	delete n.val;
	n.val = nullptr;
	n.baza = 0;
}
bool Number::operator=(const Number& n)
{
	delete val;
	val = new char[strlen(n.val) + 1];
	memcpy(val, n.val, strlen(n.val) + 1);
	baza = n.baza;
	return true;
}
bool Number::operator=(int n)
{
	int i, p, b=baza;
	baza = 10;
	for (i = 0, p = 1; p <= n; i++, p *= 10);
	delete val;
	val = new char[i + 1];
	val[i] = '\0';
	for (--i; i>=0; i--)
	{
		val[i] = n % 10 + '0';
		n /= 10;
	}
	this->SwitchBase(b);
	return true;
}
bool Number::operator=(const char* n)
{
	int b=baza;
	baza = 10;
	delete val;
	val = new char[strlen(n) + 1];
	memcpy(val, n, strlen(n) + 1);
	this->SwitchBase(b);
	return true;
}
Number operator+(const Number& a, const Number& b)
{
	Number c = a, d = b;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1=0,aux2=0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i]-'0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i]-'0';
	aux1 += aux2;
	c = aux1;
	if (a.baza > b.baza)
		c.SwitchBase(a.baza);
	else
		c.SwitchBase(b.baza);
	return c;
}
Number operator-(const Number& a, const Number& b)
{
	Number c = a, d = b;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1 = 0, aux2 = 0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i] - '0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i] - '0';
	aux1 -= aux2;
	c = aux1;
	if (a.baza > b.baza)
		c.SwitchBase(a.baza);
	else
		c.SwitchBase(b.baza);
	return c;
}
bool Number::operator+=(const Number& n)
{
	Number c(this->val, this->baza), d=n;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1 = 0, aux2 = 0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i] - '0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i] - '0';
	aux1 += aux2;
	c = aux1;
	if (this->baza > n.baza)
		c.SwitchBase(this->baza);
	else
		c.SwitchBase(n.baza);
	this->baza = c.baza;
	delete this->val;
	val = new char[strlen(c.val) + 1];
	memcpy(val, c.val, strlen(c.val) + 1);
	return true;
}
bool Number::operator-=(const Number& n)
{
	Number c(this->val, this->baza), d = n;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1 = 0, aux2 = 0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i] - '0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i] - '0';
	aux1 -= aux2;
	c = aux1;
	if (this->baza > n.baza)
		c.SwitchBase(this->baza);
	else
		c.SwitchBase(n.baza);
	this->baza = c.baza;
	delete this->val;
	val = new char[strlen(c.val) + 1];
	memcpy(val, c.val, strlen(c.val) + 1);
	return true;
}
void Number::operator--()//prefix
{
	for (int i = 0; val[i]; i++)
		val[i] = val[i + 1];
}
void Number::operator--(int n)//postfix
{
	val[strlen(val) - 1] = '\0';
}
char Number::operator[](int i)
{
	return val[i];
}
bool Number::operator>(Number n)
{
	Number c(this->val, this->baza), d = n;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1 = 0, aux2 = 0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i] - '0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i] - '0';
	if (aux1 > aux2)
		return true;
	else
		return false;
}
bool Number::operator<(Number n)
{
	Number c(this->val, this->baza), d = n;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1 = 0, aux2 = 0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i] - '0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i] - '0';
	if (aux1 < aux2)
		return true;
	else
		return false;
}
bool Number::operator>=(Number n)
{
	Number c(this->val, this->baza), d = n;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1 = 0, aux2 = 0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i] - '0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i] - '0';
	if (aux1 >= aux2)
		return true;
	else
		return false;
}
bool Number::operator<=(Number n)
{
	Number c(this->val, this->baza), d = n;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1 = 0, aux2 = 0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i] - '0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i] - '0';
	if (aux1 <= aux2)
		return true;
	else
		return false;
}
bool Number::operator==(Number n)
{
	Number c(this->val, this->baza), d = n;
	int i;
	c.SwitchBase(10); // c=a in baza 10
	d.SwitchBase(10); // d=b in baza 10
	int aux1 = 0, aux2 = 0;
	for (i = 0; c.val[i]; i++)
		aux1 = 10 * aux1 + c.val[i] - '0';
	for (i = 0; d.val[i]; i++)
		aux2 = 10 * aux2 + d.val[i] - '0';
	if (aux1 == aux2)
		return true;
	else
		return false;
}
void Number::SwitchBase(int newBase)
{
	int i,x=0,r;
	for (i = 0; val[i]; i++)
	{
		if (val[i] > '9')
			x = x * baza + (val[i] - 'A' + 10);
		else
			x = x * baza + (val[i] - '0');
	}
	//x=val in baza 10
	char* aux = new char [1000];
	for(i=0;x;i++)
	{
		r = (x % newBase);
		if (r > 9)
			aux[i] = r - 10 + 'A';
		else
			aux[i] = r + '0';
		x /= newBase;
	}
	aux[i] = '\0';
	delete val;
	val = new char[strlen(aux) + 1];
	for (i = 0; aux[i]; i++)
		val[strlen(aux) - i - 1] = aux[i];
	val[strlen(aux)] = '\0';
	baza = newBase;
}
void Number::Print()
{
	printf("%s\n", val);
}
int  Number::GetDigitsCount()
{
	return strlen(val);
}
int  Number::GetBase()
{
	return baza;
}