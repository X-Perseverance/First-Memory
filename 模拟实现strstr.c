#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *my_strstr(const char *src, const char *dest)
{
	assert(src != NULL);
	assert(dest != NULL);
	char *p_src = (char *)src;
	char *p_dest = (char *)dest;
	char *s = NULL;
	if (*dest == '\0')
	{
		return NULL;
	}
	while (*p_src)
	{
		s = p_src; //每次在src中查找的起始地址
		p_dest = (char *)dest;
		while (*s && *p_dest && (*s == *p_dest))
		{
			s++;
			p_dest++;
		}
		if (*p_dest == '\0') //查找成功
		{
			return p_src;
		}
		p_src++;
	}
	return NULL; //未找到
}

int main()
{
	char dest[] = "abcde";
	char src[] = "abcabcdefg";
	printf("%s\n", my_strstr(src, dest));
	system("pause");
	return 0;
}