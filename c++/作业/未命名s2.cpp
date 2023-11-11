#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<string> 
using namespace std;
class st{
	public:
	int s;
	string a;
	st(int as,string ai):s(as),a(ai){
	}
};
int main()
{
	vector<int> nums;
	nums.push_back(NULL);
	string bs,ad="2";
	cin>>bs;
	map<string,int>ads;
	ads.insert(make_pair(ad,1));
	map<string,int> ::iterator itt=ads.find(bs);	
	if(itt==ads.end())
	{
		cout<<"dada"<<endl;
	}
	map<string,st> target,targod; 
	map<string,st> ::iterator sad;
	target.insert(make_pair("he",st(2,"da")));	
	sad=target.begin();
	targod.insert(*sad);
	for(auto em:targod)
	{
		em.second.s=12;
		cout<<"targod"<<endl;
		cout<<em.first<<"   lal"<<em.second.s<<"  "<<em.second.a<<endl;
	}
	for(int i=0;i<10;i++)
	{
		nums.push_back(i);
	}
	for(auto em:nums)
	{
		cout<<em<<endl;
	}
	return 0;
	
}
