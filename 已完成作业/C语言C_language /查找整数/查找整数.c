#include<stdio.h>
#define MAXN 10
int main()
{
int i,flag,n,x;
int a[MAXN];
printf("��ֱ���������n��Ŀ����x��");
scanf("%d%d",&n,&x);
printf("������%d����:",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

flag=0;
for(i=0;i<n;i++)
{
if(a[i]==x)
{
printf("index is %d",i);
flag=1;
}
}
if(flag==0)
{
printf("Not Found");
}
return 0;
}
