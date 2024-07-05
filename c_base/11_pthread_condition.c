#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

static pthread_mutex_t mutex; //定义互斥锁
static pthread_cond_t cond; //定义条件变量
static int g_avail = 0; //全局共享资源

static void *consumer_thread(void *arg)
{
    for( ; ; )
    {
        pthread_mutex_lock(&mutex);

        while(0 >= g_avail)
            pthread_cond_wait(&cond, &mutex);
        
        //消费
        while(0 < g_avail)
            g_avail--; 

        pthread_mutex_unlock(&mutex);
    }
    return (void*)0;
}

int main(int argc, char* argv[])
{
    pthread_t tid;
    int ret;

    //初始化互斥锁和条件变量
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    //创建新线程
    ret = pthread_create(&tid, NULL, consumer_thread, NULL);
    if (ret)
    {
        perror("pthread_create error");
        exit(-1);
    }

    for( ; ; )
    {
        pthread_mutex_lock(&mutex);
        //生产
        g_avail++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    exit(0);
}