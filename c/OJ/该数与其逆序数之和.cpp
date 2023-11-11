#include<stdio.h>
int inverse(int n)
{
 //计算并返回n的逆序数字
 int s = 0;
 while (n > 0)
 {
  s = s * 10 + n % 10;
  n = n / 10;
 }
 return s;

}
int main()
{
 int m, n,x;
 scanf("%d", &n);
 m = inverse(n);
 x = m + n;
 printf("%d", x);
 return 0;
}
