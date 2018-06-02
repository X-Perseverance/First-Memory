#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int Binary_Search(int arr[], int left, int right, int num)
{
	assert(arr);
	int mid = left + ((right - left) >> 1);
	if(left <= right)
	{
		if (arr[mid] < num)
		{
			return Binary_Search(arr, mid + 1, right, num);
		}
		else if (arr[mid] > num)
		{
			return Binary_Search(arr, left, mid - 1, num);
		}
		else
		{
			return mid;
		}
	}
	else
	{
		return -1;
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = Binary_Search(arr, 0, size - 1, 5);
	if (result == -1)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了，在第%d个位置\n", result + 1);
	}
	system("pause");
	return 0;
}