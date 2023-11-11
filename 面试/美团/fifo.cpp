#include "stdio.h"
#include<iostream>
#include <vector>
#include <ctime>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
class JCB{
private :
	int id;
	int startTime;
	int doneTIme;
	int serverTime;
	int creatTime;
public:
	JCB(int ID,  int ServerTime):id(ID),  serverTime(ServerTime){
		creatTime = std::time(0);
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

	bool cmpcreat(JCB const * peer)
	{
		if (this->creatTime <= peer->creatTime)
		{
			return true;
		}
		else return false;
	}
	bool cmpserver(JCB const *peer)
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
class JCBworks{
	private:
		list<JCB *> jcbworks;
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
		for(auto i : jcbworks)
		{
			cout << "µÚ"<<j<<"¸ö      id = " << i->getid() << "   starttime:= "<<i->getcreatTiem()<<endl;
		}
	}
	 bool appendJCB(JCB * jcb)
	 {
		 auto it = jcbworks.begin();
		 switch (status)
		 {
		 case 0:{
					for (; it != jcbworks.end(); it++)
					{

						if (!jcb->cmpcreat(*(it)))
						{
							jcbworks.insert(it, jcb);
							break;
						}
					}
					break;
		 }
		 case 1:
		 {
				   for (; it != jcbworks.end(); it++)
				   {

					   if (!jcb->cmpserver((*it)))
					   {
						   jcbworks.insert(it, jcb);
						   break;
					   }
				   }
				   break;
		 }

		 }

	 }

};
int main()
{
	int nums[10] = { 10,3,1,5,6,1,4,6,2,7};
	JCBworks *works = new JCBworks(1);
	for (int i = 0; i < 10;i++)
{
	JCB * jcb = new JCB(i,nums[i]);
	works->appendJCB(jcb);
}
	works->show();	

	return 0;
}
