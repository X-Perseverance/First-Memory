#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ԭ�ͣ�char *strcpy(char *strDestination, const char *strSource)
//���ܣ��Ѵ�strSource��ַ��ʼ�Һ��н��������ַ������Ƶ���strDestination��ʼ�ĵ�ַ�ռ���ȥ����\0��Ҳ���ƹ�ȥ

char *my_strcpy(char *dest, const char *src)
{
	assert(dest&&src);
	char *ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char dest[20] = { 0 };
	char src[] = "hello world!";
	printf("%s\n", my_strcpy(dest, src));
	system("pause");
	return 0;
}