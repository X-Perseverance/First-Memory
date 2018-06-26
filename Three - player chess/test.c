#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Menu1()
{
	printf("*******��������Ϸ*******\n");
	printf("**                    **\n");
	printf("**       1.Play       **\n");
	printf("**       0.Exit       **\n");
	printf("**                    **\n");
	printf("************************\n");
}

void Menu2()
{
	printf("********��Ϸģʽ********\n");
	printf("**                    **\n");
	printf("**     1.�������     **\n");
	printf("**     0.��������     **\n");
	printf("**                    **\n");
	printf("************************\n");
}

void Game()
{
	char board[ROW][COL] = { 0 };
	char flag = 0;
	int choice = 0;
	srand((unsigned int)time(NULL));
	Menu2();
	printf("��ѡ��");
	scanf("%d", &choice);
	printf("********��Ϸ��ʼ********\n");
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	switch (choice)
	{
	case 1: 
	{
			while (1)
			{
				printf("�������...\n");
				PlayerMove(board, ROW, COL);
				PrintBoard(board, ROW, COL);
				flag = CheckWin(board, ROW, COL);
				if (flag != ' ')
				{
					break;
				}
				printf("��������...\n");
				ComputerMove(board, ROW, COL);
				PrintBoard(board, ROW, COL);
				flag = CheckWin(board, ROW, COL);
				if (flag != ' ')
				{
					break;
				}
			}
	}
		break;
	case 0:
	{
			  while (1)
			  {
				  printf("��������...\n");
				  ComputerMove(board, ROW, COL);
				  PrintBoard(board, ROW, COL);
				  flag = CheckWin(board, ROW, COL);
				  if (flag != ' ')
				  {
					  break;
				  }
				  printf("�������...\n");
				  PlayerMove(board, ROW, COL);
				  PrintBoard(board, ROW, COL);
				  flag = CheckWin(board, ROW, COL);
				  if (flag != ' ')
				  {
					  break;
				  }
			  }
	}
		break;
	default: printf("ѡ������������ѡ��...\n"); break;
	}
	printf("********��Ϸ����********\n");
	if (flag == 'X')
	{
		printf("���Ӯ\n");
	}
	else if (flag == 'O')
	{
		printf("����Ӯ\n");
	}
	else if (flag == 'Q')
	{
		printf("ƽ��\n");
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