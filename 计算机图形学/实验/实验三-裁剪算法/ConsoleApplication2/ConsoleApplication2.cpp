#include<stdio.h>
#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> heights = { 2,2 };
    auto maxitr = max_element(heights.begin(), heights.end());
    int max = *maxitr;

 
    vector<int> v(heights.size());
    vector<int> w(heights.size(),0);
    int data;
    int result = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int j = i;
        int s = i;
        data = 0;
        while (j < heights.size() && heights[j] >= 1)
        {
            data++;
        
            j++;
        }
        while (i < j)
        {
            v[i] = data;
            w[i] = s;
            i++;

        }
        if (data > result)
        {
            result = data;
        }
    }
    //        for(int i = 0 ;i< heights.size();i++)
    //		{
    //			cout << w[i][0]<<endl;
    //		 } 

    for (int j = 1; j < max; j++)
    {
        for (int i = 0; i < heights.size() ; i++)
        {
            data = 0;
            int z = i;
            int s = i;
            while (z < v[i] / j + w[i] && heights[z] >= j + 1)
            {
                
                data++;
                z++;

            }

            while (i < z)
            {
                w[i] = s;
                v[i] = data * (j + 1);
                i++;

            }

            if (data * (j + 1) > result)
            {
                result = data * (j + 1);

            }
        }
    }

    return result;
}