#include<iostream>
#include<string>
using namespace std;
class Student;
class Print;

class Manager //��������
{
	int mNo; //�����߱��
	char mName[20]; //����������
public:
	int scoresAvg(Student& s)
	{
		int a = s.chengji[0] + s.chengji[1] + s.chengji[2];
	
		a = a / 3;
		
		return a;
	}
};
class Print
{
public:
	void printStudent(Student& s)
	{
		cout << "" << s.num<<endl;
		cout << "" << s.nanme << endl;
		cout << "" << s.nianji << endl;
		cout << "" << s.chengji[0] << endl;
		cout << "" << s.chengji[1] << endl;
		cout << "" << s.chengji[2] << endl;

	}
	
};
class Student {
public:
	Student(int nu, string nan, string nianj, int* a)
	{
		num = nu;
		nanme = nan;
		nianji = nianj;
		chengji[0] = *a;
		chengji[1] = *(a + 1);
		chengji[2] = *(a + 2);
		number++;
	}

	static int show()
	{
		return number;


	}
	friend  Print;
	friend  int Manager::scoresAvg(Student & s);

	~Student()
	{
		number--;
	}
private:

	int num;
	string nanme;
	string nianji;
	int chengji[3];
	static int number;
};
int Student::number = 0;
int main()
{
	
		//��5��ѧ������Ϣ
		int a1[3] = { 68,89,79 };
		int a[5][3] = { { 68,89,79 },{95, 90, 93},{80, 85, 92},{87, 93, 86},{97, 84, 74} };
		Student sis1 (0001,"����","Ƕ��ʽ���18 - 1",&a[0][0]);
		Student sis2(0002, "����", "Ƕ��ʽ���18 - 1", &a[1][0]);
		cout << "��ǰStudent���������" << Student::show()<<endl; //����Student�ľ�̬���������̬˽�б���
		Manager manager;
		cout << manager.scoresAvg(sis2) << endl; //���������2��ѧ����ƽ���ɼ�
		Print print;
		print.printStudent(sis2); //�����3��ѧ������Ϣ
		sis2.~Student();
		cout << "��ǰStudent���������" << Student::show()<<endl; //����Student�ľ�̬���������̬˽�б���
		return 0;

		


}