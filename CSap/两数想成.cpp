#include<stdio.h>
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    string s;
   while(1)
   {
   	cin>>s;
   	         unordered_map<char,int> windos;
        
       int  begin=0,end=0,max=0;
        int sa=0;
        for(auto em:s)
        {
           
            if(windos.find(em)==windos.end())
            {
                    windos[em]=end;
                    end++;
            }
            else 
            {
                
                if(max < end-begin)
                {
                    max=end-begin;
                }
                sa=begin;
                
                begin=windos[em]+1;
                for(;sa<begin;sa++)
                {
                    windos.erase(s[sa]);
                }
                windos[em]=end;
                end++;
            }
           
        }
                        if(max < end-begin)
                {
                    max=end-begin;
                }
                 cout<<max; 
             
    }
               
   
                return 0;
                
    }
	

