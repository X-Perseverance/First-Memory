#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ��,������; 
//�����ڵ�10�����ʱ�������������ף���10�η�����ߣ�

int main()
{
	float sn = 100.0;
	float hn = sn/2;
	int times = 0;
	for (times = 2; times <= 10; times++)
	{
		sn = sn + 2 * hn; //��times�����ʱ��������·��
		hn = hn / 2; //��times�η����߶�
	}
	printf("������%f��\n", sn);
	printf("��%d�η����߶�Ϊ%f��\n", times - 1, hn);
	system("pause");
	return 0;
}