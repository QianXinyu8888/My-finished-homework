#include<stdio.h>
int main()
{
int calculate(int finalprice,int cost,int postage);
int cost,postage,finalprice,profit;
int str[10];
printf("什么机型？");
scanf("%s",str);
printf("请输入成本");
scanf("%d",&cost);
printf("请输入运费");
scanf("%d",&postage);
printf("%请输入成交价");
scanf("%d",&finalprice);
profit=calculate(finalprice,cost,postage);
printf("机型：%s",str);
printf("成本：%d",&cost);
printf("运费：%d",&postage);
printf("成交价：%d",&finalprice);
printf("profit=%d",&profit);
return 0;
}


int calculate(int finalprice,int cost,int postage)
{
int add;
add=finalprice-cost-postage;
return add;
}
