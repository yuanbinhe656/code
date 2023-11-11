#include <iostream>
using namespace std;
class Date {
public :
	Date(int x1, int y1, int z1);
	void displayDate();
private:
	int x;
	int y;
	int z;
};
Date::Date(int x1, int y1, int z1)
{
	x = x1;
	if (0 < y1 && y1< 13)
		y = y1;
	else y = 1;
	z = z1;
}
   void Date::displayDate()
{
	cout << x << "-" << y << "-" << z;
}
int main() {
	int y, m, d;
	cin >> y >> m >> d;
	
	Date one(y, m, d);
	one.displayDate();
	return 0;
}