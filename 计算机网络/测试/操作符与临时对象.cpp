#include<stdio.h>
#include<iostream>
using namespace std;
class complex{
	public:
		cpmplex (double i=0,double j=0){
			re=i;
			im=j;
		}
		double real()const
		{
			return this->re;
		}
		double imag()const
		{
			return this->im;
		}
		inline complex&
		_doapl(const complex&r)
		{
			this->re+=r.re;
			this->im+=r.im;
			return *this;
		}
	private:
		double re;
		double im;
};
ostream & operator <<(ostream &os,const complex &x)
{
	return os<<'('<<x.real()<<','<<x.imag()<<")";
}
int main()
{
	complex a(10,20);
	complex b(2.0,3.0);	
	a+=b;
	cout<<a;
}
