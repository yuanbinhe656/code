#include<stdio.h>
int main()
{
	int n,m,j=0;
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		if(m%2==0)
		{
			num[j++]=m;
			
		}
		
	}
	for(int i=j-1;i>-1;i--)

		{
			if(num[i]%2==0)
			{
				printf("%d ",num[i]);
			}
		}
	return 0;
}

