#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
	float rid(vector<float> s)
	{
		if(s.size()==1)
		{
			return s[0];
		}
		else {
			vector<float> v(s.begin(),s.end()-1);
			float tp=rid(v);
			cout<<"���η��ص�Ϊ��"<<tp<<endl;
			if (*(s.end()-1)<=tp)
			
				return *(s.end()-1);
			else 
				return tp;
		}
	}
int main()
{

	vector<float> s={3,2,5,6,9,4,2,1,3,4};

		cout<<"���н��Ϊ"<<rid(s)<<endl;
	return 0;
}
