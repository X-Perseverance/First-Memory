#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_add(int x, int y)
{
	return x + y;
}

int my_sub(int x, int y)
{
	return x - y;
}

int my_mul(int x, int y)
{
	return x * y;
}

int my_div(int x, int y)
{
	if (y == 0)
	{
		printf("分母不能为0！\n");
		return -1;
	}
	return x / y;
}

int main(int argc,char *argv[])
{
	if (argc != 4)
	{
		printf("格式为:%s [-a|-s|-m|-d] x y\n", argv[0]);
		return 0;
	}
	int op = 0;
	int(*fun[4])(int, int) = { my_add, my_sub, my_mul, my_div }; //函数指针数组
	if (strcmp(argv[1], "-a") == 0)
	{
		op = 0;
	}
	else if (strcmp(argv[1], "-s") == 0)
	{
		op = 1;
	}
	else if (strcmp(argv[1], "-m") == 0)
	{
		op = 2;
	}
	else if (strcmp(argv[1], "-d") == 0)
	{
		op = 3;
	}
	else
	{
		printf("格式为:%s [-a|-s|-m|-d] x y\n", argv[0]);
		return 0;
	}
	int res = fun[op](atoi(argv[2]), atoi(argv[3]));
	printf("结果是：%d\n", res);
	system("pause");
	return 0;
}