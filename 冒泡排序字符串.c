#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void StringSort(char(*a)[10], int count)
{
	assert(a);
	for (int i = 0; i < count - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < count - i - 1; j++)
		{
			if (strcmp(a[j], a[j + 1])>0)
			{
				flag = 1;
				char tmp[10] = { 0 };
				strcpy(tmp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], tmp);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

int main()
{
	char a[][10] = { "cccc", "aaaa", "dddd", "bbbb" };
	int size = sizeof(a) / sizeof(a[0]);
	StringSort(a, size);
	for (int i = 0; i < size; i++)
	{
		printf("%s ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}