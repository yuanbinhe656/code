#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class GoodClass
{
private:
	char Name[10];
	char Num[10];
	int Price;
public:
	GoodClass(char name[10], char num[10], int price)
	{
		Name[10] = name[10];
		Num[10] = num[10];
		Price = price;
	}


};

int main()
{
	GoodClass lin[1];
	lin[0] = GoodClass("¹«Ö÷È¹", "A161", 300);
	lin[0] = GoodClass("µöÓã¸Í", "H380", 200);
	lin[0] = GoodClass("Î÷Ñó¾µ", "L901", 500);
	ofstream out("good.dat", ios::binary);
	if (!out)
	{
		cout << "can not open the file.\n"
			abort();
	}
	for (int i = 0; i < 2; i++)
	{
		out.write((char*)&lin[i], sizeof(GoodClass));
	}
	out.close();
	return 0;
}