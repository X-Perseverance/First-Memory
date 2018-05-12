#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//一组数据中只有一个数字出现了一次,其他所有数字都是成对出现的,请找出这个数字（使用位运算）

int main()
{
	int num = 0;
	int arr[] = { 2, 5, 6, 8, 10, 2, 5, 6, 8 };
	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		num ^= arr[i];
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}