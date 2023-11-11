#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{

		cout<<"文件解码后为："<<endl;

			    ifstream osa;  
			
    osa.open("E:\\my\\in.txt",ios::in);
	string len;
		string sta="";
	while(getline(osa,len))
	{
		sta+=len;
		len="\n";
	}
    cout<<"std:"<<sta<<endl;
}
