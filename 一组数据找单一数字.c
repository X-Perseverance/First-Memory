#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//һ��������ֻ��һ�����ֳ�����һ��,�����������ֶ��ǳɶԳ��ֵ�,���ҳ�������֣�ʹ��λ���㣩

int main()
{
	int num = 0;
	int arr[] = { 2, 5, 6, 8, 10, 2, 5, 6, 8 };
	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		num ^= arr[i];
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}