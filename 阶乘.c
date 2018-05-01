#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//方法一：
double Fact(int n)
{
	static double num = 1;
	num *= n;
	return num;
}

int main()
{
	int n = 0;
	printf("请输入n：");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d! = %.0f\n", i, Fact(i));
	}
	system("pause");
	return 0;
}

//方法二：
//int main()
//{
//	int n = 0;
//	printf("请输入n：");
//	scanf("%d", &n);
//	double num = 1, sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		num *= i;
//		printf("%d! = %.0f\n", i, num);
//		sum += num;
//	}
//	printf("阶乘和为：%.0f\n", sum);
//	system("pause");
//	return 0;
//}