#include<stdio.h>
#include<stdlib.h>
int huiwen(int m,int k)
{
	int w,t;
	while(m)
	{
		w=m%10;
		
		if(w==k)
		{
			t=m;
			int ws;
			int as[100];
			int h=0;
			as[h]=w;
			h++;
			while(t)
			{
				t=t/10;
				ws=t%10;
				if(ws==k&&h==1)
				{
					return 1;
				}
				else if(h!=1&&as[h-2]==ws)
				{
											t=t/10;
									ws=t%10;
					h=h-2;
					while(!h)
					{
			

						if(as[h-1]==ws)
						{
						 h=h-1;
						}
						else
						{
							break;
						}

					}
					if(h==0)
					{
						return 1;
					}
					
				}
				else {
					as[h]=ws;
					h++;
				}
				
			}
		}
		m=m/10;
	}
	return 0;
}
int main()
{
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	int array[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(huiwen(array[i],k))
		{
			j++;
			printf("%d\n",array[i]);
			
		}
		
	}
	if(j==0)
	{
		printf("NO Answer\n");
	}
	return 0;
}
