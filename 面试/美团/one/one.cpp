
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
	cin >> num >> m;

	set<int> max;
	vector<int> ws;
	//vector<int,> data;
	//vector<map<int, int>> v(7, map<int, int>());
	vector<vector<int>> w(num, vector<int>(2));
	for (int i = 0; i < num; i++)
	{
		cin >> q;
		w[i][0] = q;
		w[i][1] = i;
	}

	int s = 0;
	w[s][0] = w[s][0] - 1;

	if (w[s][0] == 0)
	{
		
		cout << w[s][1] + 1 << endl;
		auto itr = w.begin() + s;
		w.erase(itr);
	}
	s = m -1 ;
	while (w.size() != 0)
	{
		
		w[s][0] = w[s][0] -1 ;
	
		s = (s + m) % w.size();
		if (w[s][0] == 0)
		{
			
			cout << w[s][1]+1 << endl;
			auto itr = w.begin() + s;
			w.erase(itr);
			if (w.size()== 0)
			{
				break;
			}
			else {
				s = (s + m - 1) % w.size();
			}
		}
		


	}

	return 0;
}