#include "theHeaders\IO_Process.h"
#include <iostream>
#include <Windows.h>
#include "theHeaders\Menu.h"
#include "theHeaders\PlayervsPlayer.h"
#include <mmsystem.h>
#include <string>
#pragma comment(lib, "user32")
using namespace std;

int Process()
{
	//Initialize the theme for the game (screen mode, music)
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	PlaySound(TEXT("Spectre NCS Release.wav"), NULL, SND_ASYNC);

	//Initialize the setting for the game
	string player1_name, player2_name;
	char P1_type, P2_type;
	int choose, level, turn, countIfAvailable, winner;
	char map[26][26];
	bool available[26][26];

	processMenu(choose, player1_name, player2_name, P1_type, P2_type, level, turn);
	countIfAvailable = level * level;
	if (choose == 1)
		winner = PlayervsPlayer(map, available, countIfAvailable, level, turn, P1_type, P2_type);
	else if (choose == 5) return 0;
	system("cls");
	PlaySound(TEXT("Mini - Game Victory 6.wav"), NULL, SND_ASYNC);
	if (winner == 1) printf("Nguoi choi 1 thang.\n");
	else if (winner == 2) printf("Nguoi choi 2 thang.\n");
	else printf("Tran dau hoa.\n");
	system("pause");
}