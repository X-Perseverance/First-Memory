#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int min = 1, max = 100;
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int n = 0;
	printf("��������µ�����(1~100)��");
	scanf("%d", &n);
	while (1)
	{
		if (n < num)
		{
			min = n;
			printf("��µ�����С�ˣ�������%d��%d�����֣�", min, max);
			scanf("%d", &n);
			if (n<min || n>max)
			{
				printf("�������ڴ˷�Χ�У����������룺");
				scanf("%d", &n);
			}
		}
		else if (n > num)
		{
			max = n;
			printf("��µ����ִ��ˣ�������%d��%d�����֣�", min, max);
			scanf("%d", &n);
			if (n<min || n>max)
			{
				printf("�������ڴ˷�Χ�У����������룺");
				scanf("%d", &n);
			}
		}
		else
		{
			printf("��ϲ��¶��ˣ�\n");
			break;
		}
	}
	system("pause");
	return 0;
}