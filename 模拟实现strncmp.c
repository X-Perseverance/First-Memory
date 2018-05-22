#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_strncmp(const char *str1, const char *str2, int count)
{
	int ret = 0;
	while (count && !(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && *str1)
	{
		str1++;
		str2++;
		count--;
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
	printf("%d\n", my_strncmp("abcd", "abc", 4));
	printf("%d\n", my_strncmp("abc", "abcd", 2));
	printf("%d\n", my_strncmp("abc", "abcd", 4));
	system("pause");
	return 0;
}