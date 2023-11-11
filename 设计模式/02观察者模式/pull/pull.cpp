#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;
class message;
class messageeT;
class Oberve;
class statisice;
class WeatherDate;
class Obervable;
class message {
public:
	virtual void show()
	{
	}
	virtual void set(message*)
	{

	}
	~message()
	{
		
	}
};
class messageeT :public message {
	float temperature;
	float humidity;
	float pressure;
public:
	float Temperature()
	{
		return this->temperature;
	}
	float Humidity() {
		return this->humidity;
	}
	float Pressure() {
		return this->pressure;
	}
	void set(float a, float b, float c)
	{
		this->humidity = a;
		this->pressure = b;
		this->temperature = c;
	}
	void show()
	{

		cout << "The humidity is" << this->humidity << endl;
		cout << "The pressure is" << this->pressure << endl;
		cout << "The temperature is" << this->temperature << endl;
	}
	messageeT(const  messageeT* s)
	{
		this->humidity = s->humidity;
		this->pressure = s->pressure;
		this->temperature = s->temperature;
	}
	//	 messageeT operator = (const messageeT* s)
	//	{
	//		this->humidity = s->humidity;
	//		this->pressure = s->pressure;
	//		this->temperature = s->temperature;
	//		cout << "fuzhigouzao=" << endl;
	//	}
	messageeT()
	{
		this->humidity = 0;
		this->pressure = 0;
		this->temperature = 0;
	}
	messageeT(float a, float b, float c)
	{
		this->humidity = a;
		this->pressure = b;
		this->temperature = c;
	}
	void set(message* s)
	{
		
		messageeT* p = dynamic_cast<messageeT*>(s);
		this->humidity = p->humidity;
		this->pressure = p->pressure;
		this->temperature = p->temperature;
		delete s;
	}


};
class Oberve {
private:
	
	message* mes;
public:
	Obervable* objs;
	Oberve(Obervable* obj)
	{
		this->objs = obj;

	}
	Oberve()
	{

	}
	virtual int update()
	{
		return 0;
	}
	virtual void update(message* mess)
	{

	}

	virtual void show()
	{
	}
};

class Obervable {


protected:
	

	map<Oberve*,bool> obj;
	vector< Oberve*> objs;
public:
	message* mes;
	virtual message* getdata(Oberve*p)
	{
		return nullptr;
	}
	virtual void notifyObserve()
	{
		
		for (auto em : objs)
		{
			
				em->update(mes);
			
			

		}
	}
	void registerObserve(Oberve* s,bool b)
	{
		obj.insert(pair< Oberve* , bool>(s,b));

	}
	void registerObserve(Oberve* s )
	{
		objs.push_back(s);

	}
	void removeObverse(Oberve* s)
	{
		int i = obj.erase(s);
		
		if ( i > 0)
		{
			cout << "delet "<<i << endl;
			//exit(1);
		}
		else {
			auto iter = remove(objs.begin(), objs.end(), s);
			if (iter == objs.end())
			{
				cout << "erro" << endl;
				//exit(1);
			}
			cout << "have not removed obvers" << endl;
		}
		
	}
	virtual void measurementschanged()
	{
	
		for (auto &em : obj)
		{
			
			em.second = 1;
		
		}
		
		notifyObserve();
	}
	virtual void setMeaurement(message* mess)
	{
		mes = mess;
		this->measurementschanged();
	}
};

class statisice : public Oberve {
private:
	messageeT* mess;
public:
	statisice(Obervable * obj):Oberve(obj)
	{
		obj->registerObserve(this, 0);
		mess = new messageeT();
	}
	statisice()
	{
		mess = new messageeT();
	}
	
	int update()
	{
		
		
		messageeT* s = dynamic_cast<messageeT*>(objs->getdata(this)) ;
		//
		if (nullptr != s)
		{
			
			this->mess->set(s);
			
			
			this->show();
		}
		else {
		
		}
		return 0;
	}
	void show()
	{

		mess->show();
	}

	void update(message* mes)
	{
		mess = dynamic_cast<messageeT*>(mes);
	}
};
class WeatherDate : public Obervable {

public:
	WeatherDate()
	{
		this->mes = new messageeT();
	}
	message* getdata(Oberve* p)
	{
		auto iter = obj.find(p);

		if (iter != obj.end() && iter->second == 1)
		{

			messageeT* w = new messageeT(dynamic_cast<messageeT*>(this->mes));
				
			iter->second = 0;
			return w;
		}
		else
		{

			return nullptr;
		}
	}
	void notifyObserve()
	{

		for (auto em : objs)
		{
			
				em->update(mes);
			
			

		}
	}

	void setMeaurement(messageeT* mess)
	{
		mes = mess;

		this->measurementschanged();
	}

};
void me(Oberve* ms)
{

	ms->show();
}
int main()

{
	float s = 1.1;
	message* ms = new messageeT(s, s + 1, s + 2);

	Obervable* meashu = new WeatherDate();
	Oberve* abc = new statisice();
	Oberve* zhuabc = new statisice(meashu);
	Oberve* obj = new statisice();
	meashu->registerObserve(obj);
	
	meashu->registerObserve(abc);
	for (int i = 1; i < 10; i++)
	{
	meashu->setMeaurement(ms);			
			obj->show();
			zhuabc->update();
			ms->set(new messageeT(s + i, s + i + 1, s + i + 2));
	
		if (i == 2)
		{
			zhuabc->update();
			meashu->removeObverse(abc);//测试删除不在其观察者表中对象
		}
		
		

	}

	return 0;
}
