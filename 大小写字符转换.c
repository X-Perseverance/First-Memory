#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//编写一个程序，可以一直接收键盘字符
//如果是小写字符就输出对应的大写字符；如果是大写字符就输出对应的小写字符；如果是数字不输出

int main()
{
	char ch = 0;
	printf("请输入字符：");
	while ((ch = getchar()) != '\n')
	{
		if ((ch >= '0') && (ch <= '9'))
		{
			continue;
		}
		else
		{
			if ((ch >= 'A') && (ch <= 'Z'))
			{
				ch = ch - 'A' + 'a';
			}
			else
			{
				ch = ch - 'a' + 'A';
			}
			putchar(ch);
		}
	}
	system("pause");
	return 0;
}
