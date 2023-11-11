#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<iostream> 
using namespace std;
int main()
{
	vector<int> num;
	int a,s=0;
	cout<<"请输入数据"<<endl;
	cout<<"按下回车结束输入"<<endl; 
	cin>>a;
	while(cin.get()!='\n')
	{
		num.push_back(a);
		cin>>a;
	}
	if(num.size()!=0)
	{
		a=0;
		for(auto em:num)
		{
			a+=em;
		}
		a=a/num.size();
		for(auto em:num)
		{
			s=s+pow((em-a),2);
		}
		s=s/num.size();
		cout<<"s^2=="<<s<<endl;
	}
	return 0; 
 } 
