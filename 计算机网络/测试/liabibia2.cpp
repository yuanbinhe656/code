#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");

    return 0;
}
struct ListNode *createlist()
{
struct ListNode *S,*T;
S=(struct ListNode *)malloc(sizeof(struct ListNode));
S->next=NULL;
S->data=NULL;
int n;
scanf("%d",&n);
if(n==-1)
{
	free(S); 
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
T=S;
S=S->next;
free(T);
return S;

	
}
