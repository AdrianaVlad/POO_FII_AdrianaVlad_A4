#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "MyVector.h"
using namespace std;
ifstream fin("in.txt");
int main()
{
	//PB1
	
	int i;
	vector <string> vs;
	string cuv[5] = { "jaoisnda","ajsiudhb","fgdmsoi","nhbd","aio" };
	for (i = 0; i < 5; i++)
	{
		vs.push_back(cuv[i]);
	}
	sort(vs.begin(), vs.end(), [](string a, string b) {return a.length() != b.length() ? a.length() < b.length() : a < b; });
	for (i = 0; i < 5; i++)
	{
		cout << vs[i]<<'\n';
	}

	//PB2

	int v[] = { 123,44,2,1,67,5,213,182,233,0 };
	auto maxint = [](int v[]) {int maxi=v[0]; for (int i = 1; v[i]; i++) maxi = max(maxi, v[i]); return maxi; };
	int maxi = maxint(v);
	cout << '\n' << maxi << '\n';

	//PB3

	auto f1 = [](int x) { return x * 2; };
	auto f2 = [](int x) { return (x >= 10); };
	MyVector myv;
	myv.Add(1);
	myv.Add(2);
	myv.Add(5);
	myv.Add(4);
	myv.Add(6);
	myv.Add(3);
	myv.Delete(5);
	myv.Iterate(f1);
	myv.Filter(f2);
	myv.Afisare();
	return 0;
}