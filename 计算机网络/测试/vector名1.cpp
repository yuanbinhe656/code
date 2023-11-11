#include<stdio.h>
#include<vector>
#include <algorithm>
#include<iostream>
using namespace std;
	struct fangcheng{
		int n;
		int s;
	};
	bool myfunction2 (fangcheng i,fangcheng j) { return (i.s>j.s); }
	bool myfunction1 (fangcheng i,fangcheng j) { return (i.s=j.s); }
	vector <fangcheng> forme(vector <fangcheng> s);
int main()
{
	vector<fangcheng> s,t,z,y,w;
		vector<fangcheng>::iterator it1,it2,it3;
	fangcheng f;
	int n;
	if(cin>>n)
	{
	
	for(int i=0;i<n;i++)
	{
				cin>>f.n;
		cin>>f.s;
		s.push_back(f);

	}}

	
	if(cin>>n)
	{
	
	for(int i=0;i<n;i++)
	{
				cin>>f.n;
		cin>>f.s;
		t.push_back(f);

	}}

	it1=s.begin();

	
	while(it1!=s.end())
	{
			it2=t.begin();
		while(it2!=t.end())
		{
			f.n=(*it1).n*(*it2).n;
			f.s=(*it1).s+(*it2).s;
			z.push_back(f);

			it2++;
		}

		it1++;


	}
	
	std::sort(z.begin(),z.end(),myfunction2);
	y=forme(z);

	it3=y.begin();
	while(it3!=y.end())
	{
		if(it3==y.end()-1)
		{
				cout<<(*it3).n<<" "<<(*it3).s<<endl;
				it3++;
		}
		else
		{
					cout<<(*it3).n<<" "<<(*it3).s<<" ";
		it3++;
		}

	}
	z=s;
	z.insert(z.end(),t.begin(),t.end());
	
	std::sort(z.begin(),z.end(),myfunction2);
	it3=z.begin();

	w=forme(z);
	it3=w.begin();
	while(it3!=w.end())
	{
		if(it3==w.end()-1)
		{
				cout<<(*it3).n<<" "<<(*it3).s<<endl;
				it3++;
		}
		else
		{
					cout<<(*it3).n<<" "<<(*it3).s<<" ";
		it3++;
		}

	}
	return 0;
	
}
vector <fangcheng> forme(vector <fangcheng> s)
{
	vector <fangcheng> t;
	vector<fangcheng>::iterator it1,it2,it3;
	it3=s.begin();
	if(s.begin()==s.end())
	{
		return s;
	}
	else 
	{
	t.push_back(*it3++);
	while(it3!=s.end())
	{
		it2=t.end()-1;
		if((*it3).s==(*it2).s)
		{
			(*it2).n+=(*it3++).n;
		}
		else 
		{
			if((*it2).n==0&(*it2).s!=0)
			{
				
				t.pop_back();
			it2=t.end()-1;
			}
			t.push_back(*it3++);
		}
	}
	}
	return t;
}



