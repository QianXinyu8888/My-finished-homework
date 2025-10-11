#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[100];
    char t[100];
    int i, k = 0, j = 0;
    FILE *fp;  //定义文件指针
    fgets(s, sizeof(s), stdin); // 使用fgets代替gets，避免缓冲区溢出
    fp = fopen("file1.txt", "w");			/*【2】*/
    for(i = 0; i < strlen(s); i++)  //遍历字符串	/*【3】*/
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            t[j] = s[i]; j++;
            if((s[i] - '0') % 2 == 0)  //判断是否为偶数	/*【4】*/
              k++;
        }
    }

    t[j] = '\0';
    fprintf(fp, "%s", t);
    fprintf(fp, " 偶数的个数：%d", k);
    fclose(fp);
    return 0;
}
