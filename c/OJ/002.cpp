#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
	int N,a[50][2000],min[50],max[50];
	int g,d,b,f;
	g=0;
	d=0;
	b=0;
	f=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&min[i],&max[i]);
	}
	for(int i=0;i<N;i++)
	{    if(max[i]-min[i]==0)
		a[i][0]=min[i];
		else
		for(int j=0;j<(max[i]-min[i]);j++)
		{
			a[i][j]=min[i]+j;
		}
	}
	for(int i=0;i<N;i++)
	{	if(max[i]-min[i]==0)
		{
		printf("%d\n",a[i][0]);
		continue;}
		else
		{
		for(int j=0;j<(max[i]-min[i]);j++)
		{
		for(int k=0;k<max[i]-min[i]-j;k++)	
		{   if(a[i][k]/10==0)
			{int d=a[i][k];
			int b=d;
			}
			else
			{
			while(a[i][k]/10!=0)
			{
				int b,c,d,e;
				e=0;
				d=0;
				b=a[i][k];
				c=a[i][k]%10;
				a[i][k]=a[i][k]/10;
				d=d+c*pow(10,e);
			}}
			if(a[i][k+1]==0)
			{
			 int g=a[i][k+1];
			 int e=g;
			}
			else
			{
			
			while(a[i][k+1]/10!=0)
			{
			int c,e;
				e=0;
				g=0;
				f=a[i][k+1];
				c=a[i][k+1]%10;
				a[i][k]=a[i][k+1]/10;
				g=g+c*pow(10,e);
			}}
			if(g<d)
			{
				a[i][k]=f;
				a[i][k+1]=b;
			}
		}
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<=max[i]-min[i];j++)
			{
				printf("%d ",a[i][j]);
				if(j==max[i]-min[i])
				printf("\n");
	
				
				
			}
		}
		
	}}

	system("pause");
	return 0;}
	

	

