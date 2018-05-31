#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch = 0;
	printf("请输入字符：");
	while ((ch = getchar()) != '\n')
	{
		if ((ch >= 'A') && (ch <= 'Z'))
		{
			//ch = ch - 'A' + 'a';
			//ch = ch + 32;
			putchar(tolower(ch));
		}
		else if ((ch >= 'a') && (ch <= 'z'))
		{
			//ch = ch - 'a' + 'A';
			//ch = ch - 32;
			putchar(toupper(ch));
		}
		//putchar(ch);
	}
	printf("\n");
	system("pause");
	return 0;
}
