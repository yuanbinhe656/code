#include <stdio.h>
#incldue <stdiio.h>    //malloc�������������ͷ�ļ��� 

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
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
List ReadInput() /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
{
	int n;
	scanf("%d",&n);
	List l=(List)malloc(sizeof(LNode));//������Ч��ָ��ָ����δ��ָ�������Ч��ָ��ռ䣬����ָ���λ�ò�ȷ���� 


	for(int i=0;i<n;i++)
	{
		scanf("%d",&l->Data[i]);
		l->Last=i;
	}
	
	return l;
}
void PrintList( List L ) /* ����ʵ�֣�ϸ�ڲ��� */
{
	for(int i= 0;i <=L->Last;i++)
	{
		printf("%d ",L->Data[i]);
	}

}
List Delete( List L, ElementType minD, ElementType maxD )//���ַ��������ͨ������������������һ���������ڶ������룬���������İ������룬����֮ǰ��ֵ�����Ԫ��ֱ����j��1��ȥ 
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
	//���ڸú����ǽ����η��ϸ�����������Ԫ��ɾ�����൱������һ��Ԫ�ص������Ԫ�ص�λ�ã�����δ��������Ԫ�ص��жϣ��������Ա���λ�õ�����Ԫ�ؽ����жϣ�����i���� 
	ͬʱ�����ڱ��κ�����ɾ��Ԫ���ǽ����һλԪ�ظ�ֵ����ǰһλԪ���У��������ѭ����;��δɾ���κ�һ��Ԫ�أ��������һλԪ�ص������һλԪ����һλ��ֵ����λ��Ϊ�洢ֵ��
	���ִ�������Ӧ�������һ��Ԫ�ؽ��е������ж� 
	 
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
				L->Data[j]=L->Data[j+1];//ֻ��Ҫ�������ڶ���Ԫ�ر�ɣ�ɾ��һ��Ԫ�ر�Ȼ�ᵼ����lastֵΪ�䵹���ڶ���Ԫ�ص�λ�ã����ǽ���һ��λ�õ�ֵ��ֵ�����ε�Ԫ���� 
				
			}
			L->Last=L->Last-1;}
		}
		else i++;
	}
	return L;
}
*/
