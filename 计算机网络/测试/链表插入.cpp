#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    printlist(head);
    head = deleteeven(head);
    printlist(head);

    return 0;
}

struct ListNodee *createlist()
{
	int n;
struct ListNode *L,*S,*T;
	L=(struct ListNode *)malloc(sizeof(struct ListNode));
	scanf("%d",&n);
	if(n!=-1)
	{

	L->data=n;	
	}
	else
	return L;

	S=L;
	scanf("%d",&n);
	while(n!=-1)
	{
	T=(struct ListNode *)malloc(sizeof(struct ListNode));
	T->data=n;
	S->next=T;
	T->next=NULL;
	S=S->next;
	scanf("%d",&n);	
	}
	return L;
}
struct ListNode *createlist()
{
ListNode *L,*S,*T;
S=(struct ListNode *)malloc(sizeof(struct ListNode));
S->next=NULL;
int n;
scanf("%d",&n);
if(n==-1)
{
	return NULL;
}
while(n!=-1)
{
	T=(struct ListNode *)malloc(sizeof(struct ListNode));
	T->data=n;
	T->next=S->next;
	S->next=T;
	scanf("%d",&n);
}
L=S;
S=S->next;
free(L);
return S;

	
}
struct ListNode *deleteeven( struct ListNode *head )//删除偶数位置的节点 
{
struct ListNode *S,*T;

while (head != NULL && head->data%2==0)
	{
		T = head;
		head = head->next;
		free(T);
	}
	// 头结点为空直接返回
	if (head == NULL)
	{
		return NULL;
	}

	S=head;
/*	if(!head)
	{
		return NULL;
	}
		if(S->data%2==0)
	{
		T=head;
		head=S->next;
		free(T);
	}*/
	while(S->next)
	{
		
	if(S->next->data%2==0)
	{
		T=S->next;
	S->next=S->next->next;

		free(T);	
	}
	else
		S=S->next;

	}
	return head;
}
struct ListNode *deleteevens( struct ListNode *head )//删除偶数位置的节点 
{
struct ListNode *S,*T;

	S=head;
	while(S)
	{

	if(!S->next)
	{
		return head;
	}
		T=S->next;
	S->next=S->next->next;
	S=S->next;
	free(T);

	}
	return head;
}

struct ListNode *createlist()
{
	struct ListNode *pt;
	pt = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *head, *tail;
	head = tail = NULL;
	scanf("%d", &pt->data);
	while (pt->data != -1)
	{
		if (head == NULL)
			head = pt;
		else
			tail->next = pt;

		tail = pt;
		pt = (struct ListNode *)malloc(sizeof(struct ListNode));
		scanf("%d", &pt->data);
	}
	return head;
}
struct ListNode *deleteeven(struct ListNode *head)
{
	struct ListNode *p1, *p2;

		// 先检查头结点是否
	while (head != NULL && head->data%2==0)
	{
		p1 = head;
		head = head->next;
		free(p1);
	}
	// 头结点为空直接返回
	if (head == NULL)
	{
		return NULL;
	}
	p1 = head;
	p2 = p1->next;
	// 头结点没问题了  看头结点以后
	// 后面要是没有直接跳过循环return   head就行
	while (p2 != NULL)
	{
		if (p2->data%2==0)
		{
			p1->next = p2->next;
			free(p2);
		}
		else
		{
			p1 = p2;
		}
		// 让p2等于下一个继续检验
		p2 = p1->next;
	}

	return head;
}

