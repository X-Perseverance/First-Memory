#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <Windows.h>

enum STATE
{
	NORMAL, //��ͨ
	FOUND_SLASH, //�ҵ�'/'
	C_COMMENT, //Cע�ͷ��	
	CPP_COMMENT, //C++ע�ͷ��
	FOUND_ASTERISK, //�ҵ�'*'
};

void CommentConvert(FILE *pIn, FILE *pOut)
{
	enum STATE state = NORMAL;
	char ch;
	char nextch;
	while (1)
	{
		ch = fgetc(pIn);
		if (ch == EOF) //EOFΪ�ļ�������־
		{
			break;
		}
		switch (state)
		{
		case NORMAL:
			if (ch == '/') //�˴���'/'�Ȳ���������Ϊ���������ַ��ǲ�ȷ����
			{
				state = FOUND_SLASH;
			}
			else
			{
				fputc(ch, pOut);  //����ʱ����ͨ�ַ�ֱ�����������ļ���ȥ
				state = NORMAL;
			}
			break;
		case FOUND_SLASH: //����֮ǰ��'/'û��������
			if (ch == '/') //��1����������ŵ���'/'��˵����C++ע�ͷ�񣬲���Ҫ�ı�
			{
				fprintf(pOut, "//"); //ֱ�ӽ�"//"���������ļ���ȥ
				state = CPP_COMMENT;
			}
			else if (ch == '*') //��2����������ŵ���'*'��˵����C����ע�ͷ����Ҫ�ı�
			{
				fprintf(pOut, "//");  //��"/*"�ĳ�"//"���������ļ���ȥ
				state = C_COMMENT;
			}
			else //��3���������ǰ���������˵��֮ǰ��'/'ֻ��һ����ͨ�ַ�
			{
				fputc('/', pOut); //�Ƚ�֮ǰ��'/'���������ļ���ȥ
				fputc(ch, pOut); //�ٽ���ʱ����ͨ�ַ����������ļ���ȥ
				state = NORMAL;
			}
			break;
		case CPP_COMMENT:
			if (ch == '\n') //�������'\n'��˵��ĳһ���Ѿ���C++ע�ͷ����ע�����
			{
				fputc(ch, pOut); //���'\n'������ļ���ȥ
				state = NORMAL;
			}
			else
			{
				fputc(ch, pOut); //�������ͨ�ַ�����ֱ�����������ļ���ȥ
				state = CPP_COMMENT;
			}
			break;
		case C_COMMENT:
			if (ch == '*') //�˴���'*'�Ȳ���������Ϊ���������ַ��ǲ�ȷ����
			{
				state = FOUND_ASTERISK;
			}
			else
			{
				fputc(ch, pOut); //�������ͨ�ַ�����ֱ�����������ļ���ȥ
				if (ch == '\n') 
					//�˴�Ӧ��ע��һ�£��������'\n'����"//"���������ļ���ȥ
					//ԭ���ǣ�C����ע�ͷ���¿��Զ���ע�ͣ���C++ע�ͷ����ֻ�ܵ���ע��
					//������Ҫ��C����ע�ͷ��ĳ�C++ע�ͷ��ʱ������'\n'��Ҫ����һ����ǰ�����"//"
				{
					fprintf(pOut, "//");
				}
				state = C_COMMENT;
			}
			break;
		case FOUND_ASTERISK: //����֮ǰ��'*'û��������
			if (ch == '/') //��1����������ŵ���'/'��˵��C����ע�ͷ���ѽ����
			{
				nextch = fgetc(pIn); //�˴�ҲӦע��һ�£�C����ע�ͷ����ɺ�Ӧ��Ҫ�ж���һ���ַ��Ƿ���'\n'
				if (nextch != '\n') 
					//�������'\n'��Ӧ�����'\n'������ļ���ȥ
					//ԭ���ǣ�C����ע�ͷ����Ծֲ�ע��
					//��ĳһ�д����ǰһ���ֱ�C����ע�ͷ��ע�ͣ�����һ��������Ч����
					//�����ִ����һ������ô��Ч����Ҳ�ᱻ֮ǰ�Ķ����C++ע�ͷ�񣨵���ע�ͣ���ע�͵�
					//���Խ���취���ǽ���Ч�����Ƶ���һ�У���ֹ��ע��
				{
					fputc('\n', pOut);
				}
				ungetc(nextch, pIn); //��һ����Ϊ����Ҫ�ж���һ���ַ������Զ������һ���ַ����˴�����Ҫ������ַ��黹��������Ϊδ����״̬������ִ�д˲��裬����©����ַ�
				state = NORMAL;
			}
			else if (ch == '*') //��2����������ŵ���'*'��˵��֮ǰ��'*'ֻ��һ����ͨ�ַ�
			{
				fputc('*', pOut); //��֮ǰ��'*'���������ļ���ȥ
				state = FOUND_ASTERISK;
			}
			else //��3����������������������˵��֮ǰ��'*'ֻ��һ����ͨ�ַ�
			{
				fputc('*', pOut); //�Ƚ�֮ǰ��'*'���������ļ���ȥ
				fputc(ch, pOut); //�ٽ���ʱ����ͨ�ַ����������ļ���ȥ
				state = C_COMMENT;
			}
			break;
		}

		const char *messages[] = { "��ͨ", "�ҵ�'/'", "C���ע��", "C++���ע��", "�ҵ�'*'" };
		printf("��ǰ�ַ���%c, ��ǰ״̬:%s\n",ch, messages[state]);
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

	fclose(pOut); //��򿪵��ȹر�
	fclose(pIn);

	system("pause");
	return 0;
}