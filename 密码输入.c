#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n = 0;
	char password[] = "aabbcc";
	char str[7] = { 0 };
	printf("������6λ���룺");
	gets(str);
	while (1)
	{
		if (strcmp(str, password) == 0)
		{
			printf("��¼�ɹ���\n");
			break;
		}
		else
		{
			n++;
			if (n == 3)
			{
				printf("��Ǹ����Ļ����Ѿ����꣡\n");
				break;
			}
			printf("��������㻹��%d�λ��ᣬ����������: ", 3 - n);
			gets(str);
		}
	}
	system("pause");
	return 0;
}
