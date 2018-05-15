#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//判断一个字符串是否为另外一个字符串旋转之后的字符串
//例如：
//给定s1 ＝ AABCD和s2 = BCDAA，返回1; 给定s1 = abcd和s2 = ACBD，返回0

int Reverse(char str1[], char str2[], int len)
{
	int n = len;
	while (n)
	{
		int i = 0;
		char tmp = str1[0];
		for (i = 0; i < len - 1; i++)
		{
			str1[i] = str1[i + 1];
		}
		str1[len - 1] = tmp;
		if (strcmp(str1, str2) == 0)
		{
			return 1;
		}
		n--;
	}
	return 0;
}

int main()
{
	char str1[] = "ABCDE";
	char str2[] = "CDEAB";
	printf("str1:%s\nstr2:%s\n", str1, str2);
	int count = Reverse(str1, str2, strlen(str1));
	if (count)
	{
		printf("str2是str1左旋后形成的\n");
	}
	else
	{
		printf("str2不是str1左旋后形成的\n");
	}
	system("pause");
	return 0;
}