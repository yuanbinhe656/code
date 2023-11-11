#include<iostream>
using namespace std;
const  int N = 7;
class stock
{
public:
	static int count;
	stock(int n, float max, float min, float begin, float end);
	stock(const stock& p);
	stock();
	~stock();
	void stock_set();
	void stock_copy(stock &);
	void stock_show();
	float stock_End();
	friend bool stock_compare(stock s);
private:
	int number;
	float Max, Min, Begin, End;

};
int stock::count = 0;
stock::stock(int n, float max, float min, float begin, float end)
{
	number = n;
	Max = max;
	Min = min;
	Begin = begin;
	End = end;
	count = count + 1;
}
stock::stock()
{
	number = 0;
	Max = 0;
	Min = 0;
	Begin = 0;
	End = 0;
}
stock::stock(const stock& p)
{
		number = p.number;
		Max = p.Max;
		Min = p.Min;
		Begin = p.Begin;
		End = p.End;
		
	}
stock::~stock()
{
	
}
void stock::stock_show()
{
	cout << number << "\t";
	cout << Max << "\t";
	cout << Min << "\t";
	cout << Begin << "\t";
	cout << End << "\t" << endl;
}
float stock::stock_End()
{
	return(End);
}
void stock::stock_copy(stock& p)
{
	this->Begin = p.Begin;
	this->End = p.End;
	this->Max = p.Max;
	this->Min = p.Min;
	cout << this->number << endl;
}
 bool stock_compare(stock s)
{
	if (s.Begin<s.End)
	{
		return true;
	}
	else
		return false;
}
 void stock::stock_set()
 {
	 cout << "number:" << endl;
	 cin >> number;
	 cout << "Begin:" << endl;
	 cin >> Begin;
	 cout << "End:" << endl;
	 cin >> End;
	 cout << "Max:" << endl;
	 cin >> Max;
	 cout << "Min:" << endl;
	 cin >> Min;
 }
 int main()
 {
	 int i;
	 stock s1[100] ;
	  
	
	 stock* p;
	 for (i = 0, p = s1;i<N;p++, i++)
	 {
		 p->stock_set();
	 }
	 for (i = 0, p = s1; i < N; p++, i++)
	 {
		p->stock_show();
	 }
	 for (i = 0, p = s1; i < N; i++, p++)
	 {
		 cout << "第" << i + 1 << "天的涨幅为" << (p->stock_End() - (p - 1)->stock_End()) / (p - 1)->stock_End() * 100 << "%" << endl;
	 }
	 return 0;
 }