#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Student.h"
#include "Globals.h"
using namespace std;
int main()
{
	Student a, b;
	char cuv1[50]="Vlad Adriana", cuv2[50]="Balent Elena";
	a.SetName(cuv1);
	b.SetName(cuv2);
	a.SetMath(10); a.SetEnglish(9); a.SetHistory(7);
	a.GetName(cuv2); //invers (inainte in cuv1, acum in cuv2), pentru a se vedea ca se schimba
	cout << "Media lui " << cuv2 << ": " << a.Average() << '\n';
	b.SetMath(6); b.SetEnglish(9); b.SetHistory(10);
	b.GetName(cuv1);
	cout << "Media lui " << cuv1 << ": " << b.Average() << '\n';
	cout << "Medie mai mare are: ";
	if (CmpAverage(&a,&b) == 1) cout << cuv2;
	if (CmpAverage(&a, &b) == 0) cout << "nimeni, notele sunt egale";
	if (CmpAverage(&a, &b) == -1) cout << cuv1;
	cout << "\nNotele la mate: " << a.GetMath() << ' ' << b.GetMath()<<'\n';
	cout << "Nota mai mare la mate are: ";
	if (CmpMath(&a, &b) == 1) cout << cuv2;
	if (CmpMath(&a, &b) == 0) cout << "nimeni, notele sunt egale";
	if (CmpMath(&a, &b) == -1) cout << cuv1;
	cout << "\nNotele la engleza: " << a.GetEnglish() << ' ' << b.GetEnglish()<<'\n';
	cout << "Nota mai mare la engleza are: ";
	if (CmpEnglish(&a, &b) == 1) cout << cuv2;
	if (CmpEnglish(&a, &b) == 0) cout << "nimeni, notele sunt egale";
	if (CmpEnglish(&a, &b) == -1) cout << cuv1;
	cout << "\nNotele la istorie: " << a.GetHistory() << ' ' << b.GetHistory()<<'\n';
	cout << "Nota mai mare la istorie are: ";
	if (CmpHistory(&a, &b) == 1) cout << cuv2;
	if (CmpHistory(&a, &b) == 0) cout << "nimeni, notele sunt egale";
	if (CmpHistory(&a, &b) == -1) cout << cuv1;
	return 0;
}