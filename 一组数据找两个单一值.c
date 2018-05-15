#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//题目：
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次，找出这两个数字

void Find(int arr[], int size)
{
	int i = 0;
	int num = 0;
	int pos = 0;
	int num1 = 0;
	int num2 = 0;

	for (i = 0; i < size; i++)
	{
		num ^= arr[i];
	}

	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) != 1) //找异或之后这个数字二进制数中最先出现1的位置
		{
			pos++;
		}
		else
		{
			break;
		}
	}

	for (i = 0; i < size; i++)
	{
		//分成2个子数组，每个子数组都包含一个只出现一次的数字
		if (((arr[i] >> pos) & 1) == 1)
		{
			num1 ^= arr[i];
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	printf("num1=%d num2=%d\n", num1, num2);
}

int main()
{
	int arr[] = { 1, 2, 2, 3, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Find(arr, size);
	system("pause");
	return 0;
}