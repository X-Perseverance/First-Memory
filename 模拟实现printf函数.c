#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

//模拟实现printf函数

void Print_int(int d) //打印整型
{
	if (d > 9)
	{
		Print_int(d / 10);
	}
	putchar(d % 10 + '0'); //将数字转换成字符，再打印
}

int my_printf(const char* format, ...)
{
	va_list list; //声明
	va_start(list, format); //初始化

	const char* p = format;
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
			case 'd':
			{
						int d = va_arg(list, int);
						Print_int(d);
			}
				break;
			case 'c':
			{
						char ch = va_arg(list, char);
						putchar(ch);
			}
				break;
			case 's':
			{
						char* cp = va_arg(list, char*);
						while (*cp)
						{
							putchar(*cp);
							cp++;
						}
			}
				break;
			default:
				break;
			}
		}
		else
		{
			putchar(*p);
		}
		p++;
	}

	va_end(list);
}

int main()
{
	int a = 10;
	char ch = 'A';
	char* str = "hello world!";
	my_printf("%d, %c, %s\n", a, ch, str);
	system("pause");
	return 0;
}