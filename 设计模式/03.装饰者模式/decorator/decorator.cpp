#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Component;
class concreteConponent;
class Decoratro;
class Component {
protected:
	float price;
	int size;
public:
	 Component(float p, int s = 0)
	{
		price = p;
		switch(s)
		{
		case 1:
			size = 1;
			break;
		case 2:
			size = 2;
			break;
		case 3:
			size = 3;
			break;
		case 0:
			size = 0;
			break;
		default:
			return;
		}
		size = s;
	}
	 Component()
	 {
		 
	}
	 virtual ~Component()
	 {
		 cout << "com" << endl;
	 }

	 virtual int setPrice(float p)
	 {
		 this->price = p;
		 return 0;
	 }
	virtual float Price()
	{
		return price;
	}
	virtual int Size()
	{
		return size;
	}
};
class concreteConponent :public Component {
private:
	string name =  "HouseBlend";
public:
	concreteConponent()
	{
		this->size = 0;
		this->setPrice(10);
	}
	concreteConponent(float p, int s = 0) :Component(p, s)
	{
		this->setPrice(10);
	}
	float Price()
	{
		if (size == 0 || size == 2)
		{
			return this->price;
		}
		else if (size == 1)
		{
			return this->price * 0.7;
		}
		else if (size == 3)
		{
			return this->price * 1.2;
		}
		else {
			exit;
		}
	}


};
class Decoratro:public Component
{
protected:
	string name ;
	Component *obj;
public:
	Decoratro(Component* ob, string na)
	{
		obj = ob;
		this->size = 0;
		this->name = na;
		this->setPrice(10);
	}
	~Decoratro()
	{
		//cout << name << endl;
		delete obj;
		
	}
	Decoratro(float p, int s, Component* ob, string na) :Component(p, s)
	{
		obj = ob;
		this->name = na;
		this->size = obj->Size();
	}
	float Price()
	{
		if (obj->Size() == 0 || obj->Size() == 2)
		{
			return this->price+obj->Price();
		}
		else if (obj->Size()==1)
		{
			return this->price * 0.7 + obj->Price();
		}
		else if (obj->Size()==3)
		{
			return this->price * 1.2 + obj->Price();
		}
		else {
			exit;
		}
	}
	int Size()
	{
		return obj->Size();
	}


};
class Mike :public Decoratro
{
public:
	Mike(Component* ob,  string name = "mike") :  Decoratro(ob, name)
	{
		this->price = 4;
		this->size = ob->Size();
	}
	~Mike()
	{
		cout << this->name<< endl;
	}

};
class Mocha :public Decoratro
{
public:
	Mocha(Component* ob, string name = "Mocha") :Decoratro(ob, name) 
	{
		this->price = 4;
		this->size = ob->Size();
	}
	~Mocha()
	{
		cout << name << endl;
	}

};
int main()
{
	Component* obj;

	for (int i = 0; i<4;i++)
	{
		obj = new concreteConponent(12, i);
		obj = new Mike(obj);
		obj = new Mocha(obj);
		float price = obj->Price();
		delete obj;
		cout << price << endl;
	}

	return 0;


}