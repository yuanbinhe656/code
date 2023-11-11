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
	mycout << "\t 工号\t姓名\t性别\t收入"<<endl;
	mycout << "\t" << number << "\t" << name << "\t" << sex << "\t" << salary << endl;
	mycout << "\t+-----------------------------+" << endl;

}
ostream& operator<<(ostream& os, Person& temp)
{
	os << "\t 工号\t姓名\t性别\t收入" <<endl;
	os << "\t" << temp.number << "\t" << temp.name << "\t" << temp.sex << "\t" << temp.salary << endl;
	os << "\t+-----------------------------+" << endl;
	return os;
}
void  Person::input()
{
	cout << "工号：";
	cin >> number;
	cout << "姓名:";
	cin >> name;
	cout << "性别:";
	cin >> sex;
}
void Teacher::input()
{
	Person::input();
	cout << "请输入课时：";cin>> teaching_hours;
	cout << "请输入职称前对应的序号" << endl;
	cout << "1-----------教授" << endl;
	cout << "2----------副教授" << endl;
	cout << "3-----------讲师" << endl;
	cout << "4-----------助教" << endl;
	cout << "输入序号：" << endl;
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
	cout << "当月工作时数"; cin >> workingHours;
}
void Temporary_workers::Pay()
{
	salary = workingHours * hourlyPay;
}
void Staff::input()
{
	Person::input();
	cout << "1-----------院级" << endl;
	cout << "2-----------处级" << endl;
	cout << "3-----------科级" << endl;
	cout << "4-----------一般工作人员" << endl;
	cout << "请输入职位前的序号：" << endl; cin >> position;

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
	cout << "1-----------院级" << endl;
	cout << "2-----------处级" << endl;
	cout << "3-----------科级" << endl;
	cout << "4-----------一般工作人员" << endl;
	cout << "请输入职位前的序号：" << endl; cin >> position;

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
	cout << "*********欢迎使用工资管理系统*********" << endl;
	cout << "***        1、教师          ***" << endl;
	cout << "***        2、一般职工      ***" << endl;
	cout << "***        3、临时工        ***" << endl;
	cout << "***        4、双肩挑教师    ***" << endl;
	cout << "***        0、退出          ***" << endl;
	cout << "************************************"<<endl;
		cout << "请选择："<<endl ;
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
			
			cout << "已关闭系统" << endl;
			return 0;
		}
		cout << "清选择是否继续，继续请输入1，退出请输入0" << endl;
		cin >> a;
	}
	return 0;
}