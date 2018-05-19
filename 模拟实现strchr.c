#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *my_strchr(const char *str, char c)
{
	assert(str);
	char *cur = (char *)str;
	while (*cur++)
	{
		if (*cur == c)
		{
			return cur;
		}
	}
	return NULL;
}

int main()
{
	char c = 'B';
	char str[] = "ABCDEF";
	printf("%s\n", my_strchr(str, c));
	system("pause");
	return 0;
}