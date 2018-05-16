#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//题目：
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水？

int Num(int money)
{
	int sum = money;
	int empty = money;
	while (empty >= 2)
	{
		sum += (empty / 2);
		empty = (empty / 2) + (empty % 2);
	}
	return sum;
}

int main()
{
	int money = 0;
	printf("请输入金额：");
	scanf("%d", &money);
	printf("可以换%d瓶饮料\n", Num(money));
	system("pause");
	return 0;
}