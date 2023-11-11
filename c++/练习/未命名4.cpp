#include<iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	string ret = "cout  ";
	while(cin >> s)
	{
		if(s == "-1")
		{
			break;
		}
		ret = ret + "<< \" " + s + " : \" <<" + s ;
	}
	ret = ret + "<< endl;";
	cout << ret;
	return 0;
}
