#include<stdio.h>
#include<math.h>

int main()
{
	int m,n,s;
	double t;
	scanf("%d %d",&m,&n);
	for (int i=m;i <= n; i++) {
		s = i;
		t = log(s);
		printf("%4d %8.4lf\n", s,t);

	}
	return 0;
}

