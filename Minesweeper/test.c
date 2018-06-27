#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Menu1()
{
	printf("********ɨ����Ϸ********\n");
	printf("**                    **\n");
	printf("**       1.Play       **\n");
	printf("**       0.Exit       **\n");
	printf("**                    **\n");
	printf("************************\n");
}

void Menu2()
{
	printf("********��Ϸ�Ѷ�********\n");
	printf("**                    **\n");
	printf("**   1.Easy (%d����)  **\n",Easy);
	printf("**   2.Hard (%d����)  **\n",Hard);
	printf("**                    **\n");
	printf("************************\n");
}

void Game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	int choice = 0;
	int count = 0;
	srand((unsigned int)time(NULL));
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	Menu2();
	printf("��ѡ��");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1: 
		{
			count = Easy;
			PrintBoard(show, ROW, COL);
			SetMine(mine, ROW, COL, count);
			ClearMine(mine, show, ROW, COL, count);
		}
		break;
	case 2:
	    {
		    count = Hard;
	        PrintBoard(show, ROW, COL);
			SetMine(mine, ROW, COL, count);
			ClearMine(mine, show, ROW, COL, count);
	    }
		break;
	default: printf("ѡ�����������¿�ʼ...\n"); break;
	}
}

int main()
{
	int input = 0;
	do
	{
		Menu1();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1: Game(); break;
		case 0: break;
		default: printf("ѡ������������ѡ��...\n"); break;
		}
	} while (input);
	system("pause");
	return 0;
}