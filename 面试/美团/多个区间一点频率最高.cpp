#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<set>
#include <iterator>
#include <map>

using namespace std;
	class data{
		public:
			int start;
			int end;
			void setstart(int s)
			{
				start = s;
			}
			void setend(int s)
			{
				end = s;
			}
			
	};
int main()
{

	struct cmpend{
		bool operator() (data a, data b)
	{
			return a.end < b.end;
		}
	};
	struct cmpstart{
		bool operator ()(data a, data b)
		{
			return a.start < b.start;
		}
	};

	int n ,max = 0,t ;
	
	cin >> n;
	data dat[n];
	for(int i = 0 ;i< n;i++)
	{
		cin >>dat[i].start;

		
	}
		for(int i = 0 ;i< n;i++)
	{
		cin >>dat[i].end;

		
		
	}
	int end ;
		std::multiset<data,cmpstart> num1(dat,dat+n);
		std::multiset<data,cmpend> num2(dat,dat+n);
		multiset<data>::iterator it1 = num1.begin();
		multiset<data>::iterator it2 = num2.begin();
		multiset<data>::iterator it3 = num2.begin();
		set<data,cmpstart> result1;

			end = (*it2).end;
			for(;(*it1).start < end ;it1++)
{
			result1.insert((*it1));
			if (max < result1.size() )
			{
				max = result1.size();
			}
}
	it2++;
		for(; it2 != num2.end();it2++)
		{
			end = (*it2).end;
			for(;(*it1).start < end&&it1!=num1.end() ;it1++)
{
			result1.insert(*it1);
}
		result1.erase((*it3));
			if (max < result1.size() )
			{
				max = result1.size();
			}
		
		}

	cout<<max;
	return 0;
}
