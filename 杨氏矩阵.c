#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//���Ͼ���
//��һ����ά���飬�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����
//�������������в���һ�������Ƿ���ڣ�ʱ�临�Ӷ�С��O(N)
//
//1 2 3
//4 5 6
//7 8 9

int Search(int arr[][3], int num)
{
	int i = 0, j = 2;
	int key = arr[i][j]; //�������Ͻ�
	while (1)
	{
		if (key == num)
		{
			return 1;
		}
		else if (key < num && i <= 2) //���ڵ�ǰ��
		{
			key = arr[++i][j];
		}
		else if (key > num && j >= 0) //���ڵ�ǰ��
		{
			key = arr[i][--j];
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	int arr[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num = 0;
	printf("������һ������");
	scanf("%d", &num);
	if (num < arr[0][0] || num > arr[2][2])
	{
		printf("����������\n");
		system("pause");
		return 0;
	}
	if (Search(arr, num))
	{
		printf("��������\n");
	}
	else
	{
		printf("����������\n");
	}
	system("pause");
	return 0;
}