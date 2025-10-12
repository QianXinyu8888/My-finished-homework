//财务报表2.0
//输入数据计算利润→自动在桌面创建记事本→把小结数据自动写入记事本中
#include<stdio.h>
#include <stdlib.h>
int menu(int a);
void jizhang(int cost,int postage,int finalprice,int profit)
{
    char str[10];
printf("请输入成本:");
scanf("%d",&cost);
printf("请输入运费:");
scanf("%d",&postage);
printf("%请输入成交价:");
scanf("%d",&finalprice);
profit=calculate(finalprice,cost,postage);
printf("*******************************************\n");
printf("机型:%s\n",str);
printf("成本：%d\n",cost);
printf("运费：%d\n",postage);
printf("成交价：%d\n",finalprice);
printf("净利润：%d",profit);

FILE*fp;                             // 创建create一个 磁盘文件fp（指针）
fp=fopen("钱多多的财务报表.txt","w");// 定义define，规定 磁盘文件fp 指向打开文件
fprintf(fp,"%s\n", str);           //把以上输入的机型名字（数组str）写入记事本中
fprintf(fp,"成本：%d\n",cost);        //把以上输入的成本cost写入记事本中
fprintf(fp,"运费：%d\n",postage);     //把以上输入的运费postage写入记事本中
fprintf(fp,"成交价：%d\n",finalprice);//把以上输入的成交价finalprice写入记事本中
fprintf(fp,"净利润：%d",profit);      //把以上输入的利润profit写入记事本中
fclose (fp);//文件一旦使用完毕，应该用fclose（fp）函数把文件关闭，
return 0;   //以 (1)将缓冲区中的数据传给磁盘，(2)同时释放存放在缓冲区中的数据
}
int calculate(int finalprice,int cost,int postage)
int cost,postage,finalprice,profit;
int str[10];
void jizhang();
int main()


int calculate(int finalprice,int cost,int postage)//自定义一个calculate函数
{
int add;                                           //计算过程
add=finalprice-cost-postage;
return add;
}
