#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//��дһ�����򣬿���һֱ���ռ����ַ�
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ�������Ǵ�д�ַ��������Ӧ��Сд�ַ�����������ֲ����

int main()
{
	char ch = 0;
	printf("�������ַ���");
	while ((ch = getchar()) != '\n')
	{
		if ((ch >= '0') && (ch <= '9'))
		{
			continue;
		}
		else
		{
			if ((ch >= 'A') && (ch <= 'Z'))
			{
				ch = ch - 'A' + 'a';
			}
			else
			{
				ch = ch - 'a' + 'A';
			}
			putchar(ch);
		}
	}
	system("pause");
	return 0;
}
