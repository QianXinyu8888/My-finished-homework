#include<stdio.h>
int reverse(int n);
int main()
{
int n;
int choice;
printf("����[1]����\t����[2]�˳�����");
scanf("%d",&choice);
printf("�������n:");
scanf("%d",&n);
reverse(n);
}
int reverse(n)
{
int a[100];
int i;
for(i=0;i<n;i++)
{
printf("����Ԫ��:");
scanf("%d",&a[i]);
}
printf("a=");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
int b[100];
int num;
    for(i=0;i<n;i++){
        num=a[i];
        b[n-1-i]=num;
    }
    printf("\n�����ź�a=");
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
}
