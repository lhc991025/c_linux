#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    char str[100] = {0};
    FILE *fp = NULL;

    //打开文件
    fp = fopen("./test_file", "w+");
    if(NULL == fp)
    {
        perror("fopen error");
        exit(-1);
    }

    //从文件中写入字符
    fgets(str, sizeof(str), fp);

    fputs("./test_file", fp);
    printf("%s", str);
    fclose(fp);
    exit(0);
}