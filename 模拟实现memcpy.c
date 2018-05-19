#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void *my_memcpy(void *dest, const void *src, int count)
{
	assert(dest);
	assert(src);
	char *p = (char *)dest;
	const char *q = (const char *)src;
	while (count--)
	{
		*p = *q;
		p++;
		q++;
	}
	return dest;
}

int main()
{
	int src[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int dest[10] = { 0 };
	my_memcpy(dest, src, sizeof(src));
	system("pause");
	return 0;
}