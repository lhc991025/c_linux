#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MALLOC_MEM_SIZE (1*1024*1024)

int main(int argc, char *argv[])
{
    char *base = NULL;
    //申请堆内存
    base = (char*)malloc(MALLOC_MEM_SIZE);
    if(NULL == base)
    {
        perror("malloc error");
        exit(-1);
    }

    //初始化申请的堆内存
    memset(base, 0x0, MALLOC_MEM_SIZE);

    /*
    使用内存
    */
    printf("please entet a strin\n");
    fgets(base, MALLOC_MEM_SIZE, stdin);

    for(int i = 0; i < strlen(base); i++)
    {
        base[i] = toupper(base[i]);
    }

    printf("base: %s\n", base);

    free(base);
    exit(0);
}