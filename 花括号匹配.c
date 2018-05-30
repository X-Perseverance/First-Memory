#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ch = 0;
	int count = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '{')
		{
			count++;
		}
		if (ch == '}' && count == 0)
		{
			printf("不匹配\n");
			system("pause");
			return 0;
		}
		if (ch == '}')
		{
			count--;
		}
	}
	if (count == 0)
	{
		printf("匹配\n");
	}
  system("pause");
  return 0;
}
