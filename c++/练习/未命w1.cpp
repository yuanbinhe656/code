#include<iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> data = {1,2,4,7,10,13,15};
	int cnt = 7;
	int flag = 0;
	for(int i = 16; ;i++)
	{
		for(auto itr = data.begin();itr !=data.end(); itr++)
		{
			for(auto itv = data.rend();itv != data.rbegin();itv--)
			{
				if(*itr + *itv == i)
				{
					flag = 1;
					
					break;
					
				}
			}
			if(flag == 1)
			{
				break;
			}
		}
		if(flag == 0)
		{
			data.push_back(i);
			cnt++;
		}
		flag = 0;
		if(cnt > 26)
		{
			break;
		}
		
	}
//	for(auto itr : data)
//	{
//		cout << itr << ",";
//		
//	}
        int datas[] = {1,2,4,7,10,13,15,18,21,24,27,32,35,38,41,44,49,52,55,58,61,66,69,72,75,78,83};
        string s = "has";
        string m = "him";
        int sum = 0;
        for(auto it : s)
        {
        	int  i = it - 'a';
        	cout << data[i] << endl;
        	sum = sum + datas[i];
        	
		}
		cout << sum << endl;
		sum = 0;
		for(auto it : m)
        {
        	int  i = it - 'a';
        	cout << data[i] << endl;
        	sum = sum + datas[i];
        	
		}
		cout << sum << endl;
	
}
