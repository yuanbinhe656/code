#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class message {
public:
	virtual void show(){
	};
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
	void show()
	{
		cout << "The temperature is" << this->temperature << endl;
		cout << "The humidity is" << this->humidity << endl;
		cout << "The pressure is" << this->pressure << endl;
	}
//	 messageeT(const  messageeT* s)
//	{
//		this->humidity = s->humidity;
//		this->pressure = s->pressure;
//		this->temperature = s->temperature;
//	}
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
	
};
int main()
{
	messageeT *t = new messageeT(1.2,2.3,3.2);
	t->show();
	return 0;
}
