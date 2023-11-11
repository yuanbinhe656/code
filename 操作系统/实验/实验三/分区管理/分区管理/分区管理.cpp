#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
using namespace std;

class work {
private:
	int id;
	int start;
	int end;
	int size;
	int stat;
public:
	work(int ID, int Size, int Start = 0, int Stat = 1) :id(ID),size(Size), start(Start), stat(Stat) {
		this->end = Start + Size;
	}
	bool setstart(int Start)
	{
		if (stat == 1)
		{
			this->start = Start;
			this->end = this->start + this->size;
		}
		else if (stat == 0)
		{
			this->start = Start;
			this->size = this->end - this->start;
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
	int setsize(int Size)
	{
		this->size = Size;
		this->end = this->start + Size;
		return size;
	}
	int setstat(int Stat)
	{
		stat = Stat;
		return stat;
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
	set<int> bit;
	list<work> listworks;
	list<work> freeworks;
	list<work> busyworks;
public:
	master(int End, int Start = 0) :start(Start), end(End) {
		work s(0, End - Start, Start, 0);

		free = End - Start;
		listworks.push_back(s);
		freeworks.push_back(s);
	}
	bool virtual addwork(const work s) = 0;

	bool virtual delwork(const int num) = 0;
	
	bool virtual insertlist(list<work>& free, work s) = 0;

	void showfree() {
		cout << "内存大小为 ：" << this->end - this->start << "   内存已使用 ：" << this->end - this->free << "   内存剩余" << this->free << endl;
		cout << " worklist" << endl;
		cout << "stat 为 1 为使用，stat 为 0 为空闲" << endl;
		cout << "ID" << "     " << "start" << "    " << "end" << "     " << "size"<<"     " << "stat" << endl;
		for (auto& itr : listworks)
		{
			cout << itr.getid() << "       " << itr.getstart() << "       " << itr.getend() << "       " << itr.getsize() << "       " << itr.getstat() << endl;
		}

		cout << " freelist" << endl;
		
		cout << "ID" << "     " << "start" << "    " << "end" << "     " << "size" << "     " << "stat" << endl;
		for (auto& itr : freeworks)
		{
			cout << itr.getid() << "       " << itr.getstart() << "       " << itr.getend() << "       " << itr.getsize() << "       " << itr.getstat() << endl;
		}

	}


};
class firstmaster :public master {
public:
	firstmaster(int End, int Start = 0) :master(End, Start) {

	}
	bool virtual insertlist(list<work>& free, work s)
	{
		int w = 0;
		for (auto itr = free.begin(); itr != free.end(); itr++)
		{
			w++;
			if (itr->getstart() > s.getstart())
			{
				//itr--;
				//cout << itr->getid() << "     s  "<<w<<endl;
				//cout << "wancheng" << endl;
				//break;
				free.insert(itr, s);
				return true;
			}
		}
		free.insert(free.end(), s);
		return true;
	}
	bool  addwork(work s)
	{
		if (bit.count(s.getid()) == 1)
		{
			cout << "该id已使用，请换其他的ID" << endl;
			return false;
		}
		bit.insert(s.getid());
		if (s.getsize() <= free)
		{
			auto itr = freeworks.begin();
			for (; itr != freeworks.end(); itr++)
			{
				if ((*itr).getsize() > s.getsize())
				{
					auto litr = find(listworks.begin(), listworks.end(), (*itr));
					s.setstart((*itr).getstart());
					itr->setstart(s.getend());
					litr->setstart(s.getend());
					listworks.insert(litr, s);
					
					free -= s.getsize();
					return true;
				}
				else if ((*itr).getsize() == s.getsize())
				{
					auto litr = find(listworks.begin(), listworks.end(), (*itr));
					(*litr).setid(s.getid());
					litr->setstat(1);
					freeworks.erase(itr);
					free -= s.getsize();
					return true;
				}
			}
			if (itr == freeworks.end())
			{
				bit.erase(s.getid());
				return false;
			}
		}
		else
		{
			bit.erase(s.getid());
			cout << "内存不足"<< endl;
			return false;
		}
	}
	bool virtual delwork(const int num)
	{

		work tem(num, 0);
		auto itr = find(listworks.begin(), listworks.end(), tem);
		if (itr != listworks.end())
		{
			free += itr->getsize();
			if (itr == listworks.begin())
			{
				auto itrr = itr;
				itrr++;
				if (itrr == listworks.end()) //内存只有一个空间块使用
				{
					(*itr).setstat(0);
					
					freeworks.push_back(*itr);

				}
				else {
					if ((*itrr).getstat() == 0)
					{
						itr->setsize(itr->getsize() + itrr->getsize());
						listworks.erase(itrr);
						
						auto fitr = freeworks.begin();
						fitr->setsize(itr->getsize());

					}
					else {
						itr->setstat(0);
						freeworks.insert(freeworks.begin(), *itr);
					}
				}
			}
			else
			{
				auto itrl = itr;
				itrl--;
				auto itrr = itr;
				itrr++;
				if (itrl->getstat() == 0 && itrr != listworks.end() && itrr->getstat() == 0)
				{
					auto fitr = find(freeworks.begin(), freeworks.end(), *itrl);
					itrl->setsize(itrl->getsize() + itr->getsize() + itrr->getsize());
					fitr->setsize(itrl->getsize());
					itrr = listworks.erase(itr);
					listworks.erase(itrr);
					
						
				}
				else  if (itrl->getstat() == 0){
					auto fitr = find(freeworks.begin(), freeworks.end(), *itrl);
					itrl->setsize(itrl->getsize() + itr->getsize());
					fitr->setsize(itrl->getsize());
					 listworks.erase(itr);
					 
				}
				else {
					itr->setstat(0);
					this->insertlist(this->freeworks, *itr);
					//fitr--;
					//cout << fitr->getid() << endl;
					//this->freeworks.insert(fitr, *itr);
				}
			}
			bit.erase(num);
			return true;
		}
		else {
			cout << "该任务不存在" << endl;
			return false;
		}
	}
};
class goodmaster :public master {
public:
	goodmaster(int End, int Start = 0) :master(End, Start) {

	}
	bool virtual insertlist(list<work>& free, work s)
	{
	
		for (auto itr = free.begin(); itr != free.end(); itr++)
		{
			
			if (itr->getsize()> s.getsize())
			{
				//itr--;
				//cout << itr->getid() << "     s  "<<w<<endl;
				//cout << "wancheng" << endl;
				//break;
				//itr--;
				free.insert(itr, s);
				return true;
			}
		}
		free.insert(free.end(), s);
		return true;
	}
	bool  addwork(work s)
	{
		if (bit.count(s.getid()) == 1)
		{
			cout << "该id已使用，请换其他的ID" << endl;
			return false;
		}
		bit.insert(s.getid());
		if (s.getsize() <= free)
		{
			auto itr = freeworks.begin();
			for (; itr != freeworks.end(); itr++)
			{
				if ((*itr).getsize() > s.getsize())
				{
					auto litr = find(listworks.begin(), listworks.end(), (*itr));
					s.setstart((*itr).getstart());
					
					litr->setstart(s.getend());
					//to do inset free
					freeworks.erase(itr);
					this->insertlist(this->freeworks, *litr);
					listworks.insert(litr, s);

					free -= s.getsize();
					return true;
				}
				else if ((*itr).getsize() == s.getsize())
				{
					auto litr = find(listworks.begin(), listworks.end(), (*itr));
					(*litr).setid(s.getid());
					litr->setstat(1);
					freeworks.erase(itr);
					free -= s.getsize();
					return true;
				}
			}
			if (itr == freeworks.end())
			{
				bit.erase(s.getid());
				return false;
			}
		}
		else
		{
			bit.erase(s.getid());
			cout << "内存不足" << endl;
			return false;
		}
	}
	bool virtual delwork(const int num)
	{

		work tem(num, 0);
		auto itr = find(listworks.begin(), listworks.end(), tem);
		if (itr != listworks.end())
		{
			free += itr->getsize();
			if (itr == listworks.begin())
			{
				auto itrr = itr;
				itrr++;
				if (itrr == listworks.end()) //内存只有一个空间块使用
				{
					(*itr).setstat(0);

					freeworks.push_back(*itr);

				}
				else {
					if ((*itrr).getstat() == 0)
					{
						freeworks.erase(itrr);
						itr->setsize(itr->getsize() + itrr->getsize());
						listworks.erase(itrr);
						this->insertlist(this->freeworks, *itr);
						
						

					}
					else {
						itr->setstat(0);
						this->insertlist(this->freeworks, *itr);

					}
				}
			}
			else //不是第一个元素
			{
				auto itrl = itr;
				itrl--;
				auto itrr = itr;
				itrr++;
				if (itrl->getstat() == 0 && itrr != listworks.end() && itrr->getstat() == 0)//前后都能合并
				{
					freeworks.remove(*itrl);
					freeworks.remove(*itrr);
					
					itrl->setsize(itrl->getsize() + itr->getsize() + itrr->getsize());
					
					itrr = listworks.erase(itr);
					listworks.erase(itrr);
					this->insertlist(this->freeworks, *itrl);


				}
				else  if (itrl->getstat() == 0) { //只能合并一个元素
					//auto fitr = find(freeworks.begin(), freeworks.end(), *itrl);
					freeworks.remove(*itrl);
					
					itrl->setsize(itrl->getsize() + itr->getsize());
					this->insertlist(freeworks, *itrl);
					//fitr->setsize(itrl->getsize());
					listworks.erase(itr);


				}
				else {//不能进行元素合并
					itr->setstat(0);
					this->insertlist(this->freeworks, *itr);
					//fitr--;
					//cout << fitr->getid() << endl;
					//this->freeworks.insert(fitr, *itr);
				}
			}
			bit.erase(num);
			return true;
		}
		else {
			cout << "该任务不存在" << endl;
			return false;
		}
	}
};
void test(master* master)
{
	master->addwork(work(1, 10));
	master->addwork(work(2, 10));
	master->addwork(work(3, 10));
	master->addwork(work(4, 10));
	master->showfree();
	master->delwork(2);
	master->showfree();
	master->addwork(work(2, 5));
	master->showfree();
	master->addwork(work(2, 4));
	master->showfree();
	master->addwork(work(0, 10));
	master->showfree();
}
int main()
{
	master* master; 
	cout << "欢迎使用动态空间管理，请进行初始化操作" << endl;
	int add, size;
	//cout << "请输入开始内存地址" << endl;
	//cin >> add;
	add = 0;
	cout << "请输入内存大小" << endl;
	cin >> size;
	while (1)
	{
		cout << "请输入要选择的分区类型 1.最佳适应分区 2.最先匹配分区" << endl;
		int s;
		cin >> s;


		if (s == 1)
		{
			master = new goodmaster(size, add);
			break;
		}
		if (s == 2)
		{
			master = new firstmaster(size, add);
			break;
		}

	}


	master->showfree();
	//test(master);
	while (1)
	{
		int select;
		cout << "请选择操作" << endl;
		cout << "1.添加任务" << endl;
		cout << "2.删除任务" << endl;
		cout << "3.查看内存" << endl;
		cout << "0.退出" << endl;
		cin >> select;
		if (select == 0)
		{
			break;
		}

		
		else if (select == 1)
		{
			int id;
			int size;
			cout << "请输入任务ID" << endl;
			cin >> id;
			cout << "请输入任务大小" << endl;
			cin >> size;
			cout << "正在准备插入任务 "<<id << endl;
			if (master->addwork(work(id, size)))
			{
				cout << "插入成功" << endl;
			}
			else
			{
				cout << "插入失败" << endl;
			}
		}
		else if (select == 2)
		{
			int id;
			int size;
			cout << "请输入任务ID" << endl;
			cin >> id;
			cout << "正在准备删除任务 "<<id << endl;
			if (master->delwork(id))
			{
				cout << "删除成功" << endl;
			}
			else
			{
				cout << "删除失败" << endl;
			}

		}
		else if (select == 3)
		{
			master->showfree();
		}
	}
	return 0;
}

