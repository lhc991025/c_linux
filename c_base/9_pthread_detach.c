#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

static void *new_thread_start(void *arg)
{
    int ret;
    //线程分离
    ret = pthread_detach(pthread_self());
    if(ret)
    {
        fprintf(stderr, "pthread_detach error: %s\n", strerror(ret));
        return NULL;
    }
    printf("新线程开始\n");
    sleep(2);
    printf("新线程结束\n");
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t tid;
    int ret;
    //创建新线程
    ret = pthread_create(&tid, NULL, new_thread_start, NULL);
    if(ret)
    {
        perror("pthread_create error:");
        exit(-1);
    }

    sleep(1);

    //等待线程终止
    ret =  pthread_join(tid, NULL);
    if(ret)
    {
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
    }

    pthread_exit(NULL);

}