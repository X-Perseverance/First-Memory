#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0, i = 0;
	printf("������һ������: ");
	scanf("%d", &num);
	printf("����λ���У�");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1); //����λ
	}
	printf("\nż��λ���У�");
	for (i = 31; i>0; i -= 2)
	{
		printf("%d ", (num >> i) & 1); //ż��λ
	}
	printf("\n");
	system("pause");
	return 0;
}