#include <iostream>
using namespace std;
class Student

{
private:
	char name[5];

	int* score;

public:

	Student(const char* p, int c)
	{
		score = new int(c);
		memcpy(name, p, strlen(p) + 1);

	}
	Student(const Student& p)
	{
		score = new int(*p.score);
		memcpy(name, p.name, strlen(p.name) + 1);
     }

	~Student()

	{

		if (score != NULL)

		{

			delete score;
			score = NULL;
		}
		


	}

	void print_info()

	{

		cout << "name:" << name;

		cout << ", score:" << *score << endl;



	}



	void setName(const char* p)

	{

		memcpy(name, p, strlen(p) + 1);

	}



};
int main()
{
	Student stu1("John", 98);
	Student stu2(stu1);
	stu2.setName("Tom");
	stu1.print_info();
	stu2.print_info();
	return 0;
}
