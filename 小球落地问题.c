#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//一球从100米高度自由落下，每次落地后反跳回原高度的一半,再落下; 
//求它在第10次落地时，共经过多少米？第10次反弹多高？

int main()
{
	float sn = 100.0;
	float hn = sn/2;
	int times = 0;
	for (times = 2; times <= 10; times++)
	{
		sn = sn + 2 * hn; //第times次落地时共经过的路程
		hn = hn / 2; //第times次反跳高度
	}
	printf("共经过%f米\n", sn);
	printf("第%d次反弹高度为%f米\n", times - 1, hn);
	system("pause");
	return 0;
}