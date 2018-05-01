#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//方法一：时间复杂度O(n*n)
void Way1(int *arr1, int *arr2, int size1, int size2)
{
	int i = 0, j = 0;
	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				printf("有\n");
				return;
			}
		}
	}
	printf("没有\n");
}

//方法二：时间复杂度O(n)——前提是两个数组都为升序或降序
void Way2(int *arr1, int *arr2, int size1, int size2)
{
	int i = 0, j = 0;
	while (i < size1 && j < size2)
	{
		if (arr1[i] == arr2[j])
		{
			printf("有\n");
			return;
		}
		else if (arr1[i] < arr2[j])
		{
			i++;
		}
		else if (arr1[i] > arr2[j])
		{
			j++;
		}
	}
	printf("没有\n");
}

int main()
{
	int arr1[] = { 1, 3, 5, 7 };
	int arr2[] = { 2, 4, 7, 8 };
	int size1 = sizeof(arr1) / sizeof(int);
	int size2 = sizeof(arr2) / sizeof(int);

	Way1(arr1, arr2, size1, size2);
	Way2(arr1, arr2, size1, size2);

	system("pause");
	return 0;
}