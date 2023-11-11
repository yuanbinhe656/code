#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>
#include<time.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void PrintArray(int* a, int n)
{
	int i = 0;
	for (; i < n - 1; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("%d\n", a[i]);
}

void InsertSort(int* a, int n)
{
	printf("您已进入直接插入排序\n");
	printf("排序前数组：");
	PrintArray(a, n);
	assert(a);
	int i, j;
	for (i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}
		printf("第%02d趟：", i);
		PrintArray(a, n);
	}
}
void shellInsert(int array[], int n)
{
	int t = (int)(log(n + 1) / log(2));
	int i, dk;
	for (i = 1; i <= t; i++)
	{
		dk = (int)(pow(2, t - i + 1) - 1);
		
		int k, j, temp;
		for (k = dk; k < n; k++)
		{
			temp = array[k];
			for (j = k - dk; (j >= k % dk) && array[j] > temp; j -= dk)
				array[j + dk] = array[j];
			if (j != k - dk)
				array[j + dk] = temp;
		}
	}
}
void ShellSort(int* a, int n)
{
	printf("您已进入希尔排序\n");
	printf("排序前数组：");
	PrintArray(a, n);
	assert(a);
	int gap = n;
	int i, j, k = 1;
	while (gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			int temp = a[i];
			for (j = i - gap; j >= 0 && a[j] > temp; j -= gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = temp;
		}
		printf("第%02d趟：", k++);
		PrintArray(a, n);
	}
}

void BubbleSort(int* a, int n)
{
	printf("您已进入冒泡排序\n");
	printf("排序前数组：");
	PrintArray(a, n);
	assert(a);

	int i, j = n, k = 1;
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (i = 1; i < j; i++)
		{
			if (a[i] < a[i - 1])
			{
				swap(&a[i], &a[i - 1]);
				flag = 1;
			}	
		}
		j--;
		if (flag)
		{
			printf("第%02d趟：", k++);
			PrintArray(a, n);
		}
	}
}
void SelectionSort(int* a, int n)
{
	printf("您已进入简单选择排序\n");
	printf("排序前数组：");
	PrintArray(a, n);
	assert(a);

	int min, i, j;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(&a[i], &a[min]);
		printf("第%02d趟：", i+1);
		PrintArray(a, n);
	}
}

void QuickSort(int* a, int left, int right, int n)
{
	
	
	
	assert(a);

	if (left < right)
	{
		static int k = 1;
		int i = left, j = right, x = a[left];
		while (i < j)
		{
			while (i < j && a[j] >= x) 
				j--;
			if (i < j)
				a[i++] = a[j];

			while (i < j && a[i] < x) 
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		if(k==1)
	   {
     	printf("您已进入快速排序排序\n");
    	printf("排序前数组：");
    	PrintArray(a, n);
    	}
		printf("第%02d趟：", k++);
		PrintArray(a, n);
		QuickSort(a, left, i - 1, n); 
		QuickSort(a, i + 1, right, n);
		
	}
}
void MergeSort(int*a, int left, int right, int* temp)
{
	static int k=1;
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	int begin1, begin2, end1, end2;
	int i = 0;
	if(k==1)
	{
	printf("您已进入归并排序\n");
	printf("排序前数组：");
	PrintArray(a, right+1);
	}
    printf("第%02d趟：", k++);
	PrintArray(a, right+1);
	MergeSort(a, left, mid, temp);
	MergeSort(a, mid + 1, right, temp);

	begin1 = left;
	end1 = mid;
	begin2 = mid + 1;
	end2 = right;
	i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
		{
			temp[i++] = a[begin2++];
		}
		else
		{
			temp[i++] = a[begin1++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	
	for (i--; i >= left; i--)
	{
		a[i] = temp[i];
		
	}
}
void table()
{
	printf("请选择对该组数据进行排序的方法:\n");
	printf("1.直接插入排序\n");
	printf("2.希尔排序\n");
	printf("3.冒泡排序\n");
	printf("4.快速排序排序\n");
	printf("5.简单选择排序\n");
	printf("6.归并排序\n");
	printf("0.退出\n");
}
int main()
{
	srand((unsigned)time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 100;
	int n = sizeof(a) / sizeof(a[0]);
	int* temp = (int*)malloc(sizeof(int)*n);
	int x = 0;
	table();
	scanf("%d", &x);
	switch (x)
	{
	case 1:
		InsertSort(a, n);
		break;
	case 2:
		
		ShellSort(a, n);
		break;
	case 3:
		BubbleSort(a, n);
		break;
	case 4:
		QuickSort(a, 0, n - 1, n);
		break;
	case 5:
		SelectionSort(a, n);
		break;
	case 6:
		MergeSort(a, 0, n-1, temp);
		break;
	case 0:
		break;
	}
	printf("排序后数组：");
	PrintArray(a, n);
	return 0;
}

