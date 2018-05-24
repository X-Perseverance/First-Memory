#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char a = 1;
	char b = 127;
	char c = a + b;
	printf("%d %d\n", c, a + b); // -128 128
	system("pause");
	return 0;
}

// a:   00000001
// b:   01111111
// a+b: 00000000 00000000 00000000 10000000    128
// c:   10000000
// c整形提升: 11111111 11111111 11111111 10000000  补码
//           11111111 11111111 11111111 01111111  反码
//           10000000 00000000 00000000 10000000  原码 -128
