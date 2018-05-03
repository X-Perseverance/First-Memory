#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void Print(int num)
{
	if (num > 9)
	{
		Print(num / 10); //递归
	}
	printf("%d ", num % 10);
}

int main()
{
	int num = 123;
	Print(num);
	printf("\n");
	system("pause");
	return 0;
}
