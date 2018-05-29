#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//int main()
//{
//	int i = 0;
//	int a = 0, b = 0, c = 0;
//	for (i = 100; i < 1000; i++)
//	{
//		a = i / 100;      //百位
//		b = i / 10 % 10;  //十位
//		c = i % 10;       //个位
//		if (i == a*a*a + b*b*b + c*c*c)
//		{
//			printf("%d ", i);
//		}
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < 1000000; i++)
	{
		int sum = 0;
		int count = 1;
		tmp = i;
		while (tmp>9) //统计位数
		{
			count++;
			tmp = tmp / 10;
		}

		tmp = i; //重新赋值
		while (tmp) //求和
		{
			sum = sum + (int)pow(tmp%10, count);
			tmp = tmp / 10;
		}

		if (i == sum) //判断水仙花数
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}