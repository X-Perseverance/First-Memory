#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//int main()
//{
//	int i = 0;
//	int a = 0, b = 0, c = 0;
//	for (i = 100; i < 1000; i++)
//	{
//		a = i / 100;      //��λ
//		b = i / 10 % 10;  //ʮλ
//		c = i % 10;       //��λ
//		if (i == a*a*a + b*b*b + c*c*c)
//		{
//			printf("%d ", i);
//		}
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < 1000000; i++)
	{
		int sum = 0;
		int count = 1;
		tmp = i;
		while (tmp>9) //ͳ��λ��
		{
			count++;
			tmp = tmp / 10;
		}

		tmp = i; //���¸�ֵ
		while (tmp) //���
		{
			sum = sum + (int)pow(tmp%10, count);
			tmp = tmp / 10;
		}

		if (i == sum) //�ж�ˮ�ɻ���
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}