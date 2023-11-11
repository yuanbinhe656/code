#include<fstream>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
bool IsDuplicated(string a[], int iLen,string t);
long double tnum[30000]={0}; //提取最终哈希表hashtable_probabilit中每个单词所对应的频率
string str[30000]; //提取最终哈希表 hashtable_probabilit 中每个单词
int main()
{
int w;
ifstream fin1("yuan.txt"); //创建读取文件对象
if(!fin1) //打开失败
{ 
cout<<"不能打开输入文件1。"<<endl;
return 1;
}
for (w=0;w<30000;w++) //读取最终表中的每个单词的概率
{
fin1>>str[w];
 if(str[w]=="") // 结束循环的判断语句
 continue;
 fin1>>tnum[w];
tnum[w]=tnum[w]/1000.0;
}
fin1.close();
ifstream fin("tt.txt"); //创建读取文件对象
if(!fin) //打开失败
{ 
cout<<"不能打开输入文件2。"<<endl;
return 1;
}
string str1[30000]; // 定义存储每个单词的 str
int i;
 
for(i=0;i<30000;i++)
{
 fin>>str1[i]; //读取内容放入变量中
if(str1[i]=="") // 结束循环的判断语句
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
} // 把结尾单词带有标点的去掉
if (!(str1[i].at(0)>='a' && str1[i].at(0)<='z'||str1[i].at(0)>='A' && str1[i].at(0)<='Z'))
{
if (str1[i].length()==1)
{continue;}
else
str1[i].erase(0,1);
} // 把开始单词带有标点的去掉
 // 计算总共录入的单词
 if (IsDuplicated(str1,i,str1[i])) // 判断是否为重复单词
{ 
i--;
 continue;
}
}
long double p=1.0,q=1.0,u; //最终公式的实现中的变量
fin.close();
 for (int r=0;r<i;r++) //循环，与给出的最终哈希表hashtable_probabilit 中找到对应的值
{
for (int y=0;y<w;y++)
{
 if (str1[r]!="" && str[y]!="") //把空的排除掉
 {
 if (str[y]==str1[r])
 {
 p=tnum[y]*p; //最终公式的分子部分
 q=(1-tnum[y])*q; //最终公式的分母的部分
 }
 }
} 
} 
 u=p/(p+q); //求最终的概率
/*此处考虑最小风险贝叶斯垃圾邮件过滤技术以及最终的判定
另一种是相应的损失为 e(a1。c2)，表示把合法邮件误判为垃圾邮件，还有一
种 e(a2，c1)表示把垃圾邮件当做合法邮件。
原则上表 I 中 e(a1，c2)的取值比 e(a2，c1)要大。*/
 /*最小风险贝叶斯算法考虑到把合法邮件判断为垃圾邮件的风险要大于把垃
圾邮件判断为合法邮件，则把两者风险系数之比定为 e.
 e=e(a1。c2)/e(a2，c1),由实验结果可以知道,但是当风险系数取 3 的时候，合
法邮件误判率达到了 0．00％*/
//所以此时，可以将 e(a1。c2)=3，e(a2，c1)=1；带入到求期望的计算式中 R1=（1-u）*e(a1，c2)，R2=u*e(a2，c1)如果 R2≤R1
//则判定为合法邮件，否则判定为垃圾邮件。
 double R1,R2;
 R1=(1-u)*3;
 R2=u*1;
 if (u>0.9 && (R1>=R2)) //超过预定阈值(例如 O．9)时，就可以判断邮件为垃圾邮件
 cout<<"邮件为垃圾邮件"<<endl;
 else
 cout<<"邮件为非垃圾邮件"<<endl;
return 0;
}
bool IsDuplicated(string a[], int iLen,string t) //函数的实现部分
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

