#pragma once
class Student
{
	char name[50];
	int math, english, history;
public:
	bool SetName(char cuv[]);
	void GetName(char cuv[]);
	bool SetMath(int x);
	int GetMath();
	bool SetEnglish(int x);
	int GetEnglish();
	bool SetHistory(int x);
	int GetHistory();
	float Average();
};

