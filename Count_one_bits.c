#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		count++;
		value = value&(value - 1);   //���λΪ1������ȫΪ0��ѭ��Ч�ʸߣ��м���1��ѭ������
	}
	return count;
}

int main()
{
	int num = 0;
	printf("������һ������: ");
	scanf("%d", &num);
	printf("��������һ����%d��1\n", Count_one_bits(num));
	system("pause");
	return 0;
}