#include <iostream>
using namespace std;
class Base
{ 
public:
	virtual void fun1() {
		cout << "fu";
	}
	virtual void fun2() {}
public:
	int Ba;
protected:
	int Bb;
private:
	int Bc;
};

class Son1 :public virtual Base
{
public:
	virtual void fun3() {}
public:
	int S1a;
protected:
	int S1b;
private:
	int S1c;
};
class Son3 :public  Base
{
public:
	virtual void fun3() {}
public:
	int S1a;
protected:
	int S1b;
private:
	int S1c;
};
class Son4 :public  Base
{
public:
	virtual void fun3() {}
public:
	int S2a;
protected:
	int S2b;
private:
	int S2c;
};
class Son2 :public virtual Base
{
public:
	virtual void fun4() {}
public:
	int S2a;
protected:
	int S2b;
private:
	int S2c;
};

class Grandson :public virtual Son1, public virtual Son2
{
public:
	void fun1() {
		cout << "go";
	}
	virtual void fun5() {}
public:
	int Ga;
protected:
	int Gb;
private:
	int Gc;
};
class nov :public  Son1, public  Son2
{
public:
	void fun1() {}
	virtual void fun5() {}
public:
	int Na;
protected:
	int Nb;
private:
	int Nc;
};
class nv :public  Son3, public  Son4
{
public:
	void fun1() {}
	virtual void fun5() {}
public:
	int Na;
protected:
	int Nb;
private:
	int Nc;
};
int main()
{
	
	Base b;
	Son1 son;
	Grandson s;
	nov n;
	nv z;
	Base& p = s;
	p.fun1();
	cout << "s:" << sizeof(z) << " n:" << sizeof(n) << endl;

}

