#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//��һ���ַ����������Ϊ:"student a am i", ���㽫��������ݸ�Ϊ"i am a student"
//Ҫ��
//����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ�

void Reverse(char *start, char *end)
{
	assert(start&&end);
	while (start < end)
	{
		*start ^= *end ^= *start ^= *end;
		start++;
		end--;
	}
}

void ReverseStr(char *str, int size)
{
	assert(str);
	char *tmp = str;
	char *left = str;
	char *right = str + size - 1;
	Reverse(left, right); //�Ƚ��ַ������巴ת  student a am i --> i ma a tneduts
	while (*tmp)
	{
		left = tmp;
		while ((*tmp != '\0') && (*tmp != ' ')) //�ҵ����ʣ��˴�һ��Ҫ��(*str1 != '\0')�������ƣ���Ϊ�ҵ����һ�����ʵ�ʱ��*str1��ԶҲ��Ϊ�ո�
		{
			tmp++;
		}
		right = tmp - 1; //��ʱstr1ָ�򵥴ʺ󷽵Ŀո���Ҫ��һ����ָ�򵥴ʵ����һ����ĸ
		Reverse(left, right); //�����巴ת���ٴη�ת���ʣ���ʹ����ƴд˳��ָ�����
		if (*tmp == ' ') //���ڿո���ָ�����һλ�����ܲ����´�ѭ����
		{
			tmp++;
		}
	}
}

int main()
{
	char arr[] = "student a am i";
	int size = strlen(arr);
	ReverseStr(arr, size);
	printf("%s\n", arr);
	system("pause");
	return 0;
}