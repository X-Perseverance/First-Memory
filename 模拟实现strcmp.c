#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//原型：int strcmp( const char *string1, const char *string2 )
//功能：用于比较两个字符串的大小
//当string1大于string2, 返回值为正数
//当string1等于string2，返回值为0
//当string1小于string2, 返回值为负数

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