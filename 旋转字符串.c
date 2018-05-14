#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//实现一个函数，可以左旋字符串中的k个字符。
//ABCDE左旋一个字符得到BCDEA
//ABCDE左旋两个字符得到CDEAB

void Reverse(char str[], int n, int len)
{
	n %= len;
	while (n)
	{
		int i = 0;
		char tmp = str[0];
		for (i = 0; i < len - 1; i++)
		{
			str[i] = str[i + 1];
		}
		str[len - 1] = tmp;
		n--;
	}
}

int main()
{
	char str[] = "ABCDE";
	int n = 0;
	printf("左旋前：%s\n", str);
	printf("请输入左旋字符个数：");
	scanf("%d", &n);
	Reverse(str, n, strlen(str));
	printf("左旋%d个字符后：%s\n", n, str);
	system("pause");
	return 0;
}