#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���
//���磺
//����s1 �� AABCD��s2 = BCDAA������1; ����s1 = abcd��s2 = ACBD������0

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
		printf("str2��str1�������γɵ�\n");
	}
	else
	{
		printf("str2����str1�������γɵ�\n");
	}
	system("pause");
	return 0;
}