#include "stdio.h"
#include<iostream>
#include <vector>
#include <ctime>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
#define FLT_MAX 3.402823466e+38F
#define FLT_MIN 1.175494351e-38F 
class JCB {
private:
	int id;
	int startTime;
	int doneTIme;
	int serverTime;
	int creatTime;
public:
	JCB(int ID, int ServerTime, int CreattTiem) :id(ID), serverTime(ServerTime), creatTime(CreattTiem) {

	}
	int getid()
	{
		return id;
	}
	void setStartTime(int time)
	{
		startTime = time;
	}
	int getcreatTiem()
	{
		return creatTime;
	}
	int getstartTiem()
	{
		return startTime;
	}
	int getdoneTime()
	{
		return doneTIme;
	}
	int getserverTime()
	{
		return serverTime;
	}
	bool setdoneTime()
	{
		doneTIme = std::time(0);
	}

	bool cmpcreat(JCB const* peer)
	{
		if (this->creatTime <= peer->creatTime)
		{
			return true;
		}
		else return false;
	}
	bool cmpserver(JCB const* peer)
	{
		if (this->serverTime <= peer->serverTime)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class JCBworks {
private:
	list<JCB*> jcbworks;
	int status;
public:
	JCBworks(int stuts) :status(stuts)
	{

	}
	void setStatus(int sta)
	{
		status = sta;
		return;
	}
	void show()
	{
		int j = 0;
		list<JCB*>::iterator itr = jcbworks.begin();
		int t = 0;
		for (; itr != jcbworks.end(); itr++)
		{
			if (status == 0)
			{
				cout << "当前时间： " << t << "   ";
				cout << "第" << j << "个      id = " << (*itr)->getid() << "   starttime:= " << (*itr)->getcreatTiem() << "   srevertime:= " << (*itr)->getserverTime() << endl;
				t += (*itr)->getserverTime();
			}
			else
			{
				cout << "当前时间： " << t << "   ";
				cout << "第" << j << "个      id = " << (*itr)->getid() << "   starttime:= " << (*itr)->getcreatTiem() << "   srevertime:= " << (*itr)->getserverTime() << endl;
				t += (*itr)->getserverTime();
			}

			j++;
		}
		cout << "全部完成，总花费：" << t << endl;
	}
	void appendJCB(JCB* jcb)
	{
		auto it = jcbworks.begin();
		switch (status)
		{
		case 0: {

			for (; it != jcbworks.end(); it++)
			{

				if (jcb->cmpcreat(*(it)))
				{

					jcbworks.insert(it, jcb);
					break;
				}
			}
			if (it == jcbworks.end())
			{
				jcbworks.insert(it, jcb);
			}
			break;
		}
		case 1:
		{
			for (; it != jcbworks.end(); it++)
			{

				if (jcb->cmpserver((*it)))
				{
					jcbworks.insert(it, jcb);
					break;
				}

			}
			if (it == jcbworks.end())
			{
				jcbworks.insert(it, jcb);
			}

			break;
		}

		}

	}

};
int main()
{
	int nums[10] = { 11,23,14,12,15,12,16,17,13,17 };
	int time[10] = { 10,3,1,5,6,1,4,6,2,7 };
	JCBworks* works = new JCBworks(0);
	for (int i = 0; i < 10; i++)
	{
		JCB* jcb = new JCB(i, nums[i], time[i]);

		works->appendJCB(jcb);
	}
	cout << "creatTime" << endl;
	works->show();
	JCBworks* works2 = new JCBworks(1);
	for (int i = 0; i < 10; i++)
	{
		JCB* jcb = new JCB(i, nums[i], time[i]);

		works2->appendJCB(jcb);
	}
	cout << "serverTime" << endl;
	works2->show();
	system("pause");
	return 0;
}