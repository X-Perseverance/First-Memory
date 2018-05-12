#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//编写函数：
//unsigned int ReverseBit(unsigned int value);
//这个函数的返回值为value的二进制形式从左到右翻转后的值
//如：
//在32位机器上25的二进制形式为：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832

unsigned int ReverseBit(unsigned int value)
{
	int sum = 0;
	int bit = 0;
	for (int i = 0; i < 32; i++)
	{
		sum = sum << 1;
		bit = value & 1;
		sum = sum | bit;
		value = value >> 1;
	}
	return sum;
}

int main()
{
	int value = 0;
	scanf("%d", &value);
	printf("%u\n", ReverseBit(value));
	system("pause");
	return 0;
}