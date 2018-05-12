#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//��д������
//unsigned int ReverseBit(unsigned int value);
//��������ķ���ֵΪvalue�Ķ�������ʽ�����ҷ�ת���ֵ
//�磺
//��32λ������25�Ķ�������ʽΪ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832

unsigned int ReverseBit(unsigned int value)
{
	int sum = 0;
	int bit = 0;
	for (int i = 0; i < 32; i++)
	{
		sum = sum << 1;
		bit = value & 1;
		sum = sum | bit;
		value = value >> 1;
	}
	return sum;
}

int main()
{
	int value = 0;
	scanf("%d", &value);
	printf("%u\n", ReverseBit(value));
	system("pause");
	return 0;
}