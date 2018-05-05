#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void DisplayYH(int n)
{
	assert(n > 0);
	int **mem = (int**)malloc(sizeof(int*)*n);
	if (mem == NULL)
	{
		return;
	}
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		mem[i] = (int*)malloc(sizeof(int)*n);
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				mem[i][j] = 1;
			}
		}
	}

	for (i = 2; i < n; i++)
	{
		for (j = 1; j < i; j++)
		{
			mem[i][j] = mem[i - 1][j] + mem[i - 1][j - 1];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (int k = 0; k < n - 1 - i; k++)
		{
			printf("%2c", ' ');
		}
		for (j = 0; j <= i; j++)
		{
			printf("%2d%2c", mem[i][j], ' ');
		}
		printf("\n");
	}

	for (i = 0; i < n; i++)
	{
		free(mem[i]);
	}
	free(mem);
}

int main()
{
	int n = 0;
	printf("请输入行数：");
	scanf("%d", &n);
	DisplayYH(n);
	system("pause");
	return 0;
}