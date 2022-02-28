#include "Student.h"
#include <cstring>
bool Student::SetName(char cuv[])
{
	if (strlen(cuv) < 50)
	{
		strcpy_s(this->name, cuv);
		return 1;
	}
	return 0;
}
void Student::GetName(char cuv[])
{
	int i;
	for (i = 0; this->name[i]; i++)
		cuv[i] = this->name[i];
	cuv[i] = '\0';
}
bool Student::SetMath(int x)
{
	if (x >= 1 && x <= 10)
	{
		this->math = x;
		return 1;
	}
	return 0;
}
int Student::GetMath()
{
	return this->math;
}
bool Student::SetEnglish(int x)
{
	if (x >= 1 && x <= 10)
	{
		this->english = x;
		return 1;
	}
	return 0;
}
int Student::GetEnglish()
{
	return this->english;
}
bool Student::SetHistory(int x)
{
	if (x >= 1 && x <= 10)
	{
		this->history = x;
		return 1;
	}
	return 0;
}
int Student::GetHistory()
{
	return this->history;
}
float Student::Average()
{
	return ((float)(this->math + this->english + this->history) / 3);
}