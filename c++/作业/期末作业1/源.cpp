#include<iostream>
using namespace std;
class Shape {
public :
	virtual double area() = 0;
	Shape (double i)
	{
		a = i;
	}
protected:
	double a;
};
class Trapezoid :  public Shape
{
public:
	Trapezoid(double i, double j,double t) :Shape(i)
	{
		b = j;
		h = t;
	}
	double area()
	{
		return (a+b)*h/2;
	}
private:
	double b;
	double h;
};
class Triangle : public Shape
{
public:
	Triangle(double i, double j) :Shape(i)
	{
		
		h = j;
	}
	double area()
	{
		return a * h / 2;
	}
private:
	
	double h;
};
int main()

{

	Shape* p;

	Trapezoid td(2, 5, 4);

	Triangle te(5, 8);

	double da = 0;

	p = &td;

	cout << p->area() << endl;

	p = &te;

	cout << p->area() << endl;

	return 0;

}