#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

//使用可变参数，实现函数，求函数参数的平均值

int average(int n, ...)
{
	va_list arg;
	int i = 0;
	int sum = 0;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
	}
	return sum / n;
	va_end(arg);
}

int main()
{
	int avg = average(6, 2, 4, 6, 8, 10, 12);
	printf("avg=%d\n", avg);
	system("pause");
	return 0;
}