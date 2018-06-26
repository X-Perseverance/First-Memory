#ifndef __game_h__
#define __game_h__

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void InitBoard(char board[ROW][COL], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
int ComputerMove(char board[ROW][COL], int row, int col);
int CheckWin(char board[ROW][COL], int row, int col);

#endif  //__game_h__