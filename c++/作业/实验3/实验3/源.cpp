#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Furniture
{
protected :
	int Number, Prices;
public :
	Furniture(int num,int p);
	virtual void output();
	virtual void input();
	virtual double Count_Prices();
};
Furniture::Furniture(int num, int p)
{
	Number = num;
	Prices = p;
}
void Furniture::output()
{
	cout << "该家具编号为:" << Number << endl;
	cout << "该家具价格为:" << Prices << endl;
}
void Furniture::input()
{
	cin >> Number;
	cin >> Prices;
}
double Furniture:: Count_Prices()
{
	return Prices;
}
class Sofa : virtual public Furniture
{
protected :
	int weight;
public :
	 virtual double Count_Prices();
	 virtual void output();
	 virtual void input();
	 Sofa(int num, int p ,int w) :Furniture(num, p)
	 {
		 weight = w;
	 }
};
void Sofa::output()
{
	cout << "该沙发的编号为:" << Number << endl;
	cout << "该沙发的价格为:" << Prices << endl;
	cout << "该沙发的重量为:" << weight << endl;
}
void Sofa::input()
{
	cin >> Number;
	cin >> Prices;
	cin >> weight;
}
double Sofa::Count_Prices()
{
	Prices = weight * 10;
	return Prices;
}
class EuroSofa :virtual public Sofa
{
protected :
	int Volume ,Material;
public :
	virtual double Count_Prices();
	virtual void output();
	virtual void input();
	EuroSofa(int num, int p, int w, int m, int v) :Furniture(num, p), Sofa(num, p, w)
	{
		Material = m;
		Volume = v;
	}
};
void EuroSofa::output()
{
	cout << "该欧式沙发的编号为:" << Number << endl;
	cout << "该欧式沙发的材质为:"<<Material <<endl;
	cout << "该欧式沙发的体积为:" << Volume << endl;
	cout << "该欧式沙发的价格为:" << Prices << endl;
	cout << "该欧式沙发的重量为:" << weight << endl;
}
void EuroSofa::input()
{
	cin >> Number;
	cin >> Prices;
	cin >> weight;
	cin >> Volume;
	cin >> Material;

}
double EuroSofa::Count_Prices()
{
	if (Material == 1)
		Prices = Volume * 100;
	else if (Material == 2)
		Prices = Volume * 50;
	else if (Material == 3)
		Prices = Volume * 20;
	else
		Prices = 5;
	return Prices;
}
class Toy :virtual public Furniture
{
protected:
	int Volume, Material;
	virtual void output();
	virtual void input();
public:
	virtual double Count_Prices();
	Toy(int num, int p,int v,int m) :Furniture(num, p)
	{
		Volume = v;
		Material = m;
	}
};
void Toy::output()
{
	cout << "该玩具的编号为:" << Number << endl;
	cout << "该玩具的材质为:" << Material<< endl;
	cout << "该玩具的体积为:" << Volume<< endl;
	cout << "该玩具的价格为:" << Prices << endl;
}
void Toy::input()
{
	cin >> Number;
	cin >> Prices;
	cin >> Volume;
	cin >> Material;

}
double Toy::Count_Prices()
{
	if (Material == 1)
		Prices = Volume * 50;
	else if (Material == 2)
		Prices = Volume * 30;
	else if (Material == 3)
		Prices = Volume * 5;
	else
		Prices = 10;
	return Prices;
}
class EuroToy : virtual public EuroSofa, virtual public Toy
{
protected:
	int Volume, Material,Prices;
public:
	virtual double Count_Prices();
	virtual void output();
	virtual void input();
	EuroToy(int num, int p,int w,int m,int v) :Furniture(num, p), Sofa(num, p, w),EuroSofa(num, p,w,m,v),Toy(num,p,v,m)
	{
		Volume = v;
		Material = m;
		Prices = p;
	}
};
void EuroToy::output()
{
	cout << "该欧式玩具的编号为:" << Number << endl;
	cout << "该欧式玩具的材质为:" << Material << endl;
	cout << "该欧式玩具的体积为:" << Volume << endl;
	cout << "该欧式玩具的价格为:" << Prices << endl;
	cout << "该欧式玩具的重量为:" << weight << endl;
}
void EuroToy::input()
{
	cin >> Number;
	cin >> Prices;
	cin >> weight;
	cin >> Volume;
	cin >> Material;

}
double EuroToy::Count_Prices()
{
	if (Material == 1)
		Prices = Volume * 50;
	else if (Material == 2)
		Prices = Volume * 30;
	else if (Material == 3)
		Prices = Volume * 5;
	else
		Prices = 10;
	return Prices;
}
int main()
{

	Furniture a(2, 3),*p;
	Sofa b(2, 3, 4);
	EuroSofa c(2, 4, 6, 7, 5);
	Toy d(2, 4, 6, 7);
	EuroToy e(5, 1, 7, 5, 4);
	p = &a;
	p->output();
	p=&b;
	p->output();
	p = &c;
	p->output(); 
	p = &d;
	p->output(); 
	p = &e;
	p->output();
	system("pause");



}