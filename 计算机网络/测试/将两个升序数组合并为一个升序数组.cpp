#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int arr_size);          /* 打印数组,细节不表 */
void merge(int* a, int m, int* b, int n, int* c); /* 合并a和b为c */

int main(int argc, char const *argv[])
{
    int m, n, i;
    int *a, *b, *c;

    scanf("%d", &m);
    a = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n);
    b = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    c = (int*)malloc((m + n) * sizeof(int));
    merge(a, m, b, n, c);
    printArray(c, m + n);

    return 0;
}
void printArray(int* arr, int arr_size)
{
	for(int i=0;i<arr_size;i++)
	{
		printf("%d ",*(arr+i));
	}
}           /* 打印数组,细节不表 */
void merge(int* a, int m, int* b, int n, int* c) /* 合并a和b为c */
{
	int i=0,j=0; 
	for (;i+j<m+n;)
	{
		if(i==m)
		{
			for(;j<n;j++)
			{
				*(c+i+j)=*(b+j);
			}
			
		}
		else if(j==n)
		{
			for(;i<m;i++)
			{
				*(c+i+j)=*(a+i);
			}
		}
		else if(*(a+i)>*(b+j))
		{
		
				*(c+i+j)=*(b+j);
			
				j++;
		
			
		}
		else
		{
			*(c+i+j)=*(a+i);
			i++;
		}
	}
} 
