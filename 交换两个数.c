#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void Exchange1(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void Exchange2(int *x, int *y)
{
	*x ^= *y ^= *x ^= *y;
}

void Exchange3(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

int main()
{
	int a = 10, b = 20;
	printf("a=%d b=%d\n", a, b);

	Exchange1(&a, &b);
	printf("交换后：\n");
	printf("a=%d b=%d\n", a, b);

	Exchange2(&a, &b);
	printf("交换后：\n");
	printf("a=%d b=%d\n", a, b);

	Exchange3(&a, &b);
	printf("交换后：\n");
	printf("a=%d b=%d\n", a, b);

	system("pause");
	return 0;
}