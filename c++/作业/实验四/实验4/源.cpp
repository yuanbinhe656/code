#include<iostream>
using namespace std;

class Rational;
istream& operator >>(istream& istr, Rational& r);
ostream& operator <<(ostream& ostr, const Rational& d);

class Rational
{
private:
	long num, den;
	void standardize(void);
public:
	Rational(int num = 0, int den = 1);
	Rational operator+(Rational);
	Rational operator-(Rational);
	Rational operator*(Rational);
	Rational operator/(Rational);
	Rational operator=(const Rational&);
	void huajian(void);
	friend istream& operator>>(istream& istr, Rational&);
	friend ostream& operator<<(ostream& ostr,const Rational&d);
};
Rational::Rational(int n, int m) :num(n),den(m)
{
	if (den == 0)
	{
		cerr << "A zero denminator is invalid" << endl;
		exit(1);
	}
}
void Rational::standardize()
{
	if (den < 0)
	{
		den = -den;
		num = -num;
	}
}
 void Rational:: huajian(void)
{
	int n, m, d;
	n = num;
	m = den;

	while (m!=0)
	{
		d = n % m;
		n = m;
		m = d;
	}
	num = num / n;
	den = den / n;
	
}
istream& operator >>(istream& istr, Rational& r)
{
	char c;
	istr >> r.num >> c >> r.den;
	if (r.den== 0)
	{
		cerr << "A zero denminator is invalid" << endl;
		exit(1);
	}
	r.standardize();
	return istr;
}
ostream& operator <<(ostream& ostr, const Rational& d)
{
	ostr << d.num <<'/' << d.den<<endl;
	return ostr;
}
Rational Rational::operator+(Rational r)
{
	Rational temp;
	temp.num = this->den * r.num+r.den*this->num;
	temp.den = this->den * r.den;
	temp.huajian();
	return temp;
}
Rational Rational::operator-(Rational r)
{
	Rational temp;
	temp.num = r.den * this->num- this->den * r.num;
	temp.den = this->den * r.den;
	if (temp.num == 0)
	{
		temp.num = 0;
		temp.den = 1;
		return temp;
	}
	temp.huajian();
	return temp;
}
Rational Rational::operator*(Rational r)
{
	Rational temp;
	temp.num = this->num * r.num;
	temp.den = this->den * r.den;
	temp.huajian();
	return temp;
}
Rational Rational::operator/(Rational r)
{
	Rational temp;
	temp.num = this->num * r.den;
	temp.den = this->den * r.num;
	temp.huajian();
	return temp;
}
Rational Rational ::operator=(const Rational& r)
{
	if (this == &r)
	{
		return *this;
	}
	this->num = r.num;
	this->den = r.den;
}
int main()
{
	Rational a(2, 3),b(4,6),c;
	c = a + b;
	cout << c << endl;
	c = a - b;
	cout << c << endl;
	c = a * b;
	cout << c << endl;
	c = a / b;
	cout << c << endl;
	system("pause");
	return 0;

	
}