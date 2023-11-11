#include<iostream>
using namespace std;
class stock
{
public:
	stock(int n, float max, float min, float begin, float end)
	{
		number = n;
		Max = max;
		Min = min;
		Begin = begin;
		End = end;
		cout << "构造函数使用中....." << endl;
	}
	stock(const stock& p)
	{
		number = p.number;
		Max = p.Max;
		Min = p.Min;
		Begin = p.Begin;
		End = p.End;
		cout << "特殊的构造函数之拷贝构造函数使用中..." << endl;
	}
	stock()
	{
		number = 0;
		Max = 0;
		Min = 0;
		Begin = 0;
		End = 0;
	}
	~stock()
	{
		cout << "析构函数使用中....BeyBey!"<< endl;
	}
	 void stock_show()
	{
		 cout << number <<"\t"  ;
		 cout << Max << "\t"  ;
		 cout << Min << "\t"  ;
		 cout << Begin << "\t" ;
		 cout << End << "\t" << endl;
	}
	 float stock_End()
	 {
		 return(End);
	 }
private:
	int number;
	float Max, Min, Begin, End;

};
int main()
{
	stock s1(1, 4.18, 4.00, 4.05, 4.09);
	stock s2(2, 4.41, 4.03, 4.04, 4.40);
	cout <<"\n" << (s2.stock_End() - s1.stock_End()) / s2.stock_End() * 100 << "%" << endl;
	stock s3(3, 4.45, 4.05, 4.06, 4.34);
	stock s4(s3);
	return 0;
}