#include<stdio.h>
#include<stdlib.h>
int main()
{

int ch;
FILE *fp;
fp=fopen("a.txt","w");
fputs(789,fp);
fclose(fp);
return 0;





}
