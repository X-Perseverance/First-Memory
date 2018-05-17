#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//ԭ�ͣ�int strcmp( const char *string1, const char *string2 )
//���ܣ����ڱȽ������ַ����Ĵ�С
//��string1����string2, ����ֵΪ����
//��string1����string2������ֵΪ0
//��string1С��string2, ����ֵΪ����

int my_strcmp(const char *str1, const char *str2)
{
	int ret = 0;
	while (!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && *str1)
	{
		str1++;
		str2++;
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret > 0)
	{
		ret = 1;
	}
	return ret;
}

int main()
{
	printf("%d\n", my_strcmp("abc", "abc"));
	printf("%d\n", my_strcmp("abc", "abcd"));
	printf("%d\n", my_strcmp("abcd", "abc"));
	system("pause");
	return 0;
}