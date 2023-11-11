#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Complex {
public :
	Complex(float a, float b)
	{
		 real= a;
		 image = b;
		 num++;
	}
	static int num;
	void save();
	Complex()
	{
		num++;
	}
	friend ostream & operator << (ostream & out, Complex);
	friend istream & operator >> (istream & in, Complex&);
	Complex(float);
	friend Complex operator *(Complex s, Complex t);

	friend Complex operator -(Complex s, Complex t);
	operator float()
	{
		return image;
	}

	 friend Complex operator +(Complex s, Complex t);

	int operator [](int a)
	{

		if (a < 0 || a>1)
		{
			
		}
		if (a == 0)
		{
			return real;
		}
		else if(a==1)
		{
			return image;
		}
		else {
			cout << "错误" << endl;
			return 1;
		}
		

	}
	Complex operator ++()
	{
		
		++real;

		return *this;

	}
	Complex operator ++(int a)
	{

		real++;

		return *this;

	}
private:
	float real;
	float image;
};
Complex operator *(Complex s, Complex t)
{
	Complex a;
	a.real = t.real * s.real - t.image * s.image;
	a.image = t.image * s.real + t.real * s.image;
	return a;

}
void Complex::save()
{

	ofstream out("data.txt", ios::app | ios::binary);
	if (!out)
	{
		cout << "Cannot open file.\n";
		
	}
	
		out << *this;
	out.close();
	
}
Complex operator -(Complex s, Complex t)
{
	Complex a;
	a.real = s.real -t.real;
	a.image = s.image - t.image ;
	return a;

}
Complex operator +(Complex s, Complex t)
{
	Complex a;
	a.real = s.real + t.real;
	a.image = s.image + t.image;
	return a;

}
ostream &operator << (ostream & out, Complex  s)
{
	out << s.real<<",";
	out << s.image<<endl;
	return out;
}
istream &operator >> (istream& in, Complex & s)
{
	
	in >> s.real;
	in >> s.image;
	return in;
}
Complex ::Complex(float t)
{
	real = 0;
	image = t;
}
void xiugai(int n)
{
	ifstream in("data.txt", ios::_Nocreate);
	int s = 0,t;
	Complex *a = new Complex[100];
	while (!in.eof())
	{
		t = sizeof(Complex);
		in.read((char*)&a[s], t);

		s ++ ;
		
	
	}
	in.close();
	cout << "请输入要修改的复数" << endl;
	cin >> a[n];
	ofstream out("data.txt", ios::binary|ios::app);
	for (int i = 0; i < s - 1; i++)
	{
		out.write((char*)(a+i), sizeof(Complex));
	}

	out.close();
}

void show(int n)
{
	ifstream in("data.txt", ios::in | ios::binary);
	Complex* tmp = new Complex[4];
	for (int i = 0; i < Complex::num; i++)
	{
		in >> tmp[i];
	}
	cout << "kaishi" << endl;
	cout <<ios::dec<< tmp[n - 1] << endl;
	in.close();

		

	
}
int Complex:: num = 0;
void main()
{
	Complex *cs[] = {
	new Complex(2.0, 3.5),
	new Complex(1, 3.6),
	new Complex(14, 5),
	new Complex(3, 0.1)
	};
	for (int i = 0; i < 4; i++)
	{
		cs[i]->save();
	}
	cout << "bu";
	Complex a(1.2, 3.3);
	Complex b(1.1, 3.3);
	Complex c(1.3, 3.3);
	Complex d(1.4, 3.3);
	a.save();

	b.save();
	c.save();
	d.save();
	show(2);
	/*show(2);
	cout << "x";
	show(4);
	a = *cs[1]**cs[3];
	xiugai(3);*/
}

