#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

static void *new_thread_start(void *arg)
{
    printf("新线程start\n");
    sleep(1);
    printf("新线程end\n");
    pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret;

    ret = pthread_create(&tid, NULL, new_thread_start, NULL);
    if(ret)
    {
        perror("pthread error");
        exit(-1);
    }

    printf("主线程end\n");
    pthread_exit(NULL);
    exit(0);
}