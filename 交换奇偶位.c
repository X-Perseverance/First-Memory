#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// ( (num)& 0xaaaaaaaa ) >> 1   ȡż��λ������
// ( (num)& 0x55555555 ) << 1   ȡ����λ������

#define Swap(N) ((N &(0x55555555))<<1)|((N &(0xaaaaaaaa))>>1)

int main()
{
	int num = 0;
	printf("������һ����: ");
	scanf("%d", &num);
	printf("������%d\n", Swap(num));
	system("pause");
	return 0;
}
