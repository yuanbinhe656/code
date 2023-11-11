#include <iostream>
using namespace std;

// 完全非特化的模板类，在此基础上特例化
template<typename Fty>
class myfunction{};
// 一个参数的特例化function
template<typename R, typename A1>
class myfunction<R(A1)> {
public:
	using PFUNC = R(*)(A1); // 创建参数为A1，返回值为R的类型
	myfunction(PFUNC pfunc):_pfunc(pfunc){}
	R operator() (A1 data)
	{
		return _pfunc(data);
	}
private:
	PFUNC _pfunc;
};
// 可变参参数的特例化function
template<typename R, typename... A1>
class myfunction<R(A1...)> {
public:
	using PFUNC = R(*)(A1...); // 创建参数为A1，返回值为R的类型
	myfunction(PFUNC pfunc) :_pfunc(pfunc) {}
	R operator() (A1... data)
	{
		return _pfunc(data...);
	}
private:
	PFUNC _pfunc;
};
int call(int data)
{
	cout << data;
	return 0;
}
int calls(int data,int num)
{
	cout << data << "," << num;
	return 0;
}
int main2()
{
	myfunction<int(int)> func(call);
	func(5);
	myfunction<int(int,int)> funcs(calls);
	funcs(5,1);
	return 0;
}