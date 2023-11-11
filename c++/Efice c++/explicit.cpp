#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	class A{

		public:
			int s;
			 A(int n=0)
		{
			s=n;
		} 
	};
	float ad=9;
	char s='a';
	A sa(s);
	A da=10;

	cout<<da.s<<endl;
	cout<<sa.s<<endl;
	return 0;
}
