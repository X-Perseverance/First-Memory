#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = -1;
	int count = 0;

	//for (int i = 0; i < 32; i++)
	//{
	//	if (((num >> i) & 1) == 1)
	//	{
	//		count++;
	//	}
	//}

	while (num) //优化
	{
		count++;
		num &= (num - 1);
	}

	printf("%d的二进制序列有%d个1\n", num, count);
	system("pause");
	return 0;
}