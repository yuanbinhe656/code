#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class work {
private:
	int id;
	int start;
	int end;
	int size;
	int stat;
public:
	work(int ID, int Size, int Start = 0, int Stat = 1) :id(ID), start(Start), stat(Stat) {
		this->end = Start + Size;
	}
	bool setstart(int Start)
	{
		if (stat = 1)
		{
			this->start = Start;
			this->end = this->start + this->size;
		}
		else if (stat == 0)
		{
			this->start = Start;
			this->size = this->end + this->start;
		}
		return true;

	}
	bool setid(int ID)
	{
		if (stat == 0)
		{
			id = ID;
			stat = 1;
			return true;
		}
		else
		{
			return false;
		}
	}
	int setstat(int Stat)
	{
		stat = Stat;
	}
	int getid()const
	{
		return id;
	}
	int getstat()const {
		return stat;
	}
	int getstart()const
	{
		return start;
	}
	int getend()const
	{
		return end;
	}
	int getsize()const
	{
		return size;
	}
	bool operator==(const work& s)const
	{
		if (id == s.id && stat == s.stat)
		{
			return true;
		}
		else
			return false;
	}
};
class master {
protected:
	int start;
	int end;
	int busy;
	int free;
	list<work> listworks;
	list<work> freeworks;
	list<work> busyworks;
public:
	master(int End, int Start = 0) :start(Start), end(End) {
		work s(0, End - Start, Start, 0);
		listworks.push_back(s);
		freeworks.push_back(s);
	}
	bool virtual addwork(const work s) = 0;

	bool virtual delwork(const int num) = 0;



};
class firstmaster :public master {
public:
	firstmaster(int End, int Start = 0) :master(Start, End) {

	}
	bool virtual addwork(work s)
	{
		if (s.getsize() <= free)
		{
			auto itr = freeworks.begin();
			for (; itr != freeworks.end(); itr++)
			{
				if ((*itr).getsize() > s.getsize())
				{
					auto litr = find(listworks.begin(), listworks.end(), (*itr));
					s.setstart((*itr).getstart());
					(*itr).setstart(s.getend());
					(*litr).setstart(s.getend());
					listworks.insert(litr, s);
					return true;
				}
				else if ((*itr).getsize() == s.getsize())
				{
					auto litr = find(listworks.begin(), listworks.end(), (*itr));
					(*litr).setid(s.getid());
					freeworks.erase(itr);
					return true;
				}
			}
			if (itr == freeworks.end())
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	bool virtual delwork(const int num)
	{
		work tem(num, 0);
		auto itr = find(listworks.begin(), listworks.end(), tem);
		if (itr != listworks.end())  // todo 不同情况下的删除
		{

			if (itr == listworks.begin())
			{
				if (++itr == listworks.end())
				{
					(*itr).setstat(0);

				}
			}
		}
	}
};
class goodmaster :public master {
public:
	goodmaster(int End, int Start = 0) :master(Start, End) {

	}
	bool virtual addwork(const work s)
	{
		if (s.getsize() <= free)
		{
			return false;
		}
	}
	bool virtual delwork(const int num)
	{

	}
};
int main()
{
	return 0;
}


