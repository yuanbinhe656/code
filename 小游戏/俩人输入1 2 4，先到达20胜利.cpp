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
 	cout<<"------�淨����ÿ�˿�ѡ���1,2,4���㿪ʼ���������У�˭����ӵ�20˭Ӯ-------"<<endl;

 }
 void play(int &s)
 {
 	int a;
 	cout<<"Ŀǰ���ֵΪ:"<<s<<endl; 
 	cout<<"���һ���룺"<<endl; 
 	while(1)
 	{
 	cin>>a;
 	if(a==1||a==2||a==4)
 	{
 		s+=a;
		 if(s==20)
		 {
		 	cout<<"��ϲ��ʤ��"<<endl;
			 return ; 
			 }	
		else if(s>20)
		{
			cout<<"����20����Ϸ���������ƽ��"<<endl;
			return ; 
		}
		else
		{
			 		cout<<"��ӽ��Ϊ��"<<s<<endl;
			 		break; 
		 } 

	 }
	 else 
	 {
	 	cout<<"�����������������"<<endl; 
	 }		
	 }
 
 	
 	cout<<"Ŀǰ���ֵΪ:"<<s<<endl;  	
 	cout<<"��Ҷ����룺"<<endl;
	while(1)
 	{
 	cin>>a;
 	if(a==1||a==2||a==4)
 	{
 		s+=a;
		 if(s==20)
		 {
		 	cout<<"��ϲ��ʤ��"<<endl;
			 return ; 
			 }	
		else if(s>20)
		{
			cout<<"����20����Ϸ���������ƽ��"<<endl;
			return ; 
		}
		else
		{
			 		cout<<"��ӽ��Ϊ��"<<s<<endl;
			 		break; 
		 } 

	 }
	 else 
	 {
	 	cout<<"�����������������"<<endl; 
	 }		
	 }
 }
