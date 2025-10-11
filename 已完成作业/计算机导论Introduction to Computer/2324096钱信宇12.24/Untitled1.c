#include <stdio.h>
#include <stdlib.h>
int main(void)
{
FILE * fp;
double n ;
fp=fopen("data.txt","w");
scanf ("%lf", &n) ;
while (n!=-1){
fprintf(fp, "%lf ", n);
scanf("%lf",&n);
}
fclose (fp);
return 0;
}
