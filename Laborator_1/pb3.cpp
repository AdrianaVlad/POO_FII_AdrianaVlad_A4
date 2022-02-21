#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <char> cuv[105];
bool cmp(vector <char> a, vector <char> b)
{
	if (a.size() != b.size())
		return a.size() > b.size();
	return a > b;
}
int main()
{
	char prop[105];
	int i,j;
	scanf("%[^\n]", prop);
	char* p;
	p = strtok(prop, " ");
	for(i=0;p;i++)
	{
		for (j = 0; *(p + j); j++)
			cuv[i].push_back (*(p + j));
		cuv[i].push_back('\0');
		p = strtok(NULL, " ");
	}
	sort(begin(cuv), begin(cuv)+i, cmp);
	for (j = 0; j < i; j++)
	{
		p = &cuv[j][0];
		printf("%s\n", p);
	}
	return 0;
}