#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 0, y = 0;
	int m = 0, n = 0;
	int tmp = 0;
	printf("��������������");
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
	printf("���Լ��Ϊ%d\n", n);
	printf("��С������Ϊ%d\n", x*y / n);
	system("pause");
	return 0;
}