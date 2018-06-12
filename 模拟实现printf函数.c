#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

//ģ��ʵ��printf����

void Print_int(int d) //��ӡ����
{
	if (d > 9)
	{
		Print_int(d / 10);
	}
	putchar(d % 10 + '0'); //������ת�����ַ����ٴ�ӡ
}

int my_printf(const char* format, ...)
{
	va_list list; //����
	va_start(list, format); //��ʼ��

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