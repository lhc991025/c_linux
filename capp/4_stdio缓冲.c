#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    //不设置默认为行缓冲模式

    //将标准输出设置为无缓冲模式
    if(setvbuf(stdout, NULL, _IONBF, 0))
    {
        perror("setvbuf error");
        exit(0);
    }

    printf("hello word\n");
    printf("hello world");

    //强制刷新标准输出缓冲区
    //fflush(stdout);

    for( ; ; )
        sleep(1);
}