#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//方法一：计数器方式
int my_strlen1(char *s)
{
	int count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return count;
}

//方法二：递归法，不创建临时变量
int my_strlen2(char *s)
{
	if (*s == '\0')
	{
		return 0;
	}
	return (1 + my_strlen2(s + 1));
}

//方法三：指针 - 指针的方式
int my_strlen3(char *s)
{
	char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return p - s;
}
//说明:若两个指针指向同一个数组或同一段内存区域
//当两个指针相减时，得到的是这两个指针之间所经历的元素个数，其中元素个数和两个指针变量的类型有关
//元素个数=两个指针之间所差总字节数/指针类型所占字节数

int main()
{
	char s[] = "abcde";
	int len = my_strlen1(s);
	printf("%d\n", len);
	system("pause");
	return 0;
}