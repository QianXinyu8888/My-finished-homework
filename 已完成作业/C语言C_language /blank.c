#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[100];
    char t[100];
    int i, k = 0, j = 0;
    FILE *fp;  //�����ļ�ָ��
    fgets(s, sizeof(s), stdin); // ʹ��fgets����gets�����⻺�������
    fp = fopen("file1.txt", "w");			/*��2��*/
    for(i = 0; i < strlen(s); i++)  //�����ַ���	/*��3��*/
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            t[j] = s[i]; j++;
            if((s[i] - '0') % 2 == 0)  //�ж��Ƿ�Ϊż��	/*��4��*/
              k++;
        }
    }

    t[j] = '\0';
    fprintf(fp, "%s", t);
    fprintf(fp, " ż���ĸ�����%d", k);
    fclose(fp);
    return 0;
}
