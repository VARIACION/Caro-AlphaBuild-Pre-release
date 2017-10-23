#include "theHeaders\PlayervsPlayer.h"
#include "theHeaders\printMap.h"
#include "theHeaders\gameState.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void notification(char(&map)[26][26], bool(&available)[26][26], int level, int turn, char player, int &winner)
{
	char column_char;
	int row, column;
	do
	{
		printf("Luot di cua nguoi choi thu %d : ", turn);
		cin >> column_char >> row;
		column = (int)column_char - 61;
		row += 3;
		if ((column < 4) || (column > level + 3)) continue;
		if ((row < 4) || (row > level + 3)) continue;
		map[row][column] = player;
		available[row][column] = true;
		break;
	} while (true);
	printElement(map, level, row, column);
	winner = state(map, row, column, player);
}

int PlayervsPlayer(char(&map)[26][26], bool(&available)[26][26], int &coundIfAvailable, int level, int turn, char P1, char P2)
{
	printMap(map, level);
	int winner;
	while (true)
	{
		if (turn == 1)
		{
			notification(map, available, level, turn, P1, winner);
			if (winner != 0) return winner;
			else turn = 2;
		}
		else
		{
			notification(map, available, level, turn, P2, winner);
			if (winner != 0) return winner;
			else turn = 1;
		}
		coundIfAvailable--;
		if (coundIfAvailable == 0) return 0;
	}
}