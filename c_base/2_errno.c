#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	int fd;
	fd = open("./test.txt", O_RDONLY);
	if(-1 == fd)
	{
		printf("Error:%s\n", strerror(errno));
		perror("open error");
		_exit(-1);
	}
	close(fd);
	_exit(0);
}
