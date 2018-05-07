#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int mid = 0, left = 0, right = 9;
	int key = 0;
	printf("请输入你想要查找的数字：");
	scanf("%d", &key);
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (key == a[mid])
		{
			printf("该数存在，下标为%d\n", mid);
			break;
		}
		else
		{
			if (key<a[mid])
			{
				right = mid - 1;
			}
			if (key>a[mid])
			{
				left = mid + 1;
			}
		}
	}
	if (left > right)
	{
		printf("该数不存在\n");
	}
	system("pause");
	return 0;
}