#include <stdio.h>
#include <stdlib.h>

//各种遍历的方法 
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}

void InorderTraversal( BinTree BT )
{
if(BT)
{
	InorderTraversal(BT->Left);
	printf(" %c",BT->Data);
	InorderTraversal(BT->Right);
}
return;
	
 } 
void PreorderTraversal( BinTree BT )
{
	if(BT)
	{
		printf(" %c",BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}

 } 
void PostorderTraversal( BinTree BT )
{
if(BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c",BT->Data);
	}
 } 
void LevelorderTraversal( BinTree BT )
{
Position T[100];
int i=0,j=0;
if(!BT)
{
	return -1;
}

T[j++]=BT;
while(i<j)
{
	BinTree s=T[i];
	printf(" %c",s->Data);
	if(s->Left)
	{
		T[j++]=s->Left;
	}
	if(s->Right)
	{
		T[j++]=s->Right;
	}
	i++;
	
}


 } 
