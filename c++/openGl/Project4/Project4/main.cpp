#include<iostream>
class data {
public:
	static int st;
	int member;
	data(int mem)
	{
		member = mem;
	}
};
int data::st = 10;
int main()
{
	data* ptr = new data(0);
	std::cout << sizeof(ptr);
	data da(11);
	// 指针访问静态成员变量
	std::cout << "对象指针访问静态变量:"<< ptr->st << std::endl;
	// 对象访问静态成员变量
	std::cout << "对象访问静态成员变量:" << da.st << std::endl;


}