#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row = 0;
	printf("«Î ‰»Î–– ˝£∫");
	scanf("%d", &row);
	int a[20][20] = { 0 };
	int num = 1;
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= i; j++)
		{
			a[i - j][j] = num++;
		}
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row - i; j++)
		{
			printf("%2d ", a[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}