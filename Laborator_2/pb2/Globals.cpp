#include "Globals.h"
#include <cstring>
int CmpName(Student* a, Student* b)
{
	char namea[50], nameb[50];
	a->GetName(namea);
	b->GetName(nameb);
	if (strcmp(namea, nameb) > 0) return 1;
	else if (strcmp(namea, nameb) == 0) return 0;
	return -1;
}
int CmpMath(Student* a, Student* b)
{

	if (a->GetMath() > b->GetMath()) return 1;
	else if (a->GetMath() == b->GetMath()) return 0;
	return -1;
}
int CmpEnglish(Student* a, Student* b)
{
	if (a->GetEnglish() > b->GetEnglish()) return 1;
	else if (a->GetEnglish() == b->GetEnglish()) return 0;
	return -1;
}
int CmpHistory(Student* a, Student* b)
{
	if (a->GetHistory() > b->GetHistory()) return 1;
	else if (a->GetHistory() == b->GetHistory()) return 0;
	return -1;
}
int CmpAverage(Student* a, Student* b)
{
	if (a->Average() > b->Average()) return 1;
	else if (a->Average() == b->Average()) return 0;
	return -1;
}