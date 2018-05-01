#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//格雷戈里公式：4*(1-1/3+1/5-1/7 ...)

double Sum()
{
	int a = 1, b = 1;
	double num = 1.0, sum = 0;
	while (fabs(num) >= 0.0000001)
	{
		num = a*1.0 / b;
		sum += num;
		a = -a;
		b += 2;
	}
	return sum;
}

int main()
{
	printf("约为：%f\n", 4 * Sum());
	system("pause");
	return 0;
}
