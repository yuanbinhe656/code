#include <stdio.h>
#include <stdlib.h>

typedef struct List  * Listnotes;
typedef struct List  ** Listnote;
struct List{
	int coef;
	int expon;
	Listnotes next;
};
void input(Listnote head,Listnote tail);
void output(Listnote head,Listnote tail);
void insert(Listnote head1,Listnote tail1,int a,int b);
void mud(Listnote head1,Listnote tail1,Listnote head2,Listnote tail2,Listnote head3,Listnote tail3);
void add(Listnote head1,Listnote tail1,Listnote head2,Listnote tail2,Listnote head3,Listnote tail3);

void test1()
{
		Listnote head1,tail1,head2,tail2,headmud,tailmud,headadd,tailadd;
	tail1=(Listnote)malloc(sizeof(Listnotes));
	head1=(Listnote)malloc(sizeof(Listnotes));
	(*tail1)=(Listnotes)malloc(sizeof(struct List));
	(*head1)=(*tail1);

		scanf("%d%d",&(*tail1)->coef,&(*tail1)->expon);
		(*tail1)->next=(Listnotes)malloc(sizeof(struct List));
				scanf("%d%d",&(*tail1)->next->coef,&(*tail1)->next->expon);

			(*tail1)=(*tail1)->next;

		output(head1,tail1);
}
void test3()
{
	Listnote head1,tail1,head2,tail2,headmud,tailmud,headadd,tailadd;
	tail1=(Listnote)malloc(sizeof(Listnotes));
	head1=(Listnote)malloc(sizeof(Listnotes));
	(*tail1)=(Listnotes)malloc(sizeof(struct List));
	(*head1)=(*tail1);
	tail2=(Listnote)malloc(sizeof(Listnotes));
	head2=(Listnote)malloc(sizeof(Listnotes));
	(*tail2)=(Listnotes)malloc(sizeof(struct List));
	(*head2)=(*tail2);
	tailmud=(Listnote)malloc(sizeof(Listnotes));
	headmud=(Listnote)malloc(sizeof(Listnotes));
	(*tailmud)=(Listnotes)malloc(sizeof(struct List));
	(*headmud)=(*tailmud);
	tailadd=(Listnote)malloc(sizeof(Listnotes));
	headadd=(Listnote)malloc(sizeof(Listnotes));	
	(*tailadd)=(Listnotes)malloc(sizeof(struct List));
	(*headadd)=(*tailadd);
	
	input(head1,tail1);
	input(head2,tail2);
	
/*	insert(head1,tail1,4,8);

	insert(head1,tail1,4,4);
	insert(head1,tail1,5,2);*/

	mud(head1,tail1,head2,tail2,headmud,tailmud);
	add(head1,tail1,head2,tail2,headadd,tailadd);
	output(headmud,tailmud);
	output(headadd,tailadd);
	

}
void test2()
{
		Listnote head1,tail1,head2,tail2,headmud,tailmud,headadd,tailadd;
	tail1=head1=(Listnote)malloc(sizeof(Listnotes));
	(*tail1)=(Listnotes)malloc(sizeof(struct List));
	tail2=head2=(Listnote)malloc(sizeof(Listnotes));
	(*tail2)=(Listnotes)malloc(sizeof(struct List));
	headmud=tailmud=(Listnote)malloc(sizeof(Listnotes));	
	(*headmud)=(Listnotes)malloc(sizeof(struct List));
	headadd=tailadd=(Listnote)malloc(sizeof(Listnotes));
	(*headadd)=(Listnotes)malloc(sizeof(struct List));
	scanf("%d%d",&(*tail1)->coef,&(*tail1)->expon);
	printf("%d,%d",(*tail1)->coef,(*tail1)->expon);
//	input(head1,tail1);
	output(head1,tail1);
	printf("lala/n");
	printf("%d,%d",(*tail1)->coef,(*tail1)->expon);
			Listnotes list1=(*head1)->next;
			printf("%d %d ",list1->coef,list1->expon);
		while(list1!=(*tail1))
		{
			printf("haha");
			printf("%d %d ",list1->coef,list1->expon);
			list1=list1->next;

		}

		printf("%d %d\n",(*tail1)->coef,(*tail1)->expon);
	output(head1,tail1);	
	
	input(head2,tail2);
	mud(head1,tail1,head2,tail2,headmud,tailmud);
	add(head1,tail1,head2,tail2,headadd,tailadd);
	output(headmud,tailmud);
	output(headadd,tailadd);
}
int main()
{
	test3();
	return 0;
	

}
void input(Listnote head,Listnote tail)
{

		int n;
	scanf("%d",&n);
	if(n>0)
	{

		for(int i=0;i<n;i++)
		{
			(*tail)->next=(Listnotes)malloc(sizeof(struct List));
			(*tail)=(*tail)->next;
			(*tail)->next=NULL;
			scanf("%d%d",&(*tail)->coef,&(*tail)->expon);

		}
	}

}
void mud(Listnote head1,Listnote tail1,Listnote head2,Listnote tail2,Listnote head3,Listnote tail3)
{
		Listnotes list1=(*head1)->next,list2=(*head2)->next;
	while(list1!=NULL)
	{
		while(list2!=NULL)
		{
			insert(head3,tail3,(list1->coef)*list2->coef,list2->expon+list1->expon);

				list2=list2->next ;			
		}
	list2=(*head2)->next;
		list1=list1->next ;
	}

	
}
void add(Listnote head1,Listnote tail1,Listnote head2,Listnote tail2,Listnote head3,Listnote tail3)
{
		Listnotes list1=(*head1)->next;
		Listnotes list2=(*head2)->next;
	while(list1!=NULL)
	{
					insert(head3,tail3,list1->coef,list1->expon);
							list1=list1->next ;
						}
	while(list2!=NULL)
		{

					insert(head3,tail3,list2->coef,list2->expon);
			list2=list2->next ;		
		}

	
}
void insert(Listnote head1,Listnote tail1,int a,int b)
{
	Listnotes list1=(*head1),list2;
	if((*head1)==(*tail1))
	{
			if(a==0&&b!=0)
		{
			return;
		}
		else
		{
		list2=(Listnotes)malloc(sizeof(struct List));
		list2->next=list1->next;
		(*head1)->next=list2;
		list2->coef=a;
		list2->expon=b;
		(*tail1)=list2;
		return ;
		}
	}
	if(b>list1->next->expon)
	{
		if(a==0&&b!=0)
		{
			return;
		}
		else
		{
		list2=(Listnotes)malloc(sizeof(struct List));
		list2->next=list1->next;
		(*head1)->next=list2;
		list2->coef=a;
		list2->expon=b;
		return ;
		}
	}
	while(list1!=(*tail1)&&b<list1->next->expon)
	{
		list1=list1->next;

	}
	
	if(list1==(*tail1))
	{

		if(a==0&&b!=0)
		{
			return;
		}
		
		else {
		(*tail1)->next=(Listnotes)malloc(sizeof(struct List));
		(*tail1)=(*tail1)->next;
		(*tail1)->coef=a;
		(*tail1)->expon=b;
		(*tail1)->next=NULL;			
		}
	}
	else if(list1->next->expon==b)
		{
			list1->next->coef=list1->next->coef+a;
			if(list1->next->coef==0&&b!=0)
			{
				list2=list1->next;
				list1->next=list1->next->next;
				free(list2);
			}
		}

	else 
	{
		if(a==0&&b!=0)
		{
			return;
		}
		else {
		list2=(Listnotes)malloc(sizeof(struct List));
		list2->next=list1->next;
		list1->next=list2;
		list2->coef=a;
		list2->expon=b;
	}
	}
}


void output(Listnote head,Listnote tail)
{
		Listnotes list1=(*head)->next;
		while(list1!=NULL)
		{

			printf("%d %d ",list1->coef,list1->expon);
			list1=list1->next;

		}
		printf("\n");

		return ;
}
