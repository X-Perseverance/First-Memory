#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//����һ��
double Fact(int n)
{
	static double num = 1;
	num *= n;
	return num;
}

int main()
{
	int n = 0;
	printf("������n��");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d! = %.0f\n", i, Fact(i));
	}
	system("pause");
	return 0;
}

//��������
//int main()
//{
//	int n = 0;
//	printf("������n��");
//	scanf("%d", &n);
//	double num = 1, sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		num *= i;
//		printf("%d! = %.0f\n", i, num);
//		sum += num;
//	}
//	printf("�׳˺�Ϊ��%.0f\n", sum);
//	system("pause");
//	return 0;
//}