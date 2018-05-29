#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 0;
	int n = 0;
	int sum = 0;
	int tmp = 0;
	printf("»Á£∫a+aa+aaa+aaaa+...\n");
	printf("«Î ‰»Îa∫Õn£∫");
	scanf("%d %d", &a, &n);
	for (int i = 0; i < n; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("sum=%d\n", sum);
	system("pause");
	return 0;
}