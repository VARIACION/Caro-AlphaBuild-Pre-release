#include "theHeaders\printMap.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;

void rowHorizontal(int size)
{
	int count = 1;
	for (int i = 1; i <= size * 4 + 1; i++)
		if (i == count)
		{
			printf("%c", 179);
			count += 4;
		}
		else printf(" ");
}

void rowConnerandEdge(int size, int left, int middle, int right)
{
	printf("%c", left);
	for (int i = 1; i <= size * 4 - 1; i++)
		if (i % 4 == 0) printf("%c", middle); else printf("%c", 196);
	printf("%c\n", right);
}

void printRow(int size, int num, int count)
{
	if (num == 4)
	{
		rowConnerandEdge(size, 218, 194, 191);
		rowHorizontal(size); printf(" %02d", count);
		printf("\n");
	}
	else if ((num != 4) && (num != size + 3))
	{
		rowConnerandEdge(size, 195, 197, 180);
		rowHorizontal(size);
		if (count > size) count--;
		printf(" %02d", count);
		printf("\n");
	}
	if (num == size + 4) rowConnerandEdge(size, 192, 193, 217);
}

void printMap(char map[26][26], int size)
{
	system("cls");
	printf("  ");
	for (int i = 65; i <= 65 + size - 1; i++)
		cout << (char)i << "   ";
	printf("\n");
	int count = 0;
	for (int i = 4; i <= size + 4; i++)
	{
		count++;
		printRow(size, i, count);
	}
}

void printElement(char map[26][26], int size, int row, int column)
{
	int setPosHorizontal[26]; setPosHorizontal[4] = 2;
	int setPosVertical[26];	setPosVertical[4] = 2;
	for (int i = 5; i <= size; i++)
	{
		setPosHorizontal[i] = setPosHorizontal[i - 1] + 4;
		setPosVertical[i] = setPosVertical[i - 1] + 2;
	}
	COORD coord;	coord.X = setPosHorizontal[column];	coord.Y = setPosVertical[row];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	printf("%c", map[row][column]);
	if (size == 19) { coord.X = 0;	coord.Y = 40; }
	else if (size == 3) { coord.X = 0; coord.Y = 8; }
	else if (size == 10) { coord.X = 0; coord.Y = 22; }
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (int i = 1; i <= 5; i++) printf("                                                  \n");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}