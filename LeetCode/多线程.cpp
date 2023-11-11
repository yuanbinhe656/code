#include <iostream>
#include <thread>
using namespace std;
void ThreadFunc(int a) {
	cout << "Thread1" <<" " << a << endl;
}

void func(double i){
	cout << i / 2 << endl;
}
class TOB {
public:
	void operator()(){
		cout << "Thread3" << endl;
	}
};
int main(){

	//函数指针移动赋值给t1
	thread t1;
	t1 = thread(ThreadFunc, 998);

	//线程函数为lambda表达式
	thread t2([]() {
		cout << "Thread2" << endl;
		});

	//线程函数为仿函数对象
	TOB tb;
	thread t3(tb);

	//线程函数为包装器
	function<void(double)> f1 = func;
	thread t4(f1, 999);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}

