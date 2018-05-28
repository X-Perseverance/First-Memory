#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	char arr1[] = "Welcome to China";
	char arr2[] = "****************"; 
	int left = 0;
	int right = strlen(arr1) - 1;
	printf("%s\n", arr2);
	while (left <= right)
	{
		Sleep(1000);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);
	}
	system("pause");
	return 0;
}