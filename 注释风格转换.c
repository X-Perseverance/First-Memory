#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <Windows.h>

enum STATE
{
	NORMAL, //普通
	FOUND_SLASH, //找到'/'
	C_COMMENT, //C注释风格	
	CPP_COMMENT, //C++注释风格
	FOUND_ASTERISK, //找到'*'
};

void CommentConvert(FILE *pIn, FILE *pOut)
{
	enum STATE state = NORMAL;
	char ch;
	char nextch;
	while (1)
	{
		ch = fgetc(pIn);
		if (ch == EOF) //EOF为文件结束标志
		{
			break;
		}
		switch (state)
		{
		case NORMAL:
			if (ch == '/') //此处的'/'先不做处理，因为接下来的字符是不确定的
			{
				state = FOUND_SLASH;
			}
			else
			{
				fputc(ch, pOut);  //将此时的普通字符直接输出到输出文件中去
				state = NORMAL;
			}
			break;
		case FOUND_SLASH: //在这之前的'/'没有做处理
			if (ch == '/') //（1）如果紧接着的是'/'，说明是C++注释风格，不需要改变
			{
				fprintf(pOut, "//"); //直接将"//"输出到输出文件中去
				state = CPP_COMMENT;
			}
			else if (ch == '*') //（2）如果紧接着的是'*'，说明是C语言注释风格，需要改变
			{
				fprintf(pOut, "//");  //将"/*"改成"//"输出到输出文件中去
				state = C_COMMENT;
			}
			else //（3）如果不是前两种情况，说明之前的'/'只是一个普通字符
			{
				fputc('/', pOut); //先将之前的'/'输出到输出文件中去
				fputc(ch, pOut); //再将此时的普通字符输出到输出文件中去
				state = NORMAL;
			}
			break;
		case CPP_COMMENT:
			if (ch == '\n') //如果遇到'\n'，说明某一行已经在C++注释风格下注释完成
			{
				fputc(ch, pOut); //输出'\n'到输出文件中去
				state = NORMAL;
			}
			else
			{
				fputc(ch, pOut); //如果是普通字符，就直接输出到输出文件中去
				state = CPP_COMMENT;
			}
			break;
		case C_COMMENT:
			if (ch == '*') //此处的'*'先不做处理，因为接下来的字符是不确定的
			{
				state = FOUND_ASTERISK;
			}
			else
			{
				fputc(ch, pOut); //如果是普通字符，就直接输出到输出文件中去
				if (ch == '\n') 
					//此处应该注意一下，如果遇到'\n'，将"//"输出到输出文件中去
					//原因是：C语言注释风格下可以多行注释，而C++注释风格下只能单行注释
					//当我们要把C语言注释风格改成C++注释风格时，遇到'\n'就要在下一行最前面输出"//"
				{
					fprintf(pOut, "//");
				}
				state = C_COMMENT;
			}
			break;
		case FOUND_ASTERISK: //在这之前的'*'没有做处理
			if (ch == '/') //（1）如果紧接着的是'/'，说明C语言注释风格已将完成
			{
				nextch = fgetc(pIn); //此处也应注意一下，C语言注释风格完成后，应该要判断下一个字符是否是'\n'
				if (nextch != '\n') 
					//如果不是'\n'，应该输出'\n'到输出文件中去
					//原因是：C语言注释风格可以局部注释
					//当某一行代码的前一部分被C语言注释风格注释，而后一部分是有效代码
					//如果不执行这一步，那么有效代码也会被之前改动后的C++注释风格（单行注释）所注释掉
					//所以解决办法就是将有效代码移到下一行，防止被注释
				{
					fputc('\n', pOut);
				}
				ungetc(nextch, pIn); //上一步因为我们要判断下一个字符，所以多访问了一个字符，此处我们要将这个字符归还，将其置为未访问状态，若不执行此步骤，会遗漏这个字符
				state = NORMAL;
			}
			else if (ch == '*') //（2）如果紧接着的是'*'，说明之前的'*'只是一个普通字符
			{
				fputc('*', pOut); //将之前的'*'输出到输出文件中去
				state = FOUND_ASTERISK;
			}
			else //（3）如果不是以上两种情况，说明之前的'*'只是一个普通字符
			{
				fputc('*', pOut); //先将之前的'*'输出到输出文件中去
				fputc(ch, pOut); //再将此时的普通字符输出到输出文件中去
				state = C_COMMENT;
			}
			break;
		}

		const char *messages[] = { "普通", "找到'/'", "C风格注释", "C++风格注释", "找到'*'" };
		printf("当前字符：%c, 当前状态:%s\n",ch, messages[state]);
	}
}

int main()
{
	const char *INPUT = "input.c";
	const char *OUTPUT = "output.c";
	FILE *pIn = fopen(INPUT, "r");
	assert(pIn != NULL);
	FILE *pOut = fopen(OUTPUT, "w");
	assert(pOut != NULL);

	CommentConvert(pIn, pOut);

	fclose(pOut); //后打开的先关闭
	fclose(pIn);

	system("pause");
	return 0;
}