#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int Day_of_year(int year, int month, int day)
{
	int s[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
	int i = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0); //�ж�����
	for (int j = 1; j < month; j++)
	{
		day = day + s[i][j];
	}		
	return day;
}

int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	int num = 0;
	printf("�����꣺");
	scanf("%d", &year);
	printf("�����£�");
	scanf("%d", &month);
	printf("�����գ�");
	scanf("%d", &day);
	num = Day_of_year(year, month, day);
	printf("%d-%d-%d�Ǹ���ĵ�%d��\n", year, month, day, num);
	system("pause");
	return 0;
}