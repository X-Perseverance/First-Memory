#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int passwd[10] = { 0 };
	int ch = 0;
	printf("请输入密码：");
	scanf("%s", passwd);
	printf("%s\n", passwd);
	printf("请确认Y/N\n");

	//方法一：清理内存缓冲区
	fflush(stdin);

	//方法二：手动清除
	//while ((ch = getchar() != '\n') && (ch != EOF))
	//{
	//	;
	//}

	ch = getchar();
	if ('Y' == ch)
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}
	system("pause");
	return 0;
}