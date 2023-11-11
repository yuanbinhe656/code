#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {FALSE=0,TRUE=1} boolean;
typedef int ElementType;
typedef int Position;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty();
Position Find(List L, ElementType X);
boolean Insert(List L, ElementType X, Position P);
boolean Delete(List L, Position P);

int main()
{
	List L;
	ElementType X;
	Position P;
	int N;

	L = MakeEmpty();
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		if (Insert(L, X, 0) == FALSE)
			printf(" Insertion Error: %d is not in.\n", X);
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else
			printf("%d is at position %d.\n", X, P);
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &P);
		if (Delete(L, P) == FALSE)
			printf(" Deletion Error.\n");
		if (Insert(L, 0, P) == FALSE)
			printf(" Insertion Error: 0 is not in.\n");
	}
	return 0;
}
List MakeEmpty()
{
	List l ;
	l= (List)malloc(sizeof( struct LNode));//要在结构体名称前加结构体声明 
	l->Last = -1;
	return l;
}
Position Find(List L, ElementType X)
{
	int i = 0;
	while ( i <= L->Last && L->Data[i] != X)
	{
		i++;
	}
	if (i == L->Last + 1)
	{
		
		return ERROR;

	}
	else
	{
	
			return i;
	}
}
/*
另一种find
 Position Find(List L, ElementType X)
 {
 for(int i=0;i<=L->L.Last;i++)
 {
 if(L.Data[i]==X)
 {
 return i;
}
 }
 return ERROE;
}
*/ 
boolean Insert(List L, ElementType X, Position P)
{
	if (L->Last == MAXSIZE-1)
	{
		printf("FULL");
		return FALSE;
	}
	else if(L->Last==-1&&P==0)
	{
		L->Data[0]=X;
		L->Last=0;
		return TRUE;
	}
	else if (L->Last+1 < P || P < 0)

	{
		printf("ILLEGAL POSITION");
		return FALSE;
	}
	else
	{
		L->Last++;
		int i = L->Last;
		for (; i > P; i--)

		{
			L->Data[i] = L->Data[i - 1];
		}
		L->Data[i] = X;
		return TRUE;
	}
}
boolean Delete(List L, Position P)
{
	if (P > L->Last || P < 0)
	{
		printf("POSITION %d EMPTY",P);
		return FALSE;
	}
	else
	{
		for (int i = P; i <= L->Last; i++)
		{
			L->Data[i] = L->Data[i + 1];
		}
		L->Last--;
		return TRUE;
	}
}
