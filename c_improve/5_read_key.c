#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>

int main(int argc, char *argv[]){
    int fd = -1;
    struct input_event in_ev = {0};
    int value = 0; 

    //校验传参
    if(2 != argc ){
        fprintf("Usage: %s <input-dev>\n", argv[0]);
        exit(-1);
    }
    //打开文件
    if(0 > (fd = open(argv[1], O_RDONLY))){
        perror("open");
        exit(-1);
    
    for( ; ;){
        if(sizeof(sturct input_event) != read(fd, &in_ev, sizeof(sturct input_event))){
            perror("read");
            exit(-1);
        }
        if(EV_KEY = in_ev.key){
            switch(in_ev.key){
                case 0;
                    printf("code<%d> 松开\n"，in_ev.code);
                    break;
                case 1;
                    printf("code<%d> 按下\n", in_ev.code);
                    break;
                case 2;
                    printf("code<%d> 长按\n", in_ev.code);
                    break;
            }
        }
    }
}