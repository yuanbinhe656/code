#include <iostream>
using namespace std;
class test {

public:
	test(int i) :data(i)
	{
		cout << "test(int)";
	}
	test(const test& t)
	{
		data = t.data;
		cout << "test(&t)";
	}
	test& operator=(const test t)
	{
		cout << "operator";
		data = t.data;
		return *this;
	}
	test()
	{
		cout << "test()";
	}
	test(test&& t)
	{
		data = t.data;
		cout << "testt(&&)";
	}
	~test()
	{
		cout << "~test";
	}
	int getdata()
	{
		return data;
	}

	int data;
};
test CreatTest(test &t)
{
	int val = t.getdata();
	//test temp(val);
	return test(val);

}
int main()
{
	/*	int i = 10;
		test t1(i);

		test t2 = test(i);
		test t3 = t2;
		test t4 = 30;
		const	test &ref = test(10);
		t1 = t2;
		*/
	test t(2);
	test t1(3);
	test &&t2 = CreatTest(t);
	cout << t2.getdata();
	t2.data = 5;
	cout << t2.getdata();
	int&& rel = 9;
	cout << endl;
	cout << rel ;
	rel++;
	cout << rel;
	return 0;
}