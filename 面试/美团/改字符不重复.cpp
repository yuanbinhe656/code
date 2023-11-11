#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int num = 0;
    int a = 1;
    for(int i = 1; i < s.size() - 1; i++)
    {
        a= 1;
        if(s[i] == s[i-1])
        {
            
            while(a == s[i-1] || a == s[i+1] )
            {
                a++;
            }       
            s[i] = a;
            i++;
            num++;                
        }
    }
    if(s.size() == 2)
    {
        if(s[0]== s[1] )
        {
            if(a==s[0])
            {
                a++;
                s[0] = a;
            }
            else
            {
                s[0]=a;
            }
        }
    }
    cout << num;
    return 0;
}
