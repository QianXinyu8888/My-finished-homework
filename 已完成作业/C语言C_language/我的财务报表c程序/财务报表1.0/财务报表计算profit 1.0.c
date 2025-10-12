//财务报表demo
//实现功能：输入数据→通过自定义函数calculate计算利润
#include<stdio.h>
int main()
{
int calculate(int finalprice,int cost,int postage);
int cost,postage,finalprice,profit;
int str[10];//定义一个数组，用来存放字符串，以便输出机型名称
printf("请输入机型？");//提示输入数据
scanf("%s",str);
printf("请输入成本:");
scanf("%d",&cost);
printf("请输入运费:");
scanf("%d",&postage);
printf("%请输入成交价:");
scanf("%d",&finalprice);
profit=calculate(finalprice,cost,postage);//调用calculate函数     //calculate=自定义函数中的add
printf("*******************************************\n");
printf("机型:%s\n",str);//str是数组，且此处为printf函数，不需要加地址符，scanf才用加
printf("成本：%d\n",cost);
printf("运费：%d\n",postage);
printf("成交价：%d\n",finalprice);
printf("利润：%d",profit);
return 0;
}


int calculate(int finalprice,int cost,int postage)
{
int add;
add=finalprice-cost-postage;
return add;//返回值给回calculate（第17行）
}
