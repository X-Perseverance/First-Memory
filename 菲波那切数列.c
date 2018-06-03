#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int Fib1(int num) //Ч�����
{
	if (num < 3)
	{
		return 1;
	}
	return Fib1(num - 1) + Fib1(num - 2);
}

int Fib2(int acc1, int acc2, int num)
{
	if (num < 2)
	{
		return acc1;
	}
	else
	{
		return Fib2(acc2, acc1 + acc2, num - 1);
	}
}

int Fib3(int acc1, int acc2, int num)
{
	if (num < 3)
	{
		return 1;
	}
	else
	{
		int add = 0;
		while (num - 2)
		{
			add = acc1 + acc2;
			acc1 = acc2;
			acc2 = add;
			num--;
		}
		return add;
	}
}

int main()
{
	int num = 0;
	printf("������num��");
	scanf("%d", &num);

	int begin = GetTickCount();
	printf("��%d������%d\n", num, Fib1(num));
	int end = GetTickCount();	
	printf("Fib1��ʱ��%dms\n", end - begin);

	begin = GetTickCount();
	printf("��%d������%d\n", num, Fib2(1, 1, num));
	end = GetTickCount();
	printf("Fib2��ʱ��%dms\n", end - begin);

	begin = GetTickCount();
	printf("��%d������%d\n", num, Fib3(1, 1, num));
	end = GetTickCount();
	printf("Fib3��ʱ��%dms\n", end - begin);

	system("pause");
	return 0;
}