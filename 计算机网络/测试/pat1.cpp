#include <stdio.h>
#incldue <stdiio.h>    //malloc函数包含在这个头文件中 

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();

    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}
List ReadInput() /* 裁判实现，细节不表。元素从下标0开始存储 */
{
	int n;
	scanf("%d",&n);
	List l=(List)malloc(sizeof(LNode));//进行有效的指针指向（若未对指针分配有效的指向空间，则其指向的位置不确定） 


	for(int i=0;i<n;i++)
	{
		scanf("%d",&l->Data[i]);
		l->Last=i;
	}
	
	return l;
}
void PrintList( List L ) /* 裁判实现，细节不表 */
{
	for(int i= 0;i <=L->Last;i++)
	{
		printf("%d ",L->Data[i]);
	}

}
List Delete( List L, ElementType minD, ElementType maxD )//这种方法更巧妙，通过设置两个变量，第一个遍历，第二个插入，符合条件的挨个插入，覆盖之前的值，最后元素直接由j—1舍去 
{
    Position n = L->Last ;
    int j=0;
    for(int i=0;i<=n;i++)
    {
        if(L->Data[i]<=minD || L->Data[i] >= maxD)
        {
            L->Data[j]=L->Data[i];
            j++;
        }
    }

    L->Last = j-1;

    return  L;
}

/*
List Delete( List L, ElementType minD, ElementType maxD )
{
	for(int i = 0;i <=L->Last;)
	{
	//由于该函数是将本次符合该条件的数组元素删除，相当于其后的一个元素到达这次元素的位置，由于未对其下面元素的判断，因此仍需对本次位置的数组元素进行判断，即其i不变 
	同时，由于本次函数的删除元素是将其后一位元素赋值到其前一位元素中，因此若在循环的途中未删除任何一个元素，则由最后一位元素等于最后一位元素下一位的值，该位置为存储值，
	出现错误，于是应当对最后一个元素进行单独的判断 
	 
		if(L->Data[i]>minD && L->Data[i]<maxD)
		{
			if(i==L->Last)
			{
				L->Last=L->Last-1;
			}
			else
			{
			
			for(int j=i;j<L->Last;j++)
			{
				L->Data[j]=L->Data[j+1];//只需要到倒数第二个元素便可，删除一个元素必然会导致其last值为其倒数第二个元素的位置，且是将下一个位置的值赋值到本次的元素中 
				
			}
			L->Last=L->Last-1;}
		}
		else i++;
	}
	return L;
}
*/
