//���񱨱�2.0
//�������ݼ���������Զ������洴�����±�����С�������Զ�д����±���
#include<stdio.h>
#include <stdlib.h>
int calculate(int finalprice,int cost,int postage);
int cost,postage,finalprice,profit;choice;
int str[10];
int main()
{
printf("                                                ��Automatic profit calculator��\n\n");
printf("                                                        Instructions\n\n");
printf("  If you just need to calculate your own profit, please enter��1��. But if you not only need to calculate your own profit, but also want to write summary into your notebook,please enter ��2��!\n\n");
printf("Explanatory: Qian Xinyu, a freshman student, the published author of the Automatic profit calculator.\n\n");
printf("Step 1: Now please enter your choice :");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Step 2: ������ɱ�:");
scanf("%d",&cost);
printf("Step: 3 �������˷�:");
scanf("%d",&postage);
printf("Step: 4 ������ɽ���:");
scanf("%d",&finalprice);
profit=calculate(finalprice,cost,postage);
printf("*******************************************\n");
printf("������%d",profit);
break;
case 2:
printf("Step: 2 ��������ͣ�");
scanf("%s",str);
printf("Step: 3 ������ɱ�:");
scanf("%d",&cost);
printf("Step: 4 �������˷�:");
scanf("%d",&postage);
printf("Step: 5 ������ɽ���:");
scanf("%d",&finalprice);
profit=calculate(finalprice,cost,postage);
printf("*******************************************\n");
printf("����:%s\n",str);
printf("�ɱ���%d\n",cost);
printf("�˷ѣ�%d\n",postage);
printf("�ɽ��ۣ�%d\n",finalprice);
printf("������%d",profit);
FILE*fp;                             // ����createһ�� �����ļ�fp��ָ�룩
fp=fopen("Ǯ���Ĳ��񱨱�.txt","w");// ����define���涨 �����ļ�fp ָ����ļ�
fprintf(fp,"%s\n", str);           //����������Ļ������֣�����str��д����±���
fprintf(fp,"�ɱ���%d\n",cost);        //����������ĳɱ�costд����±���
fprintf(fp,"�˷ѣ�%d\n",postage);     //������������˷�postageд����±���
fprintf(fp,"�ɽ��ۣ�%d\n",finalprice);//����������ĳɽ���finalpriceд����±���
fprintf(fp,"������%d\n",profit);        //���������������profitд����±���
fclose (fp);//�ļ�һ��ʹ����ϣ�Ӧ����fclose��fp���������ļ��ر�3
printf("\n\n  We have help you to save the data and write a series of data in your notebook successfully! Please close your windows confidently~ \n");
break;
default:
    printf("������������������������1��2");
}
return 0;
}

int calculate(int finalprice,int cost,int postage)//�Զ���һ��calculate����
{
int add;                                           //�������
add=finalprice-cost-postage;
return add;
}
