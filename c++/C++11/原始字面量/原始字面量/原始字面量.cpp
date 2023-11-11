#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
struct A {
	static const int i0;//正确
	static const int i1 = 2;//正确

	static const std::string str2;//正确
	//static const std::string str3 = "你太baby辣";//error:只允许static const int有类内初始值
	//static const float f0 = 3f;//error:只允许static const int 类型在类内定义

	static constexpr int i2 = 4;//正确，static constexpr必须是类内初始值
	static constexpr float i3 = 3.14;//error
	//static constexpr std::string str0;//error:没有类内初始值
	//static constexpr string &&str1 = "c++是男人的浪漫";//正确
};
//constexpr float A::i3 ;
struct Test {
	static const int a = 100;

};

void min(int const* a) {
	cout << *a << endl;
};

//const int Test::a;
template<typename T>
class set {
	T s;

};

int excepDiv(int x, int y) throw() {
	if (y == 0)
	{
		string s("cuwu1");
		int i = 1;
		throw("cuowu");
	}
	return x / y;
}
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
	int num = 8;
	switch (num)
	{
	case 1:{  // 字符原字面量
			string s = "E:\\BaiduSyncdisk笔记\c++\\C++11\\5.多线程";
			cout << s << endl;
			string s1 = R"me(E:\BaiduSyncdisk笔记\\计算机\c++\C++11\5.多线程)me";
			cout << s1 << endl;
		}
	case 2: { //long long
		long long  s1 = 12345678912345678911LL;
		int s2 = 12345678912345678911;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << LLONG_MIN << endl;
		cout << LLONG_MAX << endl;
		cout << INT64_MAX << endl;
		cout << INT16_MAX << endl;

	}
	case 3: {
		const int * s = &A::i1;
		cout << *s << endl;
		min(&(Test::a));
	}
	case 4: {
		class A {
			//int s = 0;
		public:
			virtual void set()
			{
				cout << "A" << endl;
			}
		};
		class B  :public A {
			 void  set()
			{
				cout << "B" << endl;
			}
		};
		class C :public B {
			void set()
			{
				cout << "C" << endl;
			}
		};
		A* base = new C();
		base->set();
		cout << sizeof(long long*) << endl;
		cout << sizeof(int) << endl;
		break;
	}
	case 5:{
		int s = 8;
		assert(s < 6);
		static_assert(sizeof(int) == 4, "错误, 不是32位平台...");  
		cout << "64bit Linux 指针大小: " << sizeof(char*) << endl;   
		cout << "64bit Linux long 大小: " << sizeof(long) << endl;
	}
	case 6: {
		try {
			int x = excepDiv(3, 0);
		}
		catch (int e)
		{
			cout << "catch except: " << e << endl;
		}
		catch (string s)
		{
			cout << "catch except: " << s << endl;
		}
	}
	case 7: {
		int i = 10;
		int j = 20;
		const auto  s = &i;
		*s = 10;
		const auto * const m = &i;
		cout << i << endl;
	} 
	case 8: {

	
		using ptr = void(B::*)(int);
		ptr p1 = &B::say;
		using ptr1 = int Base::*;
		ptr1 p2 =  &Base::id;
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
		
	}
	}

	return 0;
}