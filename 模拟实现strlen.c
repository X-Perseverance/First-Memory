#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//����һ����������ʽ
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

//���������ݹ鷨����������ʱ����
int my_strlen2(char *s)
{
	if (*s == '\0')
	{
		return 0;
	}
	return (1 + my_strlen2(s + 1));
}

//��������ָ�� - ָ��ķ�ʽ
int my_strlen3(char *s)
{
	char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return p - s;
}
//˵��:������ָ��ָ��ͬһ�������ͬһ���ڴ�����
//������ָ�����ʱ���õ�����������ָ��֮����������Ԫ�ظ���������Ԫ�ظ���������ָ������������й�
//Ԫ�ظ���=����ָ��֮���������ֽ���/ָ��������ռ�ֽ���

int main()
{
	char s[] = "abcde";
	int len = my_strlen1(s);
	printf("%d\n", len);
	system("pause");
	return 0;
}