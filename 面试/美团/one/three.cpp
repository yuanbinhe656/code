#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int num, m, q;

	set<int> max;
	vector<int> ws;
	//	vector<int> cours(num, 0);
	vector<map<int, int>> v(7, map<int, int>());
	vector<vector<int>> w(7, vector<int>());


	for (int i = 0; i < 7; i++)
	{
		cin >> num;
		while (num)
		{
			cin >> m;
			v[i].insert(make_pair(m, 1));
			num--;
		}

	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (v[i][j])
			{
				w[i].push_back(j);
			}
		}
	}
	map<int, int> result;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < w[i].size(); j++)
		{
			auto itr = result.find(w[i][j]);
			if (itr != result.end())
			{
				itr->second++;
			}
			else
			{
				result.insert(make_pair(w[i][j], 1));
			}
		}
	}


	return 0;
}