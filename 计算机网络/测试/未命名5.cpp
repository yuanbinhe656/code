#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		num[i]=m;
	}
	for(int i=n-1;i>-1;i--)

		{
			if(num[i]%2==0)
			{
				printf("%d ",num[i]);
			}
		}
	return 0;
}

