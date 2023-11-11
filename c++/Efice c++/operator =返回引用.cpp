#include<stdio.h>
#include<iostream>

using namespace std;
class A{
	public:
		A(int x):b(x)
			{
				
			}
		int a()
		{
			return b;
		}
	int  operator =(A x)
	{
		b=x.b;
		return 0;
	}
	private:
		int b;
};
int main()
{
	A c(5);
	A d(6);
	A e(7);
	cout<<"c.a:"<<c.a()<<endl;
	cout<<"d.a:"<<d.a()<<endl;
	cout<<"e.a:"<<e.a()<<endl;
	c=d;
	cout<<"c.a:"<<c.a()<<endl;
	cout<<"d.a:"<<d.a()<<endl;
	cout<<"e.a:"<<e.a()<<endl;
	c=d=e;
		cout<<"c.a:"<<c.a()<<endl;
	cout<<"d.a:"<<d.a()<<endl;
	cout<<"e.a:"<<e.a()<<endl;
	e=e;
	cout<<"c.a:"<<c.a()<<endl;
	cout<<"d.a:"<<d.a()<<endl;
	cout<<"e.a:"<<e.a()<<endl;
	return 0;
	
 } 
