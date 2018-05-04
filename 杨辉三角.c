#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[20][20] = { 0 };
	int i = 0, j = 0, k = 0, n = 0;
	printf("«Î ‰»Î–– ˝£∫");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		arr[i][1] = 1;
		arr[i][i] = 1;
	}

	for (i = 3; i <= n; i++)
	{
		for (j = 2; j <= i - 1; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (k = 0; k <= n - i; k++)
		{
			printf(" ");
		}
		for (j = 1; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}