#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ʵ��һ�����������������ַ����е�k���ַ���
//ABCDE����һ���ַ��õ�BCDEA
//ABCDE���������ַ��õ�CDEAB

void Reverse(char str[], int n, int len)
{
	n %= len;
	while (n)
	{
		int i = 0;
		char tmp = str[0];
		for (i = 0; i < len - 1; i++)
		{
			str[i] = str[i + 1];
		}
		str[len - 1] = tmp;
		n--;
	}
}

int main()
{
	char str[] = "ABCDE";
	int n = 0;
	printf("����ǰ��%s\n", str);
	printf("�����������ַ�������");
	scanf("%d", &n);
	Reverse(str, n, strlen(str));
	printf("����%d���ַ���%s\n", n, str);
	system("pause");
	return 0;
}