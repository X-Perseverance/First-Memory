#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Menu1()
{
	printf("*******三子棋游戏*******\n");
	printf("**                    **\n");
	printf("**       1.Play       **\n");
	printf("**       0.Exit       **\n");
	printf("**                    **\n");
	printf("************************\n");
}

void Menu2()
{
	printf("********游戏模式********\n");
	printf("**                    **\n");
	printf("**     1.玩家先手     **\n");
	printf("**     0.电脑先手     **\n");
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
	printf("请选择：");
	scanf("%d", &choice);
	printf("********游戏开始********\n");
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	switch (choice)
	{
	case 1: 
	{
			while (1)
			{
				printf("玩家走棋...\n");
				PlayerMove(board, ROW, COL);
				PrintBoard(board, ROW, COL);
				flag = CheckWin(board, ROW, COL);
				if (flag != ' ')
				{
					break;
				}
				printf("电脑走棋...\n");
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
				  printf("电脑走棋...\n");
				  ComputerMove(board, ROW, COL);
				  PrintBoard(board, ROW, COL);
				  flag = CheckWin(board, ROW, COL);
				  if (flag != ' ')
				  {
					  break;
				  }
				  printf("玩家走棋...\n");
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
	default: printf("选择有误，请重新选择...\n"); break;
	}
	printf("********游戏结束********\n");
	if (flag == 'X')
	{
		printf("玩家赢\n");
	}
	else if (flag == 'O')
	{
		printf("电脑赢\n");
	}
	else if (flag == 'Q')
	{
		printf("平局\n");
	}
}

int main()
{
	int input = 0;
	do
	{
		Menu1();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1: Game(); break;
		case 0: break;
		default: printf("选择有误，请重新选择...\n"); break;
		}
	} while (input);
	system("pause");
	return 0;
}