#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");
struct compare
{
	bool operator() (pair<string, int> p1, pair<string, int> p2)
	{
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return false;
		return true;
	}
};
int main()
{
	string s;
	map<string, int> M;
	getline(fin, s);
	size_t prev=0,p;
	while ((p = s.find_first_of(" ,?!.",prev)) != string::npos)
	{
		if (p > prev)
		{
			string s1(s.substr(prev, p - prev));
			string str1(s1.length(), ' ');
			transform(s1.begin(), s1.end(), str1.begin(), tolower);
			if (M.count(str1))
				M[str1] += 1;
			else
				M[str1] = 1;
		}
		prev = p + 1;
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, compare> Q;
	for (auto i = M.begin(); i != M.end(); i++)
		Q.push(pair<string, int>(i->first, i->second));
	while (!Q.empty())
	{
		fout << Q.top().first << ' ' << Q.top().second<<'\n';
		Q.pop();
	}
	return 0;
}