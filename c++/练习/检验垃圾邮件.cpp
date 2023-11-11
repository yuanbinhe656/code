#include<fstream>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
bool IsDuplicated(string a[], int iLen,string t);
long double tnum[30000]={0}; //��ȡ���չ�ϣ��hashtable_probabilit��ÿ����������Ӧ��Ƶ��
string str[30000]; //��ȡ���չ�ϣ�� hashtable_probabilit ��ÿ������
int main()
{
int w;
ifstream fin1("yuan.txt"); //������ȡ�ļ�����
if(!fin1) //��ʧ��
{ 
cout<<"���ܴ������ļ�1��"<<endl;
return 1;
}
for (w=0;w<30000;w++) //��ȡ���ձ��е�ÿ�����ʵĸ���
{
fin1>>str[w];
 if(str[w]=="") // ����ѭ�����ж����
 continue;
 fin1>>tnum[w];
tnum[w]=tnum[w]/1000.0;
}
fin1.close();
ifstream fin("tt.txt"); //������ȡ�ļ�����
if(!fin) //��ʧ��
{ 
cout<<"���ܴ������ļ�2��"<<endl;
return 1;
}
string str1[30000]; // ����洢ÿ�����ʵ� str
int i;
 
for(i=0;i<30000;i++)
{
 fin>>str1[i]; //��ȡ���ݷ��������
if(str1[i]=="") // ����ѭ�����ж����
break;
else
{}
 if (!(str1[i].at(str1[i].length()-1)>='a' && 
str1[i].at(str1[i].length()-1)<='z'||str1[i].at(str1[i].length()-1)>='A' && 
str1[i].at(str1[i].length()-1)<='Z'))
{
if (str1[i].length()==1)
{continue;}
else
str1[i].erase (str1[i].length()-1);
} // �ѽ�β���ʴ��б���ȥ��
if (!(str1[i].at(0)>='a' && str1[i].at(0)<='z'||str1[i].at(0)>='A' && str1[i].at(0)<='Z'))
{
if (str1[i].length()==1)
{continue;}
else
str1[i].erase(0,1);
} // �ѿ�ʼ���ʴ��б���ȥ��
 // �����ܹ�¼��ĵ���
 if (IsDuplicated(str1,i,str1[i])) // �ж��Ƿ�Ϊ�ظ�����
{ 
i--;
 continue;
}
}
long double p=1.0,q=1.0,u; //���չ�ʽ��ʵ���еı���
fin.close();
 for (int r=0;r<i;r++) //ѭ��������������չ�ϣ��hashtable_probabilit ���ҵ���Ӧ��ֵ
{
for (int y=0;y<w;y++)
{
 if (str1[r]!="" && str[y]!="") //�ѿյ��ų���
 {
 if (str[y]==str1[r])
 {
 p=tnum[y]*p; //���չ�ʽ�ķ��Ӳ���
 q=(1-tnum[y])*q; //���չ�ʽ�ķ�ĸ�Ĳ���
 }
 }
} 
} 
 u=p/(p+q); //�����յĸ���
/*�˴�������С���ձ�Ҷ˹�����ʼ����˼����Լ����յ��ж�
��һ������Ӧ����ʧΪ e(a1��c2)����ʾ�ѺϷ��ʼ�����Ϊ�����ʼ�������һ
�� e(a2��c1)��ʾ�������ʼ������Ϸ��ʼ���
ԭ���ϱ� I �� e(a1��c2)��ȡֵ�� e(a2��c1)Ҫ��*/
 /*��С���ձ�Ҷ˹�㷨���ǵ��ѺϷ��ʼ��ж�Ϊ�����ʼ��ķ���Ҫ���ڰ���
���ʼ��ж�Ϊ�Ϸ��ʼ���������߷���ϵ��֮�ȶ�Ϊ e.
 e=e(a1��c2)/e(a2��c1),��ʵ��������֪��,���ǵ�����ϵ��ȡ 3 ��ʱ�򣬺�
���ʼ������ʴﵽ�� 0��00��*/
//���Դ�ʱ�����Խ� e(a1��c2)=3��e(a2��c1)=1�����뵽�������ļ���ʽ�� R1=��1-u��*e(a1��c2)��R2=u*e(a2��c1)��� R2��R1
//���ж�Ϊ�Ϸ��ʼ��������ж�Ϊ�����ʼ���
 double R1,R2;
 R1=(1-u)*3;
 R2=u*1;
 if (u>0.9 && (R1>=R2)) //����Ԥ����ֵ(���� O��9)ʱ���Ϳ����ж��ʼ�Ϊ�����ʼ�
 cout<<"�ʼ�Ϊ�����ʼ�"<<endl;
 else
 cout<<"�ʼ�Ϊ�������ʼ�"<<endl;
return 0;
}
bool IsDuplicated(string a[], int iLen,string t) //������ʵ�ֲ���
{
for (int j=0; j<iLen; j++)
{
if(t==a[j])
{
 return true;
}
}
return false;
}

