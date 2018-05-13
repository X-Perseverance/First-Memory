#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//有一个字符数组的内容为:"student a am i", 请你将数组的内容改为"i am a student"
//要求：
//不能使用库函数，只能开辟有限个空间（空间个数和字符串的长度无关）

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
	Reverse(left, right); //先将字符串整体反转  student a am i --> i ma a tneduts
	while (*tmp)
	{
		left = tmp;
		while ((*tmp != '\0') && (*tmp != ' ')) //找到单词，此处一定要加(*str1 != '\0')条件限制，因为找到最后一个单词的时候，*str1永远也不为空格
		{
			tmp++;
		}
		right = tmp - 1; //此时str1指向单词后方的空格，需要减一才能指向单词的最后一个字母
		Reverse(left, right); //继整体反转后再次反转单词，能使单词拼写顺序恢复过来
		if (*tmp == ' ') //等于空格让指针后移一位否则不能参与下次循环。
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