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
	// ָ����ʾ�̬��Ա����
	std::cout << "����ָ����ʾ�̬����:"<< ptr->st << std::endl;
	// ������ʾ�̬��Ա����
	std::cout << "������ʾ�̬��Ա����:" << da.st << std::endl;


}