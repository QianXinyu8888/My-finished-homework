//���񱨱�demo
//ʵ�ֹ��ܣ��������ݡ�ͨ���Զ��庯��calculate��������
#include<stdio.h>
int main()
{
int calculate(int finalprice,int cost,int postage);
int cost,postage,finalprice,profit;
int str[10];//����һ�����飬��������ַ������Ա������������
printf("��������ͣ�");//��ʾ��������
scanf("%s",str);
printf("������ɱ�:");
scanf("%d",&cost);
printf("�������˷�:");
scanf("%d",&postage);
printf("%������ɽ���:");
scanf("%d",&finalprice);
profit=calculate(finalprice,cost,postage);//����calculate����     //calculate=�Զ��庯���е�add
printf("*******************************************\n");
printf("����:%s\n",str);//str�����飬�Ҵ˴�Ϊprintf����������Ҫ�ӵ�ַ����scanf���ü�
printf("�ɱ���%d\n",cost);
printf("�˷ѣ�%d\n",postage);
printf("�ɽ��ۣ�%d\n",finalprice);
printf("����%d",profit);
return 0;
}


int calculate(int finalprice,int cost,int postage)
{
int add;
add=finalprice-cost-postage;
return add;//����ֵ����calculate����17�У�
}
