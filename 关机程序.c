#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char input[10] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("���Խ���1���Ӻ�ػ��������롰cancel����ȡ���ػ���\n");
	scanf("%s", input);
	if (0 == strcmp(input, "cancel"))
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	system("pause");
	return 0;
}