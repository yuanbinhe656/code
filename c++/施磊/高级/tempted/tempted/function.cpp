#include <iostream>
using namespace std;

// ��ȫ���ػ���ģ���࣬�ڴ˻�����������
template<typename Fty>
class myfunction{};
// һ��������������function
template<typename R, typename A1>
class myfunction<R(A1)> {
public:
	using PFUNC = R(*)(A1); // ��������ΪA1������ֵΪR������
	myfunction(PFUNC pfunc):_pfunc(pfunc){}
	R operator() (A1 data)
	{
		return _pfunc(data);
	}
private:
	PFUNC _pfunc;
};
// �ɱ�β�����������function
template<typename R, typename... A1>
class myfunction<R(A1...)> {
public:
	using PFUNC = R(*)(A1...); // ��������ΪA1������ֵΪR������
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