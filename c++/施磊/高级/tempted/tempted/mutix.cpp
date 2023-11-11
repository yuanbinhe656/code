#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <Windows.h>
using namespace std;

int countless = 100;
mutex mut;
void threadHandle1(int i, unique_lock<mutex> &&locc)
{

	while (countless > 0)  // 锁加双重判断
	{
		unique_lock<mutex> loc(forward< unique_lock<mutex>>(locc));
		//loc.lock();
		if (countless > 0)
		{
			cout << "窗口" << i << " 卖出了 "<< countless-- << endl;
		}
		// mut.unlock();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
			
	}
}
int main6()
{
	vector<thread> vec;
	//unique_lock<mutex> locc(mut);
	//locc.unlock();
	for (int i = 0; i < 3; i++)
	{
		try {
			//unique_lock<mutex> locc(mut);

			//vec.push_back(thread(threadHandle1, i, move(locc)));
			Sleep(2);
		}
		catch (const std::exception& ex)
		{
			cout << "异常" << ex.what() << endl;
		}

	}
	for (auto &it : vec)
	{
		it.join();
	}
	return 0;

}