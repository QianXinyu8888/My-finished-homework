#include<stdio.h>
int nopass=0;
int avg(int a[])
{
  int j,sum=0;
  for(j=0;j<100;j++)
  {
  sum+=a[j];
  if(a[j]<60)
  	nopass++;
  }
  return sum/100.0;
}
int main(void)
{
    int score[100];
    int i;
    FILE  * fp ;
    if(fp=fopen("data2.txt","r")==NULL)
    {
        printf("文件不能打开!");
        return -1;
    }
    for(i=0;i<100;i++)
    {
        fscanf("%d",&score[i]);
        printf("%5d ",score[i]);
if(i%10==9)
printf("\n");
    }
    printf("\nnopass=%d, average=%.1f\n ",nopass,avg(score));
    fclose(fp);
    return 0;
}
