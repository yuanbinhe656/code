#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cassert>
#include <functional>
using namespace std;

using func = void(*)(int s, string y);
class Base {
public:
	int id;
	string name;
	Base(int ID, string Name) :id(ID), name(Name) {

	}
	virtual void say(string s)
	{
		cout << s << endl;

	}
};
class B :public Base {
public:
	Base::Base;
	Base::say;
	void say(int s)
	{
		cout << "B:" << "int" << endl;
		cout << s << endl;

	}
	void build(string s)
	{
		cout << s << endl;
	}
	static void call(int s, string name)
	{
		cout << "sattic   " << s << "  " << name << endl;
	}
	operator func()
	{
		return call;
	}

};

int main()
{
	int select = 5;
	switch (select)
	{
	case 1: {
		using ptr = void(B::*)(int);
		ptr p1 = &B::say;
		using ptr1 = int Base::*;
		ptr1 p2 = &Base::id;
		using ptr2 = void(Base::*)(string);
		ptr2 ptr3 = &Base::say;
		string s{ "hello" };
		int a = 2;
		B t{ 1, s };
		t(a, s);
		(t.*p1)(a);
		t.*p2 = 6;
		cout << t.id << endl;
		(t.*ptr3)(s);
		function<void(int s, string name)> func_c = B::call;
		break;
	}
	case 2: {
		string s = " hello";
		bind(B::call, 2,placeholders::_2)("jaha","sun");
		using ptr1 = void(B::*)(int);
		ptr1  pr1 = &B::say;
		using ptr2 = void(B::*)(string);
		ptr2 pr2 = &B::say;
		B t{ 1, s };
		auto f1 = bind(pr1, &t, 3);
		function<void()> fn1 = bind(pr1, &t, 3);
		auto f2 = bind(pr2, &t, "haha");
		auto f3 = bind(&B::build, &t, "sunzi");
		f1();
		fn1();
		f2();
		f3();
		break;
	}
	case 3: {
		int a = 1;
		int b = 2;
		[=]()mutable {
			a = a + b;
			cout << a << endl;
			return a + b;
		}();
		cout << a << endl;
		break;
	}
	case 4: {
		int a = 9;
		int c = 8;
		 //int&const b = a;
		 const int&  b = c;
		 int&& d = 9;
		  auto &&s =  d;
		//b = 3;
		cout << b << endl;
		break;
	}
	case 5: {
		shared_ptr<int> nptr1(new int[10](), [](int* nptr1) {
			cout << "del" << endl;
			delete []nptr1;
			});
		shared_ptr<int> nptr2(std::move(nptr1));
		cout << nptr2.use_count() << endl;
		shared_ptr<int> nptr3(nptr1);
		cout << nptr3.use_count() << endl;
		shared_ptr<int> nptr4=nptr2;
		cout << nptr4.use_count() << endl;
		int* ptr = nptr4.get();
		cout << *ptr << endl;
		*ptr = 1;
		weak_ptr<int> wp = nptr2;
		cout << wp.use_count() << endl;
		nptr1 = wp.lock();
		
		cout << wp.use_count() << endl;
		cout << *nptr1 << endl;
		
	}



	}
	return 0;
}
