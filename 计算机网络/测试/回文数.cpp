#include<stdio.h>
#include<vector>
#include<math.h>
#include<iostream>
using namespace std;
int huiwen(	long long  m,int k);
int totest(vector<int>n,vector<	long long > num);
int main()
{
	int n,k,m=0;
	cin>>n>>k;
	vector<	long long > arry(n);
	
	for(int i=0;i<n;i++)
	{
		long long ems; 
		cin>>ems;
		arry[i]=ems;
	}
	for(int em:arry)
	{
		if(huiwen(em,k))
		{
			cout<<em<<endl;
			m++;
		}
	}
	if(m==0)
	{
		cout<<"NO Answer\n"<<endl;
	}
	return 0;
}
int huiwen(	long long  m,int k)
{
	int s=m,num=0;
	vector<int> post;
	vector<	long long > nums;
	while(s)
	{
		
		if(s%10==k)
		{
			post.push_back(num);
		}
		nums.push_back(s%10);
		num++;
		s=s/10;	
	}

	if(post.size()<2)
	{
		return 0;
	}
	else 
	{
		if(totest(post,nums))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int totest(vector<int>n,vector<	long long > num)
{
	for(int i=0;i<n.size();i++)
	{
		for(int j=i+1;j<n.size();j++)
		{
			int post1=n[i],post2=n[j];
			while(post2-post1>0)
			{
				if(num[post1]==num[post2])
				{
					post1++;
					post2--;
				}
				else 
				{
					break;
				}
			}
			if(post2-post1<1)
			{
				return 1;
			}

		}
	}
	return 0;
}
