#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char buf[] = "hello world\n";
	char rd_buf[20];
	FILE *fp = NULL;
	int size;
	int ret;
	//打开文件
	if(NULL == (fp = fopen("./test_file", "w+")))
	{
		perror("fopen error");
		exit(-1);
	}
	printf("文件打开成功\n");

	//写入数据
	
	if(sizeof(buf) > fwrite(buf, 1, sizeof(buf), fp))
	{
		perror("fwrite error");
		fclose(fp);
		exit(-1);
	}
	printf("数据写入成功\n");

	// 刷新缓冲区以确保数据写入文件
    fflush(fp);

    // 重置文件指针到文件开头
    fseek(fp, 0, SEEK_SET);

	if(sizeof(buf) > (size = fread(rd_buf, 1, sizeof(buf), fp)))
	{
		perror("fread error");
		fclose(fp);
		exit(-1);
	}
	printf("读取的数据: %s\n", rd_buf);

	//将读写位置移动到文件末尾
	if(0 > fseek(fp, 0, SEEK_END))
	{
		perror("fseek error");
		fclose(fp);
		exit(-1);
	}

	//获取当前位置的偏移量
	if(0 > (ret = ftell(fp)))
	{
		perror("ftell error");
		fclose(fp);
		exit(-1);
	}
	printf("当前位置偏移量（文件大小）：%d个字节\n", ret);

	//读写位置移动到文件末尾后，再读文件
	if(sizeof(buf) > fread(buf, 1, sizeof(buf), fp))
	{
		if(feof(fp))
			printf("end-of-file标志已被设置，已到达文件末尾\n");
		clearerr(fp);
	}
	//关闭文件
	fclose(fp);
	exit(0);
}

