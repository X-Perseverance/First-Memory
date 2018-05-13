#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <string.h>

//��Ŀ��
//����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿��

void Sort_arr(int *arr, int size)
{
	int *start = arr;
	int *end = arr + size - 1;
	while (start < end)
	{
		while ((*start & 1) == 1) //�ж�ǰ�����Ƿ�Ϊ����
		{
			start++;
		}
		while ((*end & 1) == 0) //�жϺ󲿷��Ƿ�Ϊż��
		{
			end--;
		}
		if (start < end) //����
		{
			*start ^= *end ^= *start ^= *end;
		}
	}
}

int main()
{
	int arr[] = { 5, 10, 15, 20, 25, 30, 35, 45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Sort_arr(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}