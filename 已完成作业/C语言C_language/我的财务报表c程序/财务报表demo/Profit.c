#include<stdio.h>
int main()
{
int calculate(int finalprice,int cost,int postage);
int cost,postage,finalprice,profit;
int str[10];
printf("ʲô���ͣ�");
scanf("%s",str);
printf("������ɱ�");
scanf("%d",&cost);
printf("�������˷�");
scanf("%d",&postage);
printf("%������ɽ���");
scanf("%d",&finalprice);
profit=calculate(finalprice,cost,postage);
printf("���ͣ�%s",str);
printf("�ɱ���%d",&cost);
printf("�˷ѣ�%d",&postage);
printf("�ɽ��ۣ�%d",&finalprice);
printf("profit=%d",&profit);
return 0;
}


int calculate(int finalprice,int cost,int postage)
{
int add;
add=finalprice-cost-postage;
return add;
}
