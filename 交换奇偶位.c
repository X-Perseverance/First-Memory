#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// ( (num)& 0xaaaaaaaa ) >> 1   取偶数位后右移
// ( (num)& 0x55555555 ) << 1   取奇数位后左移

#define Swap(N) ((N &(0x55555555))<<1)|((N &(0xaaaaaaaa))>>1)

int main()
{
	int num = 0;
	printf("请输入一个数: ");
	scanf("%d", &num);
	printf("交换后：%d\n", Swap(num));
	system("pause");
	return 0;
}
