#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//一般方法
//int main()
//{
//	int x = 0, y = 0;
//	printf("请输入两个数：");
//	scanf("%d %d", &x, &y);
//	int min = (x<y) ? x : y;
//	int max = (x>y) ? x : y;
//	for (int i = min; i > 0; i--)
//	{
//		if ((x%i == 0) && (y%i == 0))
//		{
//			printf("最大公约数为%d\n", i);
//			break;
//		}
//	}
//	for (int j = max; j <= x*y; j++)
//	{
//		if ((j%x == 0) && (j%y == 0))
//		{
//			printf("最小公倍数为%d\n", j);
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}

//辗转相除法
int main()
{
	int x = 0, y = 0;
	int m = 0, n = 0;
	int tmp = 0;
	printf("请输入两个数：");
	scanf("%d %d", &x, &y);
	m = x;
	n = y;
	tmp = m%n;
	while (tmp)
	{
		m = n;
		n = tmp;
		tmp = m%n;
	}
	printf("最大公约数为%d\n", n);
	printf("最小公倍数为%d\n", x*y / n);
	system("pause");
	return 0;
}
