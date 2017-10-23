#include "theHeaders\gameState.h"
#include <iostream>
using namespace std;

int state(char map[26][26], int row, int column, char type)
{
	int count;
	//ngang
	count = 1;
	bool back = true, forward = true;
	int moveBack = column - 1, moveForward = column + 1;
	while ((moveBack >= column - 4) && (moveForward <= column + 4))
	{
		if ((map[row][moveBack] == type) && (back)) count++; else back = false;
		if ((map[row][moveForward] == type) && (forward)) count++; else forward = false;
		if (count == 5) return 1;
		moveBack--;	moveForward++;
	}

	//doc
	count = 1;
	moveBack = row - 1;	moveForward = row + 1;
	back = true; forward = true;
	while ((moveBack >= row - 4) && (moveForward <= row + 4))
	{
		if ((map[moveBack][column] == type) && (back)) count++; else back = false;
		if ((map[moveForward][column] == type) && (forward)) count++; else forward = true;
		if (count == 5) return 1;
		moveBack--; moveForward++;
	}

	//cheo phai
	count = 1;
	moveBack = row - 1;	moveForward = row + 1;
	for (int i = column - 1; i >= column - 4; i--)
	{
		if (map[moveBack][i] == type) count++; else break;
		moveBack--;
	}
	if (count == 5) return 1;
	for (int i = column + 1; i <= column + 4; i++)
	{
		if (map[moveForward][i] == type) count++; else break;
		moveForward++;
	}
	if (count == 5) return 1;

	//cheo trai
	count = 1;
	moveBack = row - 1;	moveForward = row + 1;
	for (int i = column + 1; i <= column + 4; i++)
	{
		if (map[moveBack][i] == type) count++; else break;
		moveBack--;
	}
	if (count == 5) return 1;
	for (int i = column - 1; i >= column - 4; i--)
	{
		if (map[moveForward][i] == type) count++; else break;
		moveForward++;
	}
	if (count == 5) return 1;
	return 0;
}