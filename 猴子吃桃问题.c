#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//һֻ��������10�����ӣ�ÿ���һ���һ�������һ��ֻʣ1�������ܹ��м�������

int main()
{
	int num = 1;
	int day = 10;
	while (--day)
	{
		num = (num + 1) * 2;
	}
	printf("������%d��\n", num);
	system("pause");
	return 0;
}