#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//原型：char *strcpy(char *strDestination, const char *strSource)
//功能：把从strSource地址开始且含有结束符的字符串复制到以strDestination开始的地址空间中去，’\0’也复制过去

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