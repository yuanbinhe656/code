#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;
int main()
{
	map<string,bool> data;
	string s = "lal";
	data.insert(make_pair(s, 1));
	auto itner = data.find(s);
	for (auto &em: data)
	{
		em.second = 0;
	}
		for (auto em: data)
	{
		cout<<em.second;
	}
	return 0;
}
