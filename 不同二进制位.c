#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//����һ��
//int Different(int num1, int num2)
//{
//	int count = 0;
//	for (int i = 0; i<32; i++)
//	{
//		if (((num1 & 1) ^ (num2 & 1)) == 1)
//		{
//			count++;
//		}
//		num1 >>= 1;
//		num2 >>= 1;
//	}
//	return count;
//}
//
//int main()
//{
//	int m = 0, n = 0;
//	printf("��������������");
//	scanf("%d %d", &m, &n);
//	printf("��%dλ��ͬ\n", Different(m, n));
//	system("pause");
//	return 0;
//}


//��������
int main()
{
	int tmp = 0;
	int m = 0, n = 0, count = 0;
	printf("��������������");
	scanf("%d %d", &m, &n);
	tmp = m^n;
	while (tmp) //����ת��Ϊtmp�Ķ�������ʽ���ж��ٸ�1
	{
		tmp = tmp&(tmp - 1);
		count++;
	}
	printf("��%dλ��ͬ\n", count);
	system("pause");
	return 0;
}