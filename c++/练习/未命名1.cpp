#include <iostream>
using namespace std;
char * get()
{
	char *s = "hh";
	return s;
}
int main()
{
	char *s = get();
	printf("%s",s);
	return 0; 
}
