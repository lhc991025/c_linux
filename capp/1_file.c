#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(void)
{
	char buff[1024];
	int fd1, fd2;
	int ret;
	fd1 = open("./src.txt", O_RDONLY);
	if(fd1 == -1)
	{
		return fd1;
	}
	
	fd2 = open("./des.txt", O_WRONLY);
	if(fd2 == -1)
	{
		ret = fd2;
		goto out1;
	
	}
	ret = read(fd1, buff, sizeof(buff));
	if(ret == -1)
		goto out2;
	
	ret = write(fd2, buff, sizeof(buff));
	printf("ret = %d\n", ret);
	if(ret == -1)
		goto out2;
	ret = 0;

out2:
	//关闭目标文件
	close(fd2);
out1:
	//关闭源文件
	close(fd1);

}
