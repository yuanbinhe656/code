#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
		cout << "delet" << endl;
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
	void set(float a,float b,float c)
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
	messageeT(float a,float b,float c)
	{
		this->humidity = a;
		this->pressure = b;
		this->temperature = c;
	}
	void set(message* s)
	{
		cout << "haha" << endl;
		messageeT* p = dynamic_cast<messageeT*>(s);
		cout << "wahaha" << endl;
		this->humidity = p->humidity;
		this->pressure = p->pressure;
		this->temperature = p->temperature;
		delete s;
	}

	
};
class Oberve {
private:
	message* mes;
public :

	virtual void update(message* mess)
	{

	}

	virtual void show()
	{
	}
};

class Obervable {

	
protected:
	message *mes;
	vector<Oberve *> obj;
public:
	virtual void notifyObserve()
	{
		
		for (auto em : obj)
		{
			em->update(mes);

		}
	}
	void registerObserve(Oberve* s)
	{
		obj.push_back(s);
		
	}
	void removeObverse(Oberve *s)
	{
		auto iter = remove(obj.begin(), obj.end(), s);
			if (iter == obj.end())
			{
				cout << "erro" << endl;
				exit(1);
			}
			cout << "have removed obvers" << endl;
	}
	virtual void measurementschanged()
	{
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
	messageeT *mess;
public:
	statisice()
	{
		mess = new messageeT();
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
	void notifyObserve()
	{

		for (auto em : obj)
		{

			em->update(mes);

		}
	}
	void measurementschanged()
	{
		notifyObserve();
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
	
		Obervable *meashu = new WeatherDate();
		Oberve* abc = new statisice();
		Oberve* obj = new statisice();
		meashu->registerObserve(obj);
		//meashu->registerObserve(abc);
		for (int i = 0; i < 10; i++)
		{
			
			
			meashu->setMeaurement(ms);			
			obj->show();
			ms->set(new messageeT(s + i, s + i + 1, s + i + 2));
			if (i == 2)
			{
				meashu->removeObverse(abc);
			}
			
		}

	return 0;
}
