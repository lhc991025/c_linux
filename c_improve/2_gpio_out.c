#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

static char gpio_path[100];

static int gpio_config(const char *attr, const char *value)
{
    char file_path[100];
    int len;
    int fd;

    sprintf(file_path, "%s/%s", gpio_path, value);
    if(0 > (fd = open(file_path, O_WRONLY))){
        perror("open");
        exit(-1);
    }
    len = strlen(value);
    if(len != write(fd, value, len)){
        perror("write");
        exit(-1);
    }
    close(fd);
    exit(0);
}

int main(int argc, char *argv[])
{   
    //校验传参
    if(3 != argc){
        fprintf(stderr, "Usage:%s <gpio> <value>", argv[0]);
        exit(-1);
    }

    //判断指定编号的GPIO是否导出
    sprintf(gpio_path, "/sys/class/gpio/gpio%s", argv[1]);

    
    if(access(gpio_path, F_OK)){ //如果目录不存在，则需要导出
        int fd;
        int len;
        if(0 > (fd = open("sys/class/gpio/export", O_WRONLY))){
            perror("open");
            exit(-1);
        }
        len = strlen(argv[1]);
        if(len != write(fd, argv[1], len)){  //导出gpio
            perror("write");
            close(fd);
            exit(-1);
        }
        close(fd);
    }

    //配置为输出模式
    if(gpio_config("direction", "out")){
        exit(-1);
    }

    //设置极性模式
    if(gpio_config("active", "on")){
        exit(-1);
    }

    //控制GPIO输出高低电平
    if(gpio_config("value", "argv[2]")){
        exit(-1);
    }
    exit(0);
}