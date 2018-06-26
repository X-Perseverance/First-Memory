#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)   //��ʼ������
{
	memset(board, ' ', row*col*sizeof(board[0][0]));
}

void PrintBoard(char board[ROW][COL], int row, int col)   //��ӡ����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i != row - 1)
		{
			printf("---|---|---\n");
		}
	}
	printf("\n");
}

void PlayerMove(char board[ROW][COL], int row, int col)   //�������
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������x����ֵ��");
		scanf("%d", &x);
		printf("������y����ֵ��");
		scanf("%d", &y);
		x--;  y--;
		if (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = 'X';
				break;
			}
			else
			{
				printf("�����괦��ռ������������...\n");
			}
		}
		else
		{
			printf("������ֵ����Χ������������...\n");
		}
	}
}

int Computer_1(char board[ROW][COL], int row, int col)   //�����ж��Լ��ܷ��������ʤ��
{
	for (int m = 0; m < row; m++)    //��
	{
		if ((board[m][0] == board[m][1]) && (board[m][1] == 'O') && (board[m][2] == ' '))
		{
			board[m][2] = 'O';
			return 1;
		}
		if ((board[m][0] == board[m][2]) && (board[m][2] == 'O') && (board[m][1] == ' '))
		{
			board[m][1] = 'O';
			return 1;
		}
		if ((board[m][1] == board[m][2]) && (board[m][1] == 'O') && (board[m][0] == ' '))
		{
			board[m][0] = 'O';
			return 1;
		}
	}
	for (int n = 0; n < col; n++)    //��
	{
		if ((board[0][n] == board[1][n]) && (board[0][n] == '0') && (board[2][n] == ' '))
		{
			board[2][n] = 'O';
			return 1;
		}
		if ((board[0][n] == board[2][n]) && (board[0][n] == '0') && (board[1][n] == ' '))
		{
			board[1][n] = 'O';
			return 1;
		}
		if ((board[1][n] == board[2][n]) && (board[1][n] == '0') && (board[0][n] == ' '))
		{
			board[0][n] = 'O';
			return 1;
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == 'O') && (board[2][2] == ' '))  //�Խ���(\)
	{
		board[2][2] = 'O';
		return 1;
	}
	if ((board[0][0] == board[2][2]) && (board[2][2] == 'O') && (board[1][1] == ' '))  //�Խ���(\)
	{
		board[1][1] = 'O';
		return 1;
	}
	if ((board[1][1] == board[2][2]) && (board[1][1] == 'O') && (board[0][0] == ' '))  //�Խ���(\)
	{
		board[0][0] = 'O';
		return 1;
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == 'O') && (board[2][0] == ' '))  //�Խ���(/)
	{
		board[2][0] = 'O';
		return 1;
	}
	if ((board[1][1] == board[2][0]) && (board[1][1] == 'O') && (board[0][2] == ' '))  //�Խ���(/)
	{
		board[0][2] = 'O';
		return 1;
	}
	if ((board[0][2] == board[2][0]) && (board[0][2] == 'O') && (board[1][1] == ' '))  //�Խ���(/)
	{
		board[1][1] = 'O';
		return 1;
	}
	return 0;
}

int Computer_2(char board[ROW][COL], int row, int col)       //�����谭���ʤ��
{
	for (int m = 0; m < row; m++)    //��
	{
		if ((board[m][0] == board[m][1]) && (board[m][1] == 'X') && (board[m][2] == ' '))
		{
			board[m][2] = 'O';
			return 1;
		}
		if ((board[m][0] == board[m][2]) && (board[m][2] == 'X') && (board[m][1] == ' '))
		{
			board[m][1] = 'O';
			return 1;
		}
		if ((board[m][1] == board[m][2]) && (board[m][1] == 'X') && (board[m][0] == ' '))
		{
			board[m][0] = 'O';
			return 1;
		}
	}
	for (int n = 0; n < col; n++)    //��
	{
		if ((board[0][n] == board[1][n]) && (board[1][n] == 'X') && (board[2][n] == ' '))
		{
			board[2][n] = 'O';
			return 1;
		}
		if ((board[0][n] == board[2][n]) && (board[2][n] == 'X') && (board[1][n] == ' '))
		{
			board[1][n] = 'O';
			return 1;
		}
		if ((board[1][n] == board[2][n]) && (board[1][n] == 'X') && (board[0][n] == ' '))
		{
			board[0][n] = 'O';
			return 1;
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == 'X') && (board[2][2] == ' '))  //�Խ���(\)
	{
		board[2][2] = 'O';
		return 1;
	}
	if ((board[0][0] == board[2][2]) && (board[2][2] == 'X') && (board[1][1] == ' '))  //�Խ���(\)
	{
		board[1][1] = 'O';
		return 1;
	}
	if ((board[1][1] == board[2][2]) && (board[1][1] == 'X') && (board[0][0] == ' '))  //�Խ���(\)
	{
		board[0][0] = 'O';
		return 1;
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == 'X') && (board[2][0] == ' '))  //�Խ���(/)
	{
		board[2][0] = 'O';
		return 1;
	}
	if ((board[1][1] == board[2][0]) && (board[1][1] == 'X') && (board[0][2] == ' '))  //�Խ���(/)
	{
		board[0][2] = 'O';
		return 1;
	}
	if ((board[0][2] == board[2][0]) && (board[0][2] == 'X') && (board[1][1] == ' '))  //�Խ���(/)
	{
		board[1][1] = 'O';
		return 1;
	}
	return 0;
}

int ComputerMove(char board[ROW][COL], int row, int col)   //��������
{
	if (Computer_1(board, row, col)) return 0;       //��һ���������ж��Լ��ܷ��������ʤ��
	if (Computer_2(board, row, col)) return 0;       //�ڶ����������谭���ʤ��
	//�������������
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
	return 0;
}

int Full(char board[ROW][COL], int row, int col)   //�ж������Ƿ�����
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

int CheckWin(char board[ROW][COL], int row, int col)   //�ж���Ӯ
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (Full(board, row, col))
	{
		return 'Q';
	}
	return ' ';
}