#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[50] = { 0 };
	int size = 0;
	printf("请输入字符串：");
	while ((str[size] = getchar()) != '\n')
	{
		size++;
	}
	str[size] = '\0';
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		if (str[left] != str[right])
		{
			printf("该字符串不是回文\n");
			system("pause");
			return 0;
		}
		left++;
		right--;
	}
	printf("该字符串是回文\n");
	system("pause");
	return 0;
}