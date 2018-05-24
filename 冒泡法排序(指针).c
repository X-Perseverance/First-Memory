#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//ָ��-ð�ݷ�����

void Bubble_sort(int *arr, int len)
{
	int *end = arr + len - 1;
	for (; end > arr; end--) //����
	{
		int flag = 0;
		for (int *start = arr; start < end; start++) //�����Ƚ�
		{
			if (*start > *(start + 1))
			{
				flag = 1;
				*start ^= *(start + 1) ^= *start ^= *(start + 1);
			}
		}
		if (flag == 0) //�Ż�
		{
			break;
		}
	}
}

void Print(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 5, 20, 3, 14, 22, 36, 8, 10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr, len);
	Print(arr, len);
	system("pause");
	return 0;
}