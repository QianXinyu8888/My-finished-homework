#include<stdio.h>
int main()
{
int answer,num;
char y;
printf("���Ⱦ�����?");
scanf("%s",&answer);
if (answer=='y')//����1
{printf("����������������ֵ");}//����1����
scanf("%d",&num);
if(num<=20)//����2
{printf("��ͨ�Ƽ�");}//����2����
else if(num>=20)
{printf("���");}//����2������
else {printf("û���ˣ����߰�");}//����1������
}
