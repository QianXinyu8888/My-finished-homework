//财务报表2.0
//输入数据计算利润→自动在桌面创建记事本→把小结数据自动写入记事本中
#include<stdio.h>
#include <stdlib.h>
int calculate(int finalprice,int cost,int postage);
int cost,postage,finalprice,profit;choice;
int str[10];
int main()
{
printf("                                                “Automatic profit calculator”\n\n");
printf("                                                        Instructions\n\n");
printf("  If you just need to calculate your own profit, please enter“1”. But if you not only need to calculate your own profit, but also want to write summary into your notebook,please enter “2”!\n\n");
printf("Explanatory: Qian Xinyu, a freshman student, the published author of the Automatic profit calculator.\n\n");
printf("Step 1: Now please enter your choice :");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Step 2: 请输入成本:");
scanf("%d",&cost);
printf("Step: 3 请输入运费:");
scanf("%d",&postage);
printf("Step: 4 请输入成交价:");
scanf("%d",&finalprice);
profit=calculate(finalprice,cost,postage);
printf("*******************************************\n");
printf("净利润：%d",profit);
break;
case 2:
printf("Step: 2 请输入机型？");
scanf("%s",str);
printf("Step: 3 请输入成本:");
scanf("%d",&cost);
printf("Step: 4 请输入运费:");
scanf("%d",&postage);
printf("Step: 5 请输入成交价:");
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
fprintf(fp,"净利润：%d\n",profit);        //把以上输入的利润profit写入记事本中
fclose (fp);//文件一旦使用完毕，应该用fclose（fp）函数把文件关闭3
printf("\n\n  We have help you to save the data and write a series of data in your notebook successfully! Please close your windows confidently~ \n");
break;
default:
    printf("输入有误，请您重新输入数字1或2");
}
return 0;
}

int calculate(int finalprice,int cost,int postage)//自定义一个calculate函数
{
int add;                                           //计算过程
add=finalprice-cost-postage;
return add;
}
