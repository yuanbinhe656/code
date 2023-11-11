#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
    Student(int sNo1, string sname1, string sClass1, int* scores1)
    {
        sNo = sNo1;
        sName = sname1;
        sClass = sClass1;
        scores[0] = scores1[0];
        scores[1] = scores1[1];
        scores[2] = scores1[2];

        cout << "构造函数使用中....." << endl;
    }
    Student(int sNo1)
    {
        sNo = sNo1;


        cout << "构造函数使用中....." << endl;
    }
    Student(const Student& p)
    {
        sNo = p.sNo;
        sName = p.sName;
        sClass = p.sClass;
        scores[0] = p.scores[0];
        scores[1] = p.scores[1];
        scores[2] = p.scores[2];
        cout << "特殊的构造函数之拷贝构造函数使用中..." << endl;
    }
    Student()
    {
        sNo = 0;
        sName = "";
        sClass = "";
        scores[3] = 0;

    }
    ~Student()
    {
        cout << "析构函数使用中...." << endl;
    }
    void Student_show()
    {
        cout << sNo << "\t";
        cout << sName << "\t";
        cout << sClass << "\t";
        cout << scores[0] << "\t";
        cout << scores[1] << "\t";
        cout << scores[2] << "\t" << endl;

    }

private:
    int sNo;
    string sName;
    string sClass;
    int scores[3];


};
int main()
{

    int a[3] = { 1,2,3 };

    Student s1(20, "张三", "三年二班", a);
    Student s2(s1);
    s1.Student_show();
    s2.Student_show();
    return 0;
}
