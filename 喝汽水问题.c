#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//��Ŀ��
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ��

int Num(int money)
{
	int sum = money;
	int empty = money;
	while (empty >= 2)
	{
		sum += (empty / 2);
		empty = (empty / 2) + (empty % 2);
	}
	return sum;
}

int main()
{
	int money = 0;
	printf("�������");
	scanf("%d", &money);
	printf("���Ի�%dƿ����\n", Num(money));
	system("pause");
	return 0;
}