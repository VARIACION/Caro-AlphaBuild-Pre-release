#pragma once
void notification(char(&map)[26][26], bool(&available)[26][26], int level, int turn, char player, int &winner);
int PlayervsPlayer(char (&map)[26][26], bool (&available)[26][26], int &coundIfAvailable, int level, int turn, char P1, char P2);