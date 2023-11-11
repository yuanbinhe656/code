#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <deque>
#include <stack>
#include <list>
using namespace std;

char dismantlingAction(string list) {
        char num[26] ;
        int i = 0,j = 0;
        int flag = 0;
        for(auto itr : list)
        {
            for(; i  < j ; i++)
            {
                if(itr == num[i])
                {
                	char c = itr;
                	char  p = c - 32;
                	cout << p << endl;
                	cout << itr << endl;
                    num[i] = p;
                    break;
                }
                else if(itr == num[i] + 32)
                {
                	
                    break;
                }
                else
                {
                	flag = 1;
				}

                
            }
            if(flag == 1)
            {
                num[j] = itr;
                j++;
                
            }
            flag = 0;
            i = 0;
            
        }
        for(auto itr :  num)
        {
        	cout << itr ;
		}
        for(auto itr : num)
        {
            if(itr >= 'a')
            {
            	
                return itr;
            }
        }
    
        return ' ';
    }
int main()
{
string s = "ccdd";
vector<int> v = {11,9,8,10,6,7};
cout << "out" << endl;

cout << dismantlingAction(s)<< endl;

	return 0;
}


