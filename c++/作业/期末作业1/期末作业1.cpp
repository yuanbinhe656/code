#include<iostream>
using namespace std;
template<typename swpst>
void myswap(swpst &i, swpst &j)
{
	swpst a;
	a = i;
	i = j;
	j = a;

}
int main() {

	int x = 1, y = 2;

	cout << x << ", " << y << endl;

	myswap(x, y);

	cout << x << ", " << y << endl;
	string x1 = "c++", y1 = "oop";

	cout << x1 << ", " << y1 << endl;

	myswap(x1, y1);

	cout << x1 << ", " << y1 << endl;



	return 0;

}
