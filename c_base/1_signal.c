#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//用户自定义处理函数
static void sig_handler(int sig)
{
    printf("receive singal:%d\n", sig);
}

int main(int argc, char *argv[])
{
    sig_t ret =NULL;
    ret = signal(SIGINT, (sig_t)sig_handler);
    if(SIG_ERR == ret)
    {
        perror("signal error");
        exit(-1);
    }
    
    for( ; ; )
    {

    }
    exit(0);
}