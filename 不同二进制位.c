#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//方法一：
//int Different(int num1, int num2)
//{
//	int count = 0;
//	for (int i = 0; i<32; i++)
//	{
//		if (((num1 & 1) ^ (num2 & 1)) == 1)
//		{
//			count++;
//		}
//		num1 >>= 1;
//		num2 >>= 1;
//	}
//	return count;
//}
//
//int main()
//{
//	int m = 0, n = 0;
//	printf("请输入两个数：");
//	scanf("%d %d", &m, &n);
//	printf("有%d位不同\n", Different(m, n));
//	system("pause");
//	return 0;
//}


//方法二：
int main()
{
	int tmp = 0;
	int m = 0, n = 0, count = 0;
	printf("请输入两个数：");
	scanf("%d %d", &m, &n);
	tmp = m^n;
	while (tmp) //问题转化为tmp的二进制形式中有多少个1
	{
		tmp = tmp&(tmp - 1);
		count++;
	}
	printf("有%d位不同\n", count);
	system("pause");
	return 0;
}