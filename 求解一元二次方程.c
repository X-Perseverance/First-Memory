#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EXP 0.00000000001 

int main()
{
	float a = 0.0, b = 0.0, c = 0.0;
	printf("������ϵ��a,b,c\n");
	scanf("%f %f %f", &a, &b, &c);
	if (a > -EXP && a < EXP) //����������ֵ�ıȽ�
	{
		printf("����һԪ���η���\n");
	}
	else
	{
		float disc = b*b - 4*a*c;
		if (disc >= EXP)
		{
			printf("����������%f %f\n", (-b + sqrt(disc)) / (2 * a), (-b - sqrt(disc)) / (2 * a));
		}
		else if (disc > -EXP && disc < EXP)
		{
			printf("��һ������%f\n",-b / (2 * a));
		}
		else
		{
			printf("�޽�\n");
		}
	}
	system("pause");
	return 0;
}