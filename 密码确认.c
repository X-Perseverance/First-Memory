#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int passwd[10] = { 0 };
	int ch = 0;
	printf("���������룺");
	scanf("%s", passwd);
	printf("%s\n", passwd);
	printf("��ȷ��Y/N\n");

	//����һ�������ڴ滺����
	fflush(stdin);

	//���������ֶ����
	//while ((ch = getchar() != '\n') && (ch != EOF))
	//{
	//	;
	//}

	ch = getchar();
	if ('Y' == ch)
	{
		printf("ȷ�ϳɹ�\n");
	}
	else
	{
		printf("ȷ��ʧ��\n");
	}
	system("pause");
	return 0;
}