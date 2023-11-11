#include <iostream>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
    void pv(vector<int>& nums,int begin, int end)
    {
        int cur = 0;
        while(begin < end)
        {
            cur = nums[begin];
            nums[begin] = nums[end];
            nums[end] = cur;
            end--;
            begin++;
        }
    }
    int findMin(int n) {
        set<int> vist;
        vector<int> per;
        long long z = 1;
        for(int i = 2; i < n; i++)
        {
            if(vist.find(i) == vist.end())
            {
                per.push_back(i);
				cout << i <<",";

            }
                   for (int j = 0; z *i * per[j] <= n; j++)
                {

                    vist.insert(i * per[j] );
                    if(per[j]%i == 0)
                    {
                        break;
                    }
                }
        }
        
        return vist.size();
    }
int main()
{
	string s = "PAYPALISHIRING";
	
	//vector<int>num = {4,5,6,7,0,1,2} ;
	cout << findMin(5000000);
	cout << "s";
	return 0;
}
