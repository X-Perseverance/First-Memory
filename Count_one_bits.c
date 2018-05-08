#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		count++;
		value = value&(value - 1);   //最低位为1，其余全为0，循环效率高，有几个1就循环几次
	}
	return count;
}

int main()
{
	int num = 0;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	printf("二进制中一共有%d个1\n", Count_one_bits(num));
	system("pause");
	return 0;
}