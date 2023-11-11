#include<stdio.h>
#include<string>
#include<iterator>
#include<iostream>
using namespace std;
int main()
{
	string s,res="";
	char ch;
	int num=1;
	string ::iterator j;
	cin>>s;
	if(s[0]>=9)
	{
		cout<<"haha"<<endl;
	}
	while (1)
	{
		cin>>s;
		j=s.begin();
		for(string ::iterator i=j;i!=s.end();i++)
		{
			cout<<*i;
			
			if(*i==' ')
			{
				res.append(j,i-1);
				j=i+1;
			}

		}

		cout<<res;
		res="";
	}
	return 0;
}
