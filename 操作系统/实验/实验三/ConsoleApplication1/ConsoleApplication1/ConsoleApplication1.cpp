#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
	vector<int> s = { 1,3,4,5 };
	vector<int> w = { 2,4,3,5 };
	auto itr = s.begin();
	itr++;
	list<int> z = { 2,4,3,5 };
	z.remove(*itr);

		for(auto i : z)
		{
			cout << i << endl;
		}
		
	cout << "Hello World";
	return 0;
}