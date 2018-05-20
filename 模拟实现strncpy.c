#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *my_strncpy(char *des, const char *src, int count)
{
	assert(src);
	assert(des);
	char *ret = des;
	while (count && (*des++ = *src++))
	{
		count--;
	}
	if (count>0)
	{
		while (--count)
		{
			*des++ = '\0';
		}
	}
	return ret;
}

int main()
{
	char string[20] = { 0 };
	char arr[] = "hello world";
	printf("String£º%s\n", my_strncpy(string, arr, strlen(arr)));
	system("pause");
	return 0;
}