#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<linux/input.h>

int main(int argc, char *argv[])
{
    struct input_event in_ev = {0};
    in fd = -1;
    //校验传参
    if(2 != argc){
        fprintf(stderr, "usage: %s <inuput-dev> /n", argv[0]);
        exit(-1);
    }

    //打开文件
    if(0 > (fd = open(argv[1], O_RDONLY)){
        perror("open error");
        exit(-1);
    }

    for( ; ;){
        if(sizeof(struct input_event) != read(fd, &in_ev, sizeof(struct input_event))){
            perror("read error");
            exit(-1);
        }
        printf("type: %d code: %d value: %d\n", in_ev.type, in_ev.code, in_ev.value);
    }
}



