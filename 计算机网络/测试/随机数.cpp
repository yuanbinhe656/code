#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned)time(NULL));
	int num[10];
	int max=0;
	for(int i=0;i<10;i++)
	{
		num[i]=rand()%100+100;
		if(max<num[i])
		{
			max=num[i];
		}
		
	}
	printf("最大值为%d\n",max);
	for(int i=0;i<10;i++)
	{
		printf("%d  ",num[i]);
	}
	return 0;
}
 
