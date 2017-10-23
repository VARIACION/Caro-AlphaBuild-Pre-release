#pragma once
#include <string>
using namespace std;
void gotoXY(int x, int y);
void menuComponents();
void printMenu(int &choose);
void menu_PlayervsPlayer(string &player1_name, string &player2_name, char &P1_type, char &P2_type, int &level, int &turn);
void introduction();
void aboutGame();
void processMenu(int &choose, string &player1_name, string &player2_name, char &P1_type, char &P2_type, int &level, int &turn);