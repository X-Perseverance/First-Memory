#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;
	printf("«Î ‰»Î±ﬂ≥§:");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			printf("  ");
		}
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for (i = n - 1; i >= 1; i--)
	{
		for (j = 1; j <= n - i; j++)
		{
			printf("  ");
		}
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}