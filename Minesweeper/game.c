#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)   //初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)   //打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf(" %d ", i);
		if (i != col)
		{
			printf("|");
		}
	}
	printf("\n---|---|---|---|---|---|---|---|---|---\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d |", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != col)
			{
				printf("|");
			}
		}
		if (i != row)
		{
			printf("\n---|---|---|---|---|---|---|---|---|---");
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char board[ROWS][COLS], int row, int col, int count)   //设置雷
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int Surround(char board[ROWS][COLS], int x, int y)   //统计周围雷数量
{
	return board[x - 1][y] + board[x - 1][y - 1] + board[x][y - 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] + board[x][y + 1] + board[x - 1][y + 1] - 8 * '0';
}

void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)  //展开
{
	if (Surround(mine, x, y) == 0)
	{
		show[x][y] = ' ';
		if ((x - 1) > 0 && show[x - 1][y] == '*')
		{
			Expand(mine, show, x - 1, y);
		}
		if ((x - 1) > 0 && (y - 1) > 0 && show[x - 1][y - 1] == '*')
		{
			Expand(mine, show, x - 1, y - 1);
		}
		if ((y - 1) > 0 && show[x][y - 1] == '*')
		{
			Expand(mine, show, x, y - 1);
		}
		if ((x + 1) <= ROW && (y - 1) > 0 && show[x + 1][y - 1] == '*')
		{
			Expand(mine, show, x + 1, y - 1);
		}
		if ((x + 1) <= ROW && show[x + 1][y] == '*')
		{
			Expand(mine, show, x + 1, y);
		}
		if ((x + 1) <= ROW && (y + 1) <= COL && show[x + 1][y + 1] == '*')
		{
			Expand(mine, show, x + 1, y + 1);
		}
		if ((y + 1) <= COL && show[x][y + 1] == '*')
		{
			Expand(mine, show, x, y + 1);
		}
		if ((x - 1) > 0 && (y + 1) <= COL && show[x - 1][y + 1] == '*')
		{
			Expand(mine, show, x - 1, y + 1);
		}
	}
	else
	{
		show[x][y] = Surround(mine, x, y) + '0';
	}
}

void ClearMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int count)   //排雷
{
	int flag = 0;
	while (1)
	{
		int i = 0;
		int j = 0;
		int sum = 0;
		int x = 0;
		int y = 0;
		printf("请输入要排查的x坐标值：");
		scanf("%d",&x);
		printf("请输入要排查的y坐标值：");
		scanf("%d", &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (flag == 0 && mine[x][y] == '1')  //保证第一次排雷不会被雷炸
				{
					flag = 1;
					SetMine(mine, ROW, COL, 1);
					mine[x][y] = '0';
				}
				else if (flag != 0 && mine[x][y] == '1')
				{
					printf("你被雷炸了，游戏失败！\n");
					printf("雷阵分布图如下:\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				else
				{
					flag = 1;
				}
				Expand(mine, show, x, y);  //展开
				system("cls");  //清屏
				PrintBoard(show, ROW, COL);
			}
			else
			{
				printf("该坐标处已排查，请重新输入...\n");
			}
		}
		else
		{
			printf("坐标值超范围，请重新输入...\n");
		}
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (show[i][j] != '*')
				{
					sum++;
				}
			}
		}
		if (sum == row*col - count)
		{
			printf("恭喜扫雷成功！\n");
			break;
		}
	}
}