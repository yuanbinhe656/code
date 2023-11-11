#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class GoodClass
{
private:
	string Name;
	string Num;
	int Price;
public:
	GoodClass(string name, string num, int price)
	{
		Name = name;
		Num = num;
		Price = price;
	}
	GoodClass()
	{
		Name = "";
		Num = "";
		Price = 0;
	}
	void decshow()
	{	

		cout.width(20);
		cout.setf(ios::left);
		cout.fill(' ');
		cout << Name;
		cout.width(20);
		cout.setf(ios::left);
		cout.fill(' ');
		cout << Num;
		cout << dec << Price << endl;
	}
	void hexshow()
	{
		cout.width(20);
		cout.setf(ios::left);
		cout.fill(' ');
		cout << Name;
		cout.width(20);
		cout.setf(ios::left);
		cout.fill(' ');
		cout << Num;
		cout << hex << Price << endl;
	}
	void octshow()
	{
		cout.width(20);
		cout.setf(ios::left);
		cout.fill(' ');
		cout << Name;
		cout.width(20);
		cout.setf(ios::left);
		cout.fill(' ');
		cout<< Num;
		cout<<oct << Price << endl;
	}
	~GoodClass()
	{}
};

int main()
{
	GoodClass lin[3];
	lin[0]=GoodClass("����ȹ", "A161", 300);
	lin[1] = GoodClass("�����", "H380", 200);
	lin[2] = GoodClass("����", "L901", 500);
	
	GoodClass list[3];

	ofstream out("good.dat", ios::binary);
	if (!out)
	{
		cout << "can not open the file." << endl;
			abort();
	}
	string text = "I am a good student./n";
	string index = "��Ʒ����\t��Ʒ���\t��Ʒ�۸�\t";
	string text1="";
	string index1 = "";
	out.write((char*)&text, sizeof(text));
	out.write((char*)&index, sizeof(index));
	out.write((char*)lin, 4 * sizeof(lin[0]));
	out.close();
	ifstream in("good.dat", ios::binary);
	in.read((char*)&text1, sizeof(text));
	in.read((char*)&index1, sizeof(index));
	in.read((char*)list,4*sizeof(GoodClass));
	cout << text1 << endl;
	cout << "�˽��ƽ������" << endl;
	cout << index1 << endl;
	for (int i = 0; i < 3; i++)
	{
		list[i].octshow();

	}
	cout << endl;
	cout << "ʮ���ƽ������" << endl;
	cout << index1 << endl;
	for (int i = 0; i < 3; i++)
	{
		list[i].decshow();

	}
	cout << endl;
	cout << "ʮ�����ƽ������" << endl;
	cout << index1 << endl;
	for (int i = 0; i < 3; i++)
	{
		list[i].hexshow();

	}
	cout << endl;
	system("pause");
	return 0;
}