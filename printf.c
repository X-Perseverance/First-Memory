#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	system("pause");
	return 0;
}

//执行结果为：4321
//printf：每个函数都返回打印的字符数，如果出现错误，则返回负值