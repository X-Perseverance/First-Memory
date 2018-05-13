#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <string.h>

//题目：
//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前面，所有偶数位于数组的后面

void Sort_arr(int *arr, int size)
{
	int *start = arr;
	int *end = arr + size - 1;
	while (start < end)
	{
		while ((*start & 1) == 1) //判断前部分是否为奇数
		{
			start++;
		}
		while ((*end & 1) == 0) //判断后部分是否为偶数
		{
			end--;
		}
		if (start < end) //交换
		{
			*start ^= *end ^= *start ^= *end;
		}
	}
}

int main()
{
	int arr[] = { 5, 10, 15, 20, 25, 30, 35, 45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Sort_arr(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
