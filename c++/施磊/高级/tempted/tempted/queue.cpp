#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

int cunt = 0;
mutex mutl;
condition_variable cv; // 线程间的互斥操作
class Queue {
public:
	void put(int val)
	{
		unique_lock<std::mutex> lck(mutl);
		while (!que.empty())
		{	
			cv.wait(lck);
		}

		que.push(val);
		cout << "生产者 生产：" << val << "号物品" << endl;
		cv.notify_all();
	}
	int get()
	{
		unique_lock<std::mutex> lck(mutl);
		while (que.empty())
		{
			cv.wait(lck);
		}
		int val = que.front();
		que.pop();
		cout << "消费者 消费：" << val << "号物品" << endl;
		cv.notify_all();
		return val;
	}
	bool empt()
	{
		return que.empty();
	}
private:
	queue<int> que;
};
void prduct(Queue *que,int &i)
{

	while (i++)
	{
		que->put(i);
		//this_thread::sleep_for(std::chrono::seconds(1));
	}
}
void consume(Queue *que, int &i)
{
	this_thread::sleep_for(std::chrono::seconds(1));
	while (1)
	{
		if (!que->empt())
		{
			int val = que->get();
		}
		
		
	}
}
int main7()
{
	Queue qu;
	thread t1(prduct, &qu, ref(cunt));
	thread t2(consume, &qu, ref(cunt));
	thread t3(prduct, &qu, ref(cunt));
	t1.join();
	t2.join();
	return 1;
}