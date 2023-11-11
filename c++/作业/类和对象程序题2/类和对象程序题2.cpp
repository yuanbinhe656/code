#include <iostream>
using namespace std;
class Student {
public:
    Student (int x1, int  y1)
    {
        x = x1;
        y = y1;
    }
    Student(const Student& p)
    {
    x = p.x;
    y = p.y;
}
    void setName(int x2)
    {
        x = x2;
   }
    void print_info()
    {
        cout << "name:" << x << ", score:" << y<<endl;
     }
private:
    int x;
    int y;

};
int main()
{
    Student stu1(1, 98);
    Student stu2(stu1);
    stu2.setName(2);
    stu1.print_info();
    stu2.print_info();
    return 0;
}