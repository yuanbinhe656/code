#include<iostream>
using namespace std;
class data{
	public:
		static int st;
		int member;
		data(int mem)
		{
			member = mem;
		}
};
int asa:: st =10;
int main()
{
	asa *ptr = new asa(0);
	// ָ����ʾ�̬��Ա���� 
	cout << ptr->st;
	
}
