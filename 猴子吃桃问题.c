#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//一只猴子连吃10天桃子，每天吃一半多一个，最后一天只剩1个，问总共有几个桃子

int main()
{
	int num = 1;
	int day = 10;
	while (--day)
	{
		num = (num + 1) * 2;
	}
	printf("总数：%d个\n", num);
	system("pause");
	return 0;
}