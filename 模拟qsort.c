#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int int_cmp(const void *x, const void *y)
{
	int *a = (int *)x;
	int *b = (int *)y;
	return *a > *b ? 1 : (*a < *b ? -1 : 0);
}

int float_cmp(const void *x, const void *y)
{
	float *a = (float *)x;
	float *b = (float *)y;
	return *a > *b ? 1 : (*a < *b ? -1 : 0);
}

int str_cmp(const void *x, const void *y)
{
	char **a = (char **)x;
	char **b = (char **)y;
	return strcmp(*a, *b);
}

static void Swap(void *x, void *y, int size)
{
	char *e1 = (char *)x;
	char *e2 = (char *)y;
	while (size--)
	{
		*e1 ^= *e2 ^= *e1 ^= *e2;
		e1++;
		e2++;
	}
}

void my_sort(void *a, int count, int size, int (*cmp)(const void *elem1, const void *elem2))
{
	assert(a);
	assert(cmp);
	int i = 0;
	int j = 0;
	for (i = 0; i < count; i++)
	{
		int flag = 0;
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp((char *)a + j*size, (char *)a + (j + 1)*size) > 0)
			{
				flag = 1;
				Swap((char *)a + j*size, (char *)a + (j + 1)*size, size);
			}
		}
		if (flag == 0) //优化
		{
			break;
		}
	}
}

int main()
{
	//int a[] = { 5, 3, 9, 11, 8, 10 };
	//float a[] = { 5.6, 8.3, 2.6, 9.1, 11.8, 7.4 };
	char *a[] = { "bbbb", "cccc", "dddd", "aaaa" };
	int len = sizeof(a) / sizeof(a[0]);
	my_sort(a, len, sizeof(char *), str_cmp);

	for (int i = 0; i < len; i++)
	{
		printf("%s ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
