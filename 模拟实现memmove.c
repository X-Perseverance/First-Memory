#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void *my_memmove(void *dest, const void *src, int len)
{
	char *ret = dest;
	if (dest > src && (char *)dest < (char *)src + len) //从右往左拷贝（解决内存区域重叠问题）
	{
		dest = (char *)dest + len - 1;
		src = (char *)src + len - 1;
		while (len--)
		{
			*(char *)dest = *(char *)src;
			dest = (char *)dest - 1;
			src = (char *)src - 1;
		}
	}
	else //从左往右拷贝
	{
		while (len--)
		{
			*(char *)dest = *(char *)src;
			dest = (char *)dest + 1;
			src = (char *)src + 1;
		}
	}
	return ret;
}

int main()
{
	char str1[10] = "1234abcd";
	char str2[10] = { 0 };
	my_memmove(str1 + 1, str1, strlen(str1));
	printf("%s\n", str1);
	system("pause");
	return 0;
}