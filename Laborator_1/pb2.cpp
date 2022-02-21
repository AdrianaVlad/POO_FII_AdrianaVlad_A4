#include <iostream>
#include <cstring>
using namespace std;
int convert_to_nr(char cuv[])
{
	int l = strlen(cuv), x=0;
	for (int i = 0; i < l; i++)
		x = x * 10 + cuv[i] - '0';
	return x;
}
int main()
{
	FILE* fin;
	if (fopen_s(&fin, "in.txt", "r") != 0)
	{
		printf("Eroare! Fisierul nu a putut fi deschis.\n");
	}
	else
	{
		printf("Fisierul a fost deschis cu succes.\n");
		char cuv[105];
		int x, s=0;
		while (fgets(cuv, 100, fin))
		{
			cuv[strlen(cuv) - 1] = '\0';
			x=convert_to_nr(cuv);
			s += x;
		}
		printf("Suma numerelor citite: %d\n", s);
	}
	system("pause");
	return 0;
}