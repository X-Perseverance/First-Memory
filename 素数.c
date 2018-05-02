#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i = 0;
	int num = 0;
	for (num = 2; num <= 1000; num++)
	{
		for (i = 2; i <= sqrt(num); i++)
		{
			if (num%i == 0)
			{
				break;
			}
		}
		if (i > sqrt(num))
		{
			printf("%d ", num);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}