#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void threadHandle1()
{
	cout << "heelo" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::this_thread::yield();
	cout << std::this_thread::get_id() << endl;
	std::this_thread::sleep_until(std::chrono::system_clock::now()+  std::chrono::seconds(5));
	cout << "Íê³É" << endl;

}
int main4()
{
	thread t1(threadHandle1);
	cout << t1.get_id();
	t1.join();
	cout << "haha" << endl;
	try {
		t1.detach();
	}
	catch (...)
	{
		cout << "erro";
	}
	Sleep(2);
	return 0;
}