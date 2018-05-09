#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0, i = 0;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	printf("奇数位序列：");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1); //奇数位
	}
	printf("\n偶数位序列：");
	for (i = 31; i>0; i -= 2)
	{
		printf("%d ", (num >> i) & 1); //偶数位
	}
	printf("\n");
	system("pause");
	return 0;
}