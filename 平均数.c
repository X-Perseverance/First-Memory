#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1 = 0, num2 = 0;
	int average = 0;
	printf("请输入两个数：");
	scanf("%d %d", &num1, &num2);
	average = (num1&num2) + ((num1^num2) >> 1);
	// num1&num2        : 取相同位的一半
	// (num1^num2) >> 1 : 取不同位的一半
	printf("average=%d\n", average);
	system("pause");
	return 0;
}