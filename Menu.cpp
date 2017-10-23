#include "theHeaders\Menu.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <time.h>
using namespace std;

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menuComponents()
{
	printf("%c           00. Tat nhac nen              %c\n", 179, 179);	gotoXY(75, 16);
	printf("%c           01. Dau voi nguoi             %c\n", 179, 179);	gotoXY(75, 17);
	printf("%c        02. Dau voi may (coming soon)    %c\n", 179, 179);	gotoXY(75, 18);
	printf("%c             03. Huong dan               %c\n", 179, 179);	gotoXY(75, 19);
	printf("%c             04. Thong tin               %c\n", 179, 179);	gotoXY(75, 20);
	printf("%c               05. Thoat                 %c\n", 179, 179);	gotoXY(75, 21);
}

void printMenu(int &choose)
{
	system("cls");
	gotoXY(90, 13);	printf("CARO CHESS\n");
	gotoXY(75, 14);
	printf("%c", 218);
	for (int i = 1; i <= 41; i++)
		printf("%c", 196);
	printf("%c\n", 191);
	gotoXY(75, 15);	menuComponents();
	printf("%c", 195);
	for (int i = 1; i <= 41; i++)
		printf("%c", 196);
	printf("%c\n", 180);
	gotoXY(75, 22);
	printf("%cChon de tiep tuc:                        %c\n", 179, 179);
	gotoXY(75, 23);
	printf("%c", 192);
	for (int i = 1; i <= 41; i++)
		printf("%c", 196);
	printf("%c\n", 217);
	do
	{
		gotoXY(95, 22);
		printf("    ");
		gotoXY(95, 22);
		scanf_s("%d", &choose);
	} while ((choose < 1) && (choose > 5));
	if (choose == 5) return;
	return;
}

void menu_PlayervsPlayer(string &player1_name, string &player2_name, char &P1_type, char &P2_type, int &level, int &turn)
{
	system("cls");	gotoXY(80, 13);	printf("NHAP DU LIEU NGUOI CHOI");
	gotoXY(65, 14);
	printf("%c", 218);
	for (int i = 1; i <= 56; i++) printf("%c", 196);
	printf("%c", 191);	gotoXY(65, 15);
	printf("%cHay nhap ten nguoi choi 1 :                             %c", 179, 179);	gotoXY(65, 16);
	printf("%cHay nhap ten nguoi choi 2 :                             %c", 179, 179);	gotoXY(65, 17);
	printf("%cHay nhap ki tu cho nguoi choi 1:                        %c", 179, 179);
	gotoXY(65, 18);
	printf("%cHay nhap ki tu cho nguoi choi 2:                        %c", 179, 179);
	gotoXY(65, 19);
	printf("%cChon muc do ban co (1: 3x3, 2: 10x10, 3: 19x19):        %c", 179, 179);
	gotoXY(65, 20);
	printf("%c                                                        %c", 179, 179);
	gotoXY(65, 21);
	printf("%c                                                        %c", 179, 179);
	gotoXY(65, 22);
	printf("%c", 192);
	for (int i = 1; i <= 56; i++)
		printf("%c", 196);
	printf("%c\n", 217);
	_flushall();	gotoXY(94, 15);	getline(cin, player1_name);
	do
	{
		_flushall();
		gotoXY(94, 16);
		cout << "               ";
		gotoXY(94, 16);
		getline(cin, player2_name);
	} while (player1_name == player2_name);
	do 
	{ 
		_flushall();
		gotoXY(99, 17);
		cout << "         ";
		gotoXY(99, 17);
		cin >> P1_type;
	} while ((P1_type != 'X') && (P1_type != 'O'));
	if (P1_type == 'X') 
		do 
		{ 
			_flushall();
			gotoXY(99, 18);
			cout << "         ";
			gotoXY(99, 18);
			cin >> P2_type; 
		} while (P2_type != 'O');
	else 
		do 
		{
			_flushall();
			gotoXY(99, 18);
			cout << "         ";
			gotoXY(99, 18);
			cin >> P2_type; 
		} while (P2_type != 'X');
	do
	{
		_flushall();
		gotoXY(115, 19);
		cout << "     ";
		gotoXY(115, 19);
		cin >> level;
	} while ((level < 1) || (level > 3));
	if (level == 1) level = 3; else if (level == 2) level = 10; else level = 19;
	gotoXY(66, 20);
	turn = 0;
	srand(time(NULL));
	while (turn == 0) turn = rand() % 3;
	printf("Nguoi choi %d da duoc chon di truoc.", turn);
	gotoXY(66, 21);
	int countBack = 10;
	while (countBack >= 0)
	{
		gotoXY(66, 21);
		printf("Tran dau se duoc bat dau trong %02d giay nua.", countBack);
		Sleep(1000);
		countBack--;
	}
}

void introduction()
{
	system("cls");	gotoXY(80, 13);
	printf("     HUONG DAN CHOI GAME                 ");
	gotoXY(65, 14);
	printf("%c", 218);
	for (int i = 1; i <= 57; i++) printf("%c", 196);
	printf("%c", 191);	gotoXY(65, 15);
	printf("%cHai nguoi choi se thay phien nhau danh cac nuoc X hoac O %c", 179, 179);	gotoXY(65, 16);
	printf("%cVoi che do ban co 3x3 : nguoi thang cuoc la nguoi danh   %c", 179, 179);	gotoXY(65, 17);
	printf("%cduoc 3 o nuoc cua minh lien tiep theo chieu ngang, doc,  %c", 179, 179);	gotoXY(65, 18);
	printf("%ccheo trai hoac cheo phai dau tien.                       %c", 179, 179);	gotoXY(65, 19);
	printf("%cDoi voi che do ban co 10x10 va 19x19 : nguoi thang cuoc  %c", 179, 179);	gotoXY(65, 20);
	printf("%cla nguoi danh duoc 5 o nuoc cua minh lien tiep theo chieu%c", 179, 179);	gotoXY(65, 21);
	printf("%cngang, doc, cheo trai hoac cheo phai dau tien.           %c", 179, 179);	gotoXY(65, 22);
	printf("%c", 192);
	for (int i = 1; i <= 57; i++)
		printf("%c", 196);
	printf("%c\n", 217);
	gotoXY(65, 23);	system("pause");
}

void aboutGame()
{
	system("cls");	gotoXY(80, 13);
	gotoXY(65, 14);
	printf("%c", 218);
	for (int i = 1; i <= 56; i++) printf("%c", 196);
	printf("%c", 191);
	gotoXY(65, 15);
	printf("%c                  THONG TIN VE GAME                     %c", 179, 179);	gotoXY(65, 16);
	printf("%cDo an cuoi ki Nhap mon lap trinh lop 17CLC2             %c", 179, 179);	gotoXY(65, 17);
	printf("%cMa phien ban : pre-release alpha build 1.0              %c", 179, 179);	gotoXY(65, 18);
	printf("%cMoi thong tin ve phien ban, loi game, vui long lien lac %c", 179, 179);	gotoXY(65, 19);
	printf("%cqua email : huaanhminh0412@gmail.com                    %c", 179, 179);	gotoXY(65, 20);
	printf("%c________________________________________________________%c", 179, 179);	gotoXY(65, 21);
	printf("%cCac thanh vien trong doi ngu phat trien:                %c", 179, 179);	gotoXY(65, 22);
	printf("%cTruong nhom : Hua Anh Minh - Ma so SV : 1753070         %c", 179, 179);	gotoXY(65, 23);
	printf("%cHuong Dat Minh - Ma so SV : 1753071                     %c", 179, 179);	gotoXY(65, 24);
	printf("%cNguyen Ngoc Dang Khanh - Ma so SV : 1753134             %c", 179, 179);	gotoXY(65, 25);
	printf("%cNguyen Cong Phuc - Ma so SV : 1753085                   %c", 179, 179);	gotoXY(65, 26);
	printf("%c________________________________________________________%c", 179, 179);	gotoXY(65, 27);
	printf("%cNhac : NCS (NoCopyrightSounds) Alan Walker - Spectre    %c", 179, 179);	gotoXY(65, 28);
	printf("%c", 192);
	for (int i = 1; i <= 56; i++)
		printf("%c", 196);
	printf("%c\n", 217);
	gotoXY(65, 29); system("pause");
}

void processMenu(int &choose, string &player1_name, string &player2_name, char &P1_type, char &P2_type, int &level, int &turn)
{
	do
	{
		printMenu(choose);
		if (choose == 0)
		{
			if (choose == 0) PlaySound(NULL, 0, 0);
			printMenu(choose);
		}
		if (choose == 1)
		{
			menu_PlayervsPlayer(player1_name, player2_name, P1_type, P2_type, level, turn);
			break;
		}
		else if (choose == 2)
		{
			system("cls");
			gotoXY(95, 13);
			printf("RAT TIEC :(");
			gotoXY(80, 14);
			printf("Tinh nang nay hien chua co, se cap nhat sau.\n");
			gotoXY(80, 15); system("pause");
		}
		else if (choose == 3) introduction();
		else if (choose == 4) aboutGame();
		else break;
	} while (true);
}