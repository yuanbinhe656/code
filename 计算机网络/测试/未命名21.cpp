#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
typedef int ElemType;

struct List{
	ElemType a;
	ElemType b;
	List* next;
};
typedef List *Listnote;
Listnote creat(Listnote);
void show(Listnote s);
Listnote stander(Listnote l1);
Listnote insert(Listnote l1,int var1,int var2);
Listnote add(Listnote l1,Listnote l2,Listnote l3);
Listnote mud(Listnote l1,Listnote l2,Listnote l3);
Listnote sub(Listnote l1,Listnote l2,Listnote l3);
void clear(Listnote l1);
void shwo(Listnote l1);
void clear(Listnote l1)
{
	Listnote list1=l1,val;
	while(list1->next)
	{
		val=list1->next;
		list1->next =list1->next->next;
		list1=list1->next;
		free(val);
	}
}
void manu()
{
	int select;
	List l1,l2,l3;
	Listnote List1=&l1,List2=&l2,Last=&l3;
	List1->next=NULL;
	List2->next=NULL;
	Last->next=NULL;		
	printf("**************************************\n");
	printf("*********��ѡ����Ҫ���е�����********\n");
	printf("*********1.���**2.���**3.���***********************\n");
	scanf("%d",&select);
	printf("*********�������һ������ʽ��ϵ����ָ��********\n");
	List1=creat(List1);

	printf("**************************************\n");
	printf("*********������ڶ�������ʽ��ϵ����ָ��********\n");
	List2=creat(List2);
	printf("**************************************\n");
	if(select==1)
	{

		Last=add(List1,List2,Last);
				show(Last);
		
	}
	else if(select==2)
	{
		Last=sub(List1,List2,Last);
		show(Last);		
	}
	else if(select==3)
	{
		Last=mud(List1,List2,Last);
		show(Last);
	}
	else
	{
		printf("�����������������"); 
	}
	return ;		
}


int main(){

	
	while(1)
	{

		manu();

		
	}
	return 0;
	
	
	
}
void show(Listnote w)
{
Listnote s=w;
	while(s->next)
	{
		if(s->next->a==1)
		{
			if(s->b==0)
			printf("1");
			else if(s->next->b==1)
			{
			printf("x");	
				
			}
			else
			{
			printf("x^%d",s->next->b);	
			}
		}
		else if(s->next->b==0)
		{
			printf("%d",s->next->a);
		}
		else if(s->next->b==1)
		{
				printf("%dx",s->next->a);	
		}
		else{
					printf("%dXx^%d",s->next->a,s->next->b);
		}
 	
 	if(s->next->next&&s->next->next->a>0)
 	{
 		printf("+");
	 }

	 s=s->next;
	}
	printf("\n");
return;
}
Listnote insert(Listnote l1,int var1,int var2)
{
	Listnote list1,val;
	list1=l1;

	while(list1->next )
	{
		if(l1->next->b>var2)
		{
				val=(Listnote)malloc(sizeof(struct List));
				val->a=var1;
				val->b=var2;
	
				val->next =l1->next;
				l1->next=val;
				break;			
		}
		
		else if(list1->next->b ==var2)
		{
			list1->next->a=var1+list1->next->a;
			break;
		}
		else if(list1->next->b<var2)
		{
		
			if(list1->next->next&&list1->next->next->b>var2)
			{
				val=(Listnote)malloc(sizeof(struct List));
				val->a=var1;
				val->b=var2;
	
				val->next =list1->next->next;
				list1->next->next=val;
				break;
			}
			else if(!list1->next->next)
			{
				val=(Listnote)malloc(sizeof(struct List));
				val->a=var1;
				val->b=var2;
				val->next=NULL;
				list1->next->next=val;
				break;					
			}
		}
		list1=list1->next;
	}
	if(l1->next==NULL)
	{
		val=(Listnote)malloc(sizeof(struct List));
		val->a=var1;
		val->b=var2;
		val->next=NULL;
		l1->next=val;
		
	}


	return l1;
	
}

Listnote stander(Listnote l1)
{
	Listnote list1,val;
	list1=l1;
	while(list1->next)
	{
		if(list1->next->a==0)
		{
			val=list1->next;
			list1->next=list1->next->next;

			free(val);
		}
		list1=list1->next;
		
	}
	return l1;
}
Listnote add(Listnote L1,Listnote L2,Listnote l3)
{

	Listnote L,head,l1=L1,l2=L2;
	head=L1=l3;

	while(l1->next)
	{
		insert(l3,l1->next->a,l1->next->b);		
		l1=l1->next;
			l3=stander(l3);
	}
	while(l2->next)
	{
		insert(l3,l2->next->a,l2->next->b);
		l2=l2->next;
			l3=stander(l3);		
	}



	return l3;
}
Listnote mud(Listnote L1,Listnote L2,Listnote l3)
{
	Listnote L,head,l1=L1,l2=L2;
	head=L1=l3;
	while(l1->next)
	{
		while(l2->next)
		{
			insert(l3,l1->next->a*l2->next->a,l1->next->b+l2->next->b);
			l2=l2->next;

		}
		l2=L2;
		l1=l1->next;
	}
	l3=stander(l3);
	return l3;
}
Listnote sub(Listnote L1,Listnote L2,Listnote l3)
{


	Listnote L,head,l1=L1,l2=L2;
	head=L1=l3;
	int num;

	while(l1->next)
	{
		insert(l3,l1->next->a,l1->next->b);		
		l1=l1->next;
	}
	while(l2->next)
	{
		num=l2->next->a;
		num=-num;
		insert(l3,-l2->next->a,l2->next->b);
		l2=l2->next;
	
	}
			l3=stander(l3);	



	return l3;
}

Listnote creat(Listnote l2)
{

	Listnote L,head;
	head=L=l2;
	int num;
	printf("��������Ҫ������ݵĸ���");
	scanf("%d",&num); 
	for(int i=0;i<num;i++)
	{
		L->next=(Listnote)malloc(sizeof(struct List));
		L=L->next;
		L->next=NULL;
		printf("��������ϵ��:"); 
		scanf("%d",&L->a);
		printf("��������ָ��:"); 
		scanf("%d",&L->b);		
	}
	return  head;
}


