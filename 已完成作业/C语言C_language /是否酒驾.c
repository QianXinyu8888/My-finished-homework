#include<stdio.h>
int main()
{
int answer,num;
char y;
printf("您喝酒了吗?");
scanf("%s",&answer);
if (answer=='y')//条件1
{printf("请输入您吹气的数值");}//条件1满足
scanf("%d",&num);
if(num<=20)//条件2
{printf("普通酒驾");}//条件2满足
else if(num>=20)
{printf("醉驾");}//条件2不满足
else {printf("没事了，您走吧");}//条件1不满足
}
