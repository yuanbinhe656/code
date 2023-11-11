#include<stdio.h>
#include<stdlib.h>

//希尔排序，一开始通过一组两个元素进行比较，再成倍增加，最终达到其长度个元素比较
//size 2,4,6,8 gap 为组数 
//特点：在其所占空间为n，不占额外空间 
void xier(int * num,int size)
{
	int gap = size / 2; 
	int temp ;
	while(gap > 0 )  //当gap为0时，代表其组数 已经经过了组数为1的排序，此时已经完成排序 
	{
		for(int i = gap;i < size;i++)
			{
				temp = num[i];
				for (int j = i - gap;j >= 0&& num[j] > temp ;j = j -gap )//插入排序，每次到一组新的元素，其与前面的元素进行大小比对 
				{
					num[j+gap] = num[j];
					num[j] = temp;
					
				}
			}
			gap = gap / 2;
	}
}
int main()
{
	int num[10] = {1,3,4,-1,45,6,2,46,3,3};
	xier(num,10);
	for(int i = 0;i<10;i++)
	{
		printf("num[%d]:%d\n",i,num[i]);
		
	}
	return 0;
 } 
