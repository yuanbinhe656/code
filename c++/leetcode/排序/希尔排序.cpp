#include<stdio.h>
#include<stdlib.h>

//ϣ������һ��ʼͨ��һ������Ԫ�ؽ��бȽϣ��ٳɱ����ӣ����մﵽ�䳤�ȸ�Ԫ�رȽ�
//size 2,4,6,8 gap Ϊ���� 
//�ص㣺������ռ�ռ�Ϊn����ռ����ռ� 
void xier(int * num,int size)
{
	int gap = size / 2; 
	int temp ;
	while(gap > 0 )  //��gapΪ0ʱ������������ �Ѿ�����������Ϊ1�����򣬴�ʱ�Ѿ�������� 
	{
		for(int i = gap;i < size;i++)
			{
				temp = num[i];
				for (int j = i - gap;j >= 0&& num[j] > temp ;j = j -gap )//��������ÿ�ε�һ���µ�Ԫ�أ�����ǰ���Ԫ�ؽ��д�С�ȶ� 
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
