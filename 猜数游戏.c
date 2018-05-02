#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int min = 1, max = 100;
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int n = 0;
	printf("请输入你猜的数字(1~100)：");
	scanf("%d", &n);
	while (1)
	{
		if (n < num)
		{
			min = n;
			printf("你猜的数字小了，请输入%d到%d的数字：", min, max);
			scanf("%d", &n);
			if (n<min || n>max)
			{
				printf("该数不在此范围中，请重新输入：");
				scanf("%d", &n);
			}
		}
		else if (n > num)
		{
			max = n;
			printf("你猜的数字大了，请输入%d到%d的数字：", min, max);
			scanf("%d", &n);
			if (n<min || n>max)
			{
				printf("该数不在此范围中，请重新输入：");
				scanf("%d", &n);
			}
		}
		else
		{
			printf("恭喜你猜对了！\n");
			break;
		}
	}
	system("pause");
	return 0;
}