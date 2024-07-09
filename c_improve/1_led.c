#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/types.h>

#define LED_TRIGGER "sys/class/sys-led/trigger"
#define LED_BRIGHTNESS "sys/class/sys-led/brightness"
#define USAGE() fprintf(stderr, "usage:\n" \
 " %s <on|off>\n" \
 " %s <trigger> <type>\n", argv[0], argv[0])

int main(int argc, char *argv[])
{
    int fd1, fd2;
    if (2 > argc) {
        USAGE();
        exit(-1);
    }
    
    //打开文件
    fd1 = open(LED_TRIGGER, O_RDWR);
    if(0 > fd1){
        perror("open");
        exit(-1);
    }

    fd2 = open(LED_BRIGHTNESS, O_RDWR);
    if(0 > fd2){
        perror("open");
        exit(-1);
    }

    //根据传参控制led
    if(!strcmp(argv[1], "on")){
        write(fd1, "none", 4);
        write(fd2, "1", 1); //led亮
    }

    else if(!strcmp(argv[1], "off")){
        write(fd1, "none", 4);
        write(fd2, "0", 1); //led灭
    }

    else if(!strcmp(argv[1], "trigger")){
        if(3!=argc){
            USAGE();
            exit(-1);
        }
        if(0 > write(fd1, argv[2], strlen(argv[2]))){
            perror("write");
        }
    }
    else
    {
        USAGE();
    }
    exit(0);
}

