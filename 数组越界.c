#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//����Խ�����⣺���ܵ�����ѭ��
//VC 6.0 ��Խ��1λ�����գ�
//Linux gcc ��Խ��2λ����1��
//VS ��Խ��3λ����2��

//����Խ�磬&i == &arr[12], ���Ϊ��ѭ��

int main()
{
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 1;
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}