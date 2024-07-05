#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

    printf("atoi: %d\n", atoi("500"));   //字符串转int
    printf("atol: %ld\n", atol("500"));   //字符串转long int
    printf("atoll: %lld\n", atoll("500")); //字符串转 long long int
    
    printf("atof: %f\n", atof("0.1231")); //字符串转浮点数

}