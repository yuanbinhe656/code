#include "stdio.h"
#include<iostream>
#include <vector>
#include <ctime>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
enum tcbstatus { wait, done, doing };
#define FLT_MAX 3.402823466e+38F
#define FLT_MIN 1.175494351e-38F 
class TCB {
private:
	int id;
	int startTime;
	int doneTIme;
	int serverTime;
	int creatTime;
	int waitTime;
	tcbstatus status;
	float priority;

public:
	TCB(int ID, int ServerTime, int CreattTiem) :id(ID), serverTime(ServerTime), creatTime(CreattTiem) {
		this->waitTime = 0;
		this->priority = FLT_MAX;
		this->status = wait;
	}
	int getid()
	{
		return id;
	}
	void setStartTime(int time)
	{
		startTime = time;
	}
	tcbstatus  getstatus()
	{
		return this->status;
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

	bool cmpcreat(TCB const* peer)
	{
		if (this->creatTime <= peer->creatTime)
		{
			return true;
		}
		else return false;
	}
	bool cmppr(TCB * peer)
	{
		if (this->getpriority() <= peer->getpriority())
		{
			return true;
		}
		else return false;
	}
	bool cmpserver(TCB const* peer)
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

	int  setrun(int t)
	{
		
		serverTime = serverTime - t;
		if (serverTime <= 0)
		{
			status = done;
			
			 t  +=serverTime;
			 cout << "   done    ";
		}
		else {
			status = wait;
			cout << "   not done";
			this->priority = FLT_MIN;
		}
		waitTime = 0;
		cout << "   run:" << t << " time" << endl;
		return t;
	}
	float getpriority()
	{
		return priority;
	}
	void setwait(int t)
	{
		waitTime += t;
		priority = float((waitTime + serverTime)) / serverTime;

	}
	bool operator > (TCB const* tcb)
	{
		if (this->priority >= tcb->priority)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class my_great{
public:
	bool operator()(TCB* t,TCB* s)
	{
		if (t->getpriority() >= s->getpriority())
		{
			return true;
		}
		else
		{
			return false;
		}
 }
};
class my_greatti {
public:
	bool operator()(TCB* t, TCB* s)
	{
		if (t->getserverTime() >= s->getserverTime())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class TCBworks {
private:
	list<TCB*> tcbworks;
	int status;
public:
	TCBworks(int stuts) :status(stuts)
	{

	}
	void setStatus(int sta)
	{
		status = sta;
		return;
	}
	int  startrun(int t)
	{
		if (tcbworks.size() == 0)
		{
			return 0;
		}
		else {
			auto itr = tcbworks.begin();
			cout << "id = " << (*itr)->getid() << "   starttime: = " << (*itr)->getcreatTiem() << "   srevertime : = " << (*itr)->getserverTime() << "   priority : = " << (*itr)->getpriority() ;
			t =(*itr)->setrun(t);
			
			if ((*itr)->getstatus() == done)
			{
				tcbworks.erase(itr);
				itr = tcbworks.begin();
			}
			else {
				itr++;
			}
			
			
			for (; itr != tcbworks.end(); itr++)
			{
				(*itr)->setwait(t);
				
			}
			tcbworks.sort([](TCB* t, TCB* s) {
				if (t->getpriority() < s->getpriority())
					return true;
				else
					return false;
				});
			
		}
		this->show();
		return t;
	}
	void show()
	{
		int j = 0;
		tcbworks.sort([]( TCB* t,  TCB* s) {
			if (t->getserverTime() < s->getserverTime())
				return true;
			else
				return false;
			});
		
		list<TCB*>::iterator itr = tcbworks.begin();

		for (; itr != tcbworks.end(); itr++)
		{
			if (status == 0)
			{
				cout << "id = " << (*itr)->getid() << "   starttime: = " << (*itr)->getcreatTiem() << "   srevertime : = " << (*itr)->getserverTime() << "   priority : = " << (*itr)->getpriority() << endl;;
			}
			else
			{
				cout << "id = " << (*itr)->getid() << "   starttime: = " << (*itr)->getcreatTiem() << "   srevertime : = " << (*itr)->getserverTime() << "   priority : = " << (*itr)->getpriority();
			}

			j++;
		}
	}
	void appendTCB(TCB* tcb)
	{
		auto it = tcbworks.begin();
		switch (status)
		{
		case 0: {

			for (; it != tcbworks.end(); it++)
			{

				if (tcb->cmpcreat(*(it)))
				{

					tcbworks.insert(it, tcb);
					break;
				}
			}
			if (it == tcbworks.end())
			{
				tcbworks.insert(it, tcb);
			}
			break;
		}
		case 1:
		{
			for (; it != tcbworks.end(); it++)
			{

				if (!tcb->cmpserver((*it)))
				{
					tcbworks.insert(it, tcb);
					break;
				}

			}
			if (it == tcbworks.end())
			{
				tcbworks.insert(it, tcb);
			}

			break;
		}
		case 2:
		{
			for (; it != tcbworks.end(); it++)
			{

				if (tcb->cmppr((*it)))
				{
					tcbworks.insert(it, tcb);
					break;
				}

			}
			if (it == tcbworks.end())
			{
				tcbworks.insert(it, tcb);
			}

			break;
		}
		}

	}

};
int main()
{
	int nums[10] = { 10,3,1,5,6,1,4,6,2,7 };
	int time[10] = { 1,3,4,2,5,2,6,7,3,7 };
	TCBworks* works = new TCBworks(0);
	for (int i = 0; i < 10; i++)
	{
		TCB* jcb = new TCB(i, nums[i], time[i]);

		works->appendTCB(jcb);
	}

	int runtime = 2;
	int ti = 0;
	//works->show();
	while (1)
	{
		cout << "the " << ti << "  time:   ";
		int t = works->startrun(runtime);
		if (t == 0)
		{
			cout << "all done";
			break;
		}
		
		ti += t;

	}
	system("pause");
		return 0;
}
