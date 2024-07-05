#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

static pthread_mutex_t mutex;
static int g_count = 0;

static void *new_thread_start(void *arg)
{
    int loops = *((int*)arg);
    int l_count, j;
    for(j = 0; j < l_count; j++)
    {
        pthread_mutex_lock(&mutex);//互斥锁上锁

        l_count = g_count;
        l_count ++;
        g_count = l_count;

        pthread_mutex_unlock(&mutex);//互斥锁解锁
    }
    return (void*)0;
}


int main(int argc, char *argv[])
{
    pthread_t tid1, tid2;
    int ret;

    //获取用户给的参数
    if()
}