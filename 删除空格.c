#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[50] = { 0 };
	printf("������һ���ַ�����");
	gets(str);
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			str[j++] = str[i];
		}
		i++;
	}   
	str[j] = '\0';
	printf("ɾ���ո��%s\n", str);
	system("pause");
	return 0;
}