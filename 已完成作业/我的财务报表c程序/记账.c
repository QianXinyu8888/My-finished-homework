//���񱨱�2.0
//�������ݼ���������Զ������洴�����±�����С�������Զ�д����±���
#include<stdio.h>
#include <stdlib.h>
int menu(int a);
void jizhang(int cost,int postage,int finalprice,int profit)
{
    char str[10];
printf("������ɱ�:");
scanf("%d",&cost);
printf("�������˷�:");
scanf("%d",&postage);
printf("%������ɽ���:");
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
fprintf(fp,"������%d",profit);      //���������������profitд����±���
fclose (fp);//�ļ�һ��ʹ����ϣ�Ӧ����fclose��fp���������ļ��رգ�
return 0;   //�� (1)���������е����ݴ������̣�(2)ͬʱ�ͷŴ���ڻ������е�����
}
int calculate(int finalprice,int cost,int postage)
int cost,postage,finalprice,profit;
int str[10];
void jizhang();
int main()


int calculate(int finalprice,int cost,int postage)//�Զ���һ��calculate����
{
int add;                                           //�������
add=finalprice-cost-postage;
return add;
}
