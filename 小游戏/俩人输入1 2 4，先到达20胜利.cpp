#include<stdio.h>
#include<iostream>
using namespace std;
void show();
void play(int &s);
int main()
{
	show();
	int s=0;
	while(1)
	{
		play(s);
		if(s>=20)
		{
			break;
		}
	}
	return 0;
 } 
 void show()
 {
 	cout<<"----------------------------------------------------------------------------"<<endl;
 	cout<<"------玩法规则：每人可选择加1,2,4从零开始，轮流进行，谁先相加到20谁赢-------"<<endl;

 }
 void play(int &s)
 {
 	int a;
 	cout<<"目前相加值为:"<<s<<endl; 
 	cout<<"玩家一输入："<<endl; 
 	while(1)
 	{
 	cin>>a;
 	if(a==1||a==2||a==4)
 	{
 		s+=a;
		 if(s==20)
		 {
		 	cout<<"恭喜您胜利"<<endl;
			 return ; 
			 }	
		else if(s>20)
		{
			cout<<"超过20，游戏结束，打成平手"<<endl;
			return ; 
		}
		else
		{
			 		cout<<"相加结果为："<<s<<endl;
			 		break; 
		 } 

	 }
	 else 
	 {
	 	cout<<"输入错误。请重新输入"<<endl; 
	 }		
	 }
 
 	
 	cout<<"目前相加值为:"<<s<<endl;  	
 	cout<<"玩家二输入："<<endl;
	while(1)
 	{
 	cin>>a;
 	if(a==1||a==2||a==4)
 	{
 		s+=a;
		 if(s==20)
		 {
		 	cout<<"恭喜您胜利"<<endl;
			 return ; 
			 }	
		else if(s>20)
		{
			cout<<"超过20，游戏结束，打成平手"<<endl;
			return ; 
		}
		else
		{
			 		cout<<"相加结果为："<<s<<endl;
			 		break; 
		 } 

	 }
	 else 
	 {
	 	cout<<"输入错误。请重新输入"<<endl; 
	 }		
	 }
 }
