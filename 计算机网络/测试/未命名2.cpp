#include <stdio.h>
#include <stdlib.h>
typedef struct List  * Listnotes;
typedef struct List  ** Listnote;
struct List{
	int coef;
	int expon;
	Listnote next;
};
int main()
{
			printf("heh");
	Listnote head1,tail1,head2,tail2,headmud,tailmud,headadd,tailadd;
	Listnotes hid;
	tail1=head1=(Listnote)malloc(sizeof(Listnotes));
	(*head1)=(Listnotes)malloc(sizeof(struct List));
	hid=(*head1)->next;
	hid=(Listnotes)malloc(sizeof(struct List));
	(*head1)->coef=1;
		printf("heh");
	printf("%d",(*head1)->coef);
	printf("heh");
	system("pause");
	return 0;
}
