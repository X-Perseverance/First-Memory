#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

//使用可变参数，实现函数，求函数参数的最大值

int MAX(int n, ...)
{
	va_list arg;
	int i = 0;
	int max = 10;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		int flag = va_arg(arg, int);
		if (flag>max)
		{
			max = flag;
		}
	}
	return max;
	va_end(arg);
}

int main()
{
	int max = MAX(5, 10, 20, 30, 40, 50);
	printf("最大值为%d\n", max);
	system("pause");
	return 0;
}