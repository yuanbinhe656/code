#include <atomic>
#include <thread>
#include <iostream>
#include <list>
#include <Windows.h>
using namespace std;

std::atomic_bool isReady = false;
//std::atomic_int countless = 0;
	int countles = 0;
void task()
{
	while (isReady)
	{
		this_thread::yield();
	}
	
	for (int i = 0; i < 100; ++i)
	{
		countles++;
	}
}
int main()
{
	list<thread> tlist;
	for (int i = 0; i < 10; i++)
	{
		tlist.push_back(thread(task));
	}
	Sleep(3);
	
	cout << countles << endl;
	for (auto &it : tlist)
	{
		it.join();
	}
	return 0;
	

}