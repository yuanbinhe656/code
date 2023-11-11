#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Person
{
public:
	friend ostream& operator<<(ostream&, Person&);
	void input();
	void save();
protected:
	int number;
	string name;
	string sex;
	double salary;
};
class Teacher :public virtual Person
{
public:
	void input();
	void Pay();
protected:
	int teaching_hours;
	double  title;
};
class Temporary_workers :public virtual Person
{
public:
	Temporary_workers() :hourlyPay(30) {}
	void input();
	void Pay();
private:
	double hourlyPay;
	int workingHours;
};
class Staff :public virtual Person
{
public:
	Staff() {}
	void input();
	void Pay();
protected:
	double position;

};
class Staff_Teacher :public Staff, public Teacher
{
public:
	Staff_Teacher() {}
	void input();
	void Pay();
};
void Person::save()
{
	ofstream mycout("result.txt", ios::app);
	mycout << "\t ����\t����\t�Ա�\t����"<<endl;
	mycout << "\t" << number << "\t" << name << "\t" << sex << "\t" << salary << endl;
	mycout << "\t+-----------------------------+" << endl;

}
ostream& operator<<(ostream& os, Person& temp)
{
	os << "\t ����\t����\t�Ա�\t����" <<endl;
	os << "\t" << temp.number << "\t" << temp.name << "\t" << temp.sex << "\t" << temp.salary << endl;
	os << "\t+-----------------------------+" << endl;
	return os;
}
void  Person::input()
{
	cout << "���ţ�";
	cin >> number;
	cout << "����:";
	cin >> name;
	cout << "�Ա�:";
	cin >> sex;
}
void Teacher::input()
{
	Person::input();
	cout << "�������ʱ��";cin>> teaching_hours;
	cout << "������ְ��ǰ��Ӧ�����" << endl;
	cout << "1-----------����" << endl;
	cout << "2----------������" << endl;
	cout << "3-----------��ʦ" << endl;
	cout << "4-----------����" << endl;
	cout << "������ţ�" << endl;
	cin >> title;

}
void Teacher::Pay()
{
	if (title == 1)
		salary = teaching_hours * 150 + 5000;
	else if (title == 2)
		salary = teaching_hours * 120 + 5000;
	else if (title == 3)
		salary = teaching_hours * 100 + 5000;
	else
		salary = teaching_hours * 80 + 5000;
}
void Temporary_workers::input()
{
	cout << "���¹���ʱ��"; cin >> workingHours;
}
void Temporary_workers::Pay()
{
	salary = workingHours * hourlyPay;
}
void Staff::input()
{
	Person::input();
	cout << "1-----------Ժ��" << endl;
	cout << "2-----------����" << endl;
	cout << "3-----------�Ƽ�" << endl;
	cout << "4-----------һ�㹤����Ա" << endl;
	cout << "������ְλǰ����ţ�" << endl; cin >> position;

}
void Staff::Pay()
{
	if (position == 1)
		salary = 8000;
	else if (position == 2)
		salary = 6900;
	else if (position == 3)
		salary = 6600;
	else
		salary = 5000;
}
void Staff_Teacher::input()
{
	Teacher::input();
	cout << "1-----------Ժ��" << endl;
	cout << "2-----------����" << endl;
	cout << "3-----------�Ƽ�" << endl;
	cout << "4-----------һ�㹤����Ա" << endl;
	cout << "������ְλǰ����ţ�" << endl; cin >> position;

}
void Staff_Teacher::Pay()
{
	Staff::Pay();
	if (title == 1)
		salary = teaching_hours * 1.5 + 5000 + salary;
	else if (title == 2)
		salary = teaching_hours * 1.2 + 4000 + salary;
	else if (title == 3)
		salary = teaching_hours * 1.2 + 3000 + salary;
	else
		salary = teaching_hours * 1.2 + 2000 + salary;
	

}
void menu()
{
	system("cls");
	cout << "*********��ӭʹ�ù��ʹ���ϵͳ*********" << endl;
	cout << "***        1����ʦ          ***" << endl;
	cout << "***        2��һ��ְ��      ***" << endl;
	cout << "***        3����ʱ��        ***" << endl;
	cout << "***        4��˫������ʦ    ***" << endl;
	cout << "***        0���˳�          ***" << endl;
	cout << "************************************"<<endl;
		cout << "��ѡ��"<<endl ;
}
int main()
{


	int a = 1;
	while (a)
	{
		int i;
		menu();
		cin >> i;
		
		switch (i)
		{
		case 1:
			Teacher * teacherptr;
			teacherptr = new Teacher;
			teacherptr->input();
			teacherptr->Pay();
			teacherptr->save();
			cout << *teacherptr;
			delete teacherptr;
			
			break;
		case 2:
			Staff * staffptr;
			staffptr = new Staff;
			staffptr->input();
			staffptr->Pay();
			
			cout << *staffptr;
			
			staffptr->save();
			delete staffptr;
			break;
		case 3:
			Temporary_workers * temporary_workerptr;
			temporary_workerptr = new Temporary_workers;
			temporary_workerptr->input();
			temporary_workerptr->Pay();
			temporary_workerptr->save();
			cout << *temporary_workerptr;
		
			
			delete temporary_workerptr;
			break;
		case 4:
			Staff_Teacher * staff_teacherptr;
			staff_teacherptr = new Staff_Teacher;
			staff_teacherptr->input();
			staff_teacherptr->Pay();
			staff_teacherptr->save();
			cout << *staff_teacherptr;
			
			delete staff_teacherptr;
			break;
		case 0:
			
			cout << "�ѹر�ϵͳ" << endl;
			return 0;
		}
		cout << "��ѡ���Ƿ����������������1���˳�������0" << endl;
		cin >> a;
	}
	return 0;
}