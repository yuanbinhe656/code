#include <stdio.h>
#include <stdlib.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
       printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}
struct stud_node *createlist()
{
	struct stud_node *head,*p;
	head=(struct stud_node*)malloc(sizeof(struct stud_node));
	p=head;
	int n;
	scanf("%d",&n);

	while(n!=0)
	{
		p->next=(struct stud_node*)malloc(sizeof(struct stud_node));
		p=p->next;
		p->num=n;
		scanf("%s",p->name);
		scanf("%d",&p->score);
		scanf("%d",&n);
	
	}
	p->next=NULL;
	head=head->next; 

	return head;
}
struct stud_node *deletelist( struct stud_node *head, int min_score )
{
	struct stud_node *L,*p;
	L=(struct stud_node*)malloc(sizeof(struct stud_node));
	L->next=head; 
	head=L;
	while(L->next)
	{
		if(L->next->score<min_score)
		{
			p=L->next;
			L->next=L->next->next;
			free(p);
		}
		else
		L=L->next;
	}
	p=head;
	head=head->next;
	free(p);

	return head;
}
