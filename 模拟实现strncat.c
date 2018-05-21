#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *my_strncat(char *dest, const char *src, int count)
{
	assert(src);
	assert(dest);
	char *ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (count-- && (*dest++ = *src++))
	{
		;
	}
	return ret;
}

int main()
{
	char arr[20] = "hello";
	printf("%s\n", my_strncat(arr, arr, strlen(arr)-2));
	system("pause");
	return 0;
}