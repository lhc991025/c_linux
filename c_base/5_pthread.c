#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<sys/types.h>

static void *new_thread_start(void *arg)
{
    printf("新线程：进程ID<%d> 线程ID<%lu>\n", getpid(), pthread_self());
    return (void *)0;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret;

    ret = pthread_create(&tid, NULL, new_thread_start, NULL);
    if(ret)
    {
        fprintf(stderr, "Error:%s\n", strerror(ret));
        exit(-1);
    }

    printf("主线程：进程ID<%d> 线程ID<%lu>\n", getpid(), pthread_self());
    sleep(1);
    exit(0);
}