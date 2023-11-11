#include<stdio.h>
#define PI 3.14159
int main()
{
	double r;
	scanf("%lf", &r);
	double c, s;
	c = 2 * PI * r;
	s = PI * r * r;
	printf("%.2lf %.2lf",c,s );
	return 0;
}

