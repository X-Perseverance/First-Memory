#ifndef __game_h__
#define __game_h__

#include <stdio.h>
#include <time.h>
#include <Windows.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Easy 10
#define Hard 30

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col, int count);
void ClearMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int count);

#endif  //__game_h__