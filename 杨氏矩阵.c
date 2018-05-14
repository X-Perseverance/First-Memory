#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//杨氏矩阵：
//有一个二维数组，数组的每行从左到右是递增的，每列从上到下是递增的
//在这样的数组中查找一个数字是否存在，时间复杂度小于O(N)
//
//1 2 3
//4 5 6
//7 8 9

int Search(int arr[][3], int num)
{
	int i = 0, j = 2;
	int key = arr[i][j]; //数组右上角
	while (1)
	{
		if (key == num)
		{
			return 1;
		}
		else if (key < num && i <= 2) //不在当前行
		{
			key = arr[++i][j];
		}
		else if (key > num && j >= 0) //不在当前列
		{
			key = arr[i][--j];
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	int arr[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num = 0;
	printf("请输入一个数：");
	scanf("%d", &num);
	if (num < arr[0][0] || num > arr[2][2])
	{
		printf("该数不存在\n");
		system("pause");
		return 0;
	}
	if (Search(arr, num))
	{
		printf("该数存在\n");
	}
	else
	{
		printf("该数不存在\n");
	}
	system("pause");
	return 0;
}