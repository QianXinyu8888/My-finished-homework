#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp;
char n;
char c[10];
fp=fopen("test1","w");
fprintf(fp,"lalala");
fclose(fp);

fp=fopen("test","r");
fscanf(fp,"%s",c);
printf("%s",c);
return 0;
}
