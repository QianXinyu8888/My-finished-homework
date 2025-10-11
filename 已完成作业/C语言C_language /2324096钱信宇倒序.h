#include<stdio.h>
int reverse(int n);
int main()
{
int n;
int choice;
printf("输入[1]逆序\t输入[2]退出程序");
scanf("%d",&choice);
printf("输入个数n:");
scanf("%d",&n);
reverse(n);
}
int reverse(n)
{
int a[100];
int i;
for(i=0;i<n;i++)
{
printf("输入元素:");
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
    printf("\n逆序存放后a=");
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
}
