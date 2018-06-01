#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


int main()
{
	for (int num = 0; num <= 100; num++)
	{
		if ((num&(num - 1)) == 0)
		{
			printf("%d ",num);
		}
	}
	system("pause");
	return 0;
}