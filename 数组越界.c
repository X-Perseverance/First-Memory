#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//数组越界问题：可能导致死循环
//VC 6.0 ：越界1位（不空）
//Linux gcc ：越界2位（空1）
//VS ：越界3位（空2）

//数组越界，&i == &arr[12], 结果为死循环

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