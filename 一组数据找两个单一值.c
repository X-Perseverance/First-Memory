#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//��Ŀ��
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Σ��ҳ�����������

void Find(int arr[], int size)
{
	int i = 0;
	int num = 0;
	int pos = 0;
	int num1 = 0;
	int num2 = 0;

	for (i = 0; i < size; i++)
	{
		num ^= arr[i];
	}

	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) != 1) //�����֮��������ֶ������������ȳ���1��λ��
		{
			pos++;
		}
		else
		{
			break;
		}
	}

	for (i = 0; i < size; i++)
	{
		//�ֳ�2�������飬ÿ�������鶼����һ��ֻ����һ�ε�����
		if (((arr[i] >> pos) & 1) == 1)
		{
			num1 ^= arr[i];
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	printf("num1=%d num2=%d\n", num1, num2);
}

int main()
{
	int arr[] = { 1, 2, 2, 3, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Find(arr, size);
	system("pause");
	return 0;
}