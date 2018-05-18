#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *my_strstr(const char *src, const char *dest)
{
	assert(src != NULL);
	assert(dest != NULL);
	char *p_src = (char *)src;
	char *p_dest = (char *)dest;
	char *s = NULL;
	if (*dest == '\0')
	{
		return NULL;
	}
	while (*p_src)
	{
		s = p_src; //ÿ����src�в��ҵ���ʼ��ַ
		p_dest = (char *)dest;
		while (*s && *p_dest && (*s == *p_dest))
		{
			s++;
			p_dest++;
		}
		if (*p_dest == '\0') //���ҳɹ�
		{
			return p_src;
		}
		p_src++;
	}
	return NULL; //δ�ҵ�
}

int main()
{
	char dest[] = "abcde";
	char src[] = "abcabcdefg";
	printf("%s\n", my_strstr(src, dest));
	system("pause");
	return 0;
}