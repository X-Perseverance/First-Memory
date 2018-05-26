#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EXP 0.00000000001 

int main()
{
	float a = 0.0, b = 0.0, c = 0.0;
	printf("请输入系数a,b,c\n");
	scanf("%f %f %f", &a, &b, &c);
	if (a > -EXP && a < EXP) //浮点数和零值的比较
	{
		printf("不是一元二次方程\n");
	}
	else
	{
		float disc = b*b - 4*a*c;
		if (disc >= EXP)
		{
			printf("有两个根：%f %f\n", (-b + sqrt(disc)) / (2 * a), (-b - sqrt(disc)) / (2 * a));
		}
		else if (disc > -EXP && disc < EXP)
		{
			printf("有一个根：%f\n",-b / (2 * a));
		}
		else
		{
			printf("无解\n");
		}
	}
	system("pause");
	return 0;
}