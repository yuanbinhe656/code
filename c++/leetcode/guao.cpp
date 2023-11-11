#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include<iostream>
using namespace std;
    int maxProfit(vector<int>& prices) {
               int number = prices.size();
        int m,n;
        int data[number][3];
        int max=prices[0],min=prices[0];
        data[0][0]=data[number-1][1]=0;
        for(int i = 1;i < prices.size();i++)
        {
            if(prices[i]<min)
            {
                
                data[i][0] = max - min;
                min=max = prices[i];

            } else if(prices[i] > max)
            {
                max = prices[i];
                data[i][0] = max -min;

            }
            else{
                data[i][0]=max -min;
            }

            
        }
           m=max=prices[number-1],min=prices[number-1];
                   data[number-1][2]=data[number-1][0]+data[number-1][1];
                   //		vector<int> prices ={4,7,2,1,11};
        for(int i = number -2;i > -1;i --)
        {
            if(prices[i] < min)
            {
                min =prices[i];
                max = m;
                 data[i][1] = max - min;
                 data[i][2]=data[i][0]+data[i][1];
            }
            else if(prices[i]> m)
            {
                m = prices[i];
                data[i][1] = max - min;
                 data[i][2]=data[i][0]+data[i][1];
            }
            else{
            	if(m- prices[i] >max - min)
            	{
				max = m;
            	min = prices[i];
                data[i][1] = max - min;
               
                 data[i][2]=data[i][0]+data[i][1];
             }
             else{
             	  data[i][1] = max - min;
                
                 data[i][2]=data[i][0]+data[i][1];
			 }
            }
        }
        int pr = data[number-1][2];
        for(int i = number -2;i > -1;i --)
        {
            if(data[i][2]>pr)
            {
                pr = data[i][2];
            }
            cout<<"0:"<<data[i][0]<<" 1:"<<data[i][1] <<" 2:"<<data[i][2]<<endl;
        }
        return pr;
    }
int main()
{
	vector<int> prices ={4,7,2,1,11};
	vector<int> pricess ={3,3,5,0,0,3,1,4};
	int m =maxProfit(prices);
	cout<<m;
	int x=NULL;
	if(x == NULL)
	{
		x = 0;
		cout<<"x:"<<x<<endl;
	}
	return 0;
}
