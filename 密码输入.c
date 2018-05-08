#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n = 0;
	char password[] = "aabbcc";
	char str[7] = { 0 };
	printf("请输入6位密码：");
	gets(str);
	while (1)
	{
		if (strcmp(str, password) == 0)
		{
			printf("登录成功！\n");
			break;
		}
		else
		{
			n++;
			if (n == 3)
			{
				printf("抱歉，你的机会已经用完！\n");
				break;
			}
			printf("密码错误！你还有%d次机会，请重新输入: ", 3 - n);
			gets(str);
		}
	}
	system("pause");
	return 0;
}
