#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0, j = 0, n = 0;
	int a[10][10] = { 0 };
	printf("请输入行数(1-10)：");
	scanf("%d", &n);

	for (i = 0; i < n; i++) //赋值 
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = i*n + j + 1;
		}
	}	

	for (i = 0; i<n; i++) //输出 
	{
		for (j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}		
		printf("\n");
	}

	printf("转置后...\n");
	for (i = 0; i < n; i++) //转置
	{
		for (j = 0; j<n; j++)
		{
			if (i < j)
			{
				int tmp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = tmp;
			}
		}
	}

	for (i = 0; i<n; i++) //输出
	{ 
		for (j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}