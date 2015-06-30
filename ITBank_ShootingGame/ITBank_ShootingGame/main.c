#define _CRT_SECURE_NO_WARNINGS

#include "WhiteBoardConsole.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#if _DEBUG
#pragma comment(lib,"WhiteBoardConsole_d.lib")
#else
#pragma comment(lib,"WhiteBoardConsole.lib")
#endif

int g_nCharXPos = 40;
int g_nCharYPos = 15;
DWORD g_dwPrevChartime;
int g_nBulletFalg[5] = {FALSE, FALSE, FALSE, FALSE, FALSE};
int g_nBulletXPos[5];
int g_nBulletYPos[5];
int g_nBulletKeyFlag[5] = {FALSE, FALSE, FALSE, FALSE, FALSE};
int g_nBulletKeyPressed = 0;
int g_nItemXPos;
int g_nItemYPos;
int g_nItemKeyFlag = FALSE;
int g_nEnemyXPos[3];
int g_nEnemyYPos[3];
int g_nCoinXPos;
int g_nCoinYPos;
DWORD g_dwPrevEnemytime;
DWORD g_dwPrevItemtime;
DWORD g_dwPrevCointime;
DWORD g_dwPrevItemtime2;
char strTemp[100];
int g_nLife = 5;
int g_nTimeElapsed = 1;
int g_nKills = 0;
char strTemp2[100];
char strTemp3[100];

boolean checkLeftBoundary();
boolean checkRightBoundary();
boolean checkUpBoundary();
boolean checkDownBoundary();
void Init(i);
void ItemInit();
void CoinInit();
void DrawUI();
void KeyProc();
void Update();
void Draw();
void gameOver();

int main()
{
	int i;
	ConsoleInit(80, 20);

	srand((unsigned int)time(NULL));
	for (i = 0; i < 3; i++){
		Init(i);
	}
	ItemInit();
	CoinInit();
	while (1)
	{
		Update();
		KeyProc();
		Draw();
		Sleep(30);
		g_nTimeElapsed++;
	}
	ConsoleRelease();
	return 0;
}

boolean checkLeftBoundary(){
	boolean indic = 0;
	if (g_nCharXPos < 12){
		indic = 1;
	}
	return indic;
}

boolean checkRightBoundary(){
	boolean indic = 0;
	if (g_nCharXPos > 66){
		indic = 1;
	}
	return indic;
}

boolean checkUpBoundary(){
	boolean indic = 0;
	if (g_nCharYPos <= 0){
		indic = 1;
	}
	return indic;
}

boolean checkDownBoundary(){
	boolean indic = 0;
	if (g_nCharYPos > 18){
		indic = 1;
	}
	return indic;
}

void Init(int i)
{
	g_nEnemyXPos[i] = (rand() % 59) + 10;
	g_nEnemyYPos[i] = 0;
}

void ItemInit(){
	g_nItemXPos = (rand() % 59) + 10;
	g_nItemYPos = 0;
}

void CoinInit(){
	g_nCoinXPos = (rand() % 59) + 10;
	g_nCoinYPos = 0;
}

void DrawUI()
{
	ScreenPrint(0, 0, "         #                                                            #");
	ScreenPrint(0, 1, "         #                                                            #");
	ScreenPrint(0, 2, "         #                                                            #");
	ScreenPrint(0, 3, "         #                                                            #");
	ScreenPrint(0, 4, "         #                                                            #");
	ScreenPrint(0, 5, "         #                                                            #");
	ScreenPrint(0, 6, "         #                                                            #");
	ScreenPrint(0, 7, "         #                                                            #");
	ScreenPrint(0, 8, "         #                                                            #");
	ScreenPrint(0, 9, "         #                                                            #");
	ScreenPrint(0, 10, "         #                                                            #");
	ScreenPrint(0, 11, "         #                                                            #");
	ScreenPrint(0, 12, "         #                                                            #");
	ScreenPrint(0, 13, "         #                                                            #");
	ScreenPrint(0, 14, "         #                                                            #");
	ScreenPrint(0, 15, "         #                                                            #");
	ScreenPrint(0, 16, "         #                                                            #");
	ScreenPrint(0, 17, "         #                                                            #");
	ScreenPrint(0, 18, "         #                                                            #");
	ScreenPrint(0, 19, "         #                                                            #");
	ScreenPrint(0, 20, "         ##############################################################");
}

void KeyProc()
{
	int i;
	if (timeGetTime() - g_dwPrevChartime > 50)
	{
		g_dwPrevChartime = timeGetTime();
		if (GetKeyDownState(VK_LEFT) == KEY_DOWN)
		{
			if (checkLeftBoundary() == 0){
				g_nCharXPos -= 2;
				if (g_nCharXPos < 2) g_nCharXPos = 2;
			}
		}
		if (GetKeyDownState(VK_RIGHT) == KEY_DOWN)
		{
			if (checkRightBoundary() == 0){
				g_nCharXPos += 2;
			}
		}
		if (GetKeyDownState(VK_UP) == KEY_DOWN)
		{
			if (checkUpBoundary() == 0){
				g_nCharYPos--;
			}
		}
		if (GetKeyDownState(VK_DOWN) == KEY_DOWN)
		{
			if (checkDownBoundary() == 0){
				g_nCharYPos++;
			}
		}
		if (GetKeyDownState(VK_SPACE) == KEY_DOWN)
		{
			g_nBulletKeyPressed++;
			g_nBulletKeyFlag[g_nBulletKeyPressed] = TRUE;
		}
		if (GetKeyDownState(VK_SPACE) == KEY_UP)
		{
			for (i = 0; i < 5; i++){
				if (g_nBulletKeyFlag[i] == TRUE)
				{
					g_nBulletKeyFlag[i] = FALSE;
					if (g_nBulletFalg[g_nBulletKeyPressed] == FALSE)
					{
						g_nBulletFalg[g_nBulletKeyPressed] = TRUE;
						g_nBulletXPos[g_nBulletKeyPressed] = g_nCharXPos;
						g_nBulletYPos[g_nBulletKeyPressed] = g_nCharYPos - 1;
					}
				}
			}
		}
	}
}

void Update()
{
	int i, j;
	if (g_nLife <= 0){
		gameOver();
	}
	for (i = 0; i < 3; i++){
		for (j = 0; j < 5; j++){
			if (g_nBulletXPos[j] + 2 > g_nEnemyXPos[i] && g_nBulletXPos[j] < g_nEnemyXPos[i] + 2 && g_nBulletYPos[j] <= g_nEnemyYPos[i] + 1 && g_nBulletYPos[j] + 1 >= g_nEnemyYPos[i]){
				Init(i);  
				g_nBulletFalg[j] = FALSE;
				g_nBulletKeyPressed--;
				g_nKills++;
			}
		}
	}
	for (i = 0; i < 3; i++){
		if (g_nCharXPos + 2 > g_nEnemyXPos[i] && g_nCharXPos < g_nEnemyXPos[i] + 2 && g_nCharYPos <= g_nEnemyYPos[i] + 1 && g_nCharYPos + 1 >= g_nEnemyYPos[i]){
			Init(i);
			g_nLife -= 2;
		}
	}
	if (g_nItemKeyFlag == TRUE && ((g_nItemXPos == g_nCharXPos) || (g_nItemXPos == (g_nCharXPos + 1))) && (g_nItemYPos == g_nCharYPos)){
		ItemInit();
		g_nLife++;
		g_nItemKeyFlag = FALSE;
	}
	if (((g_nCoinXPos == g_nCharXPos) || (g_nCoinXPos == (g_nCharXPos + 1))) && (g_nCoinYPos == g_nCharYPos)){
		CoinInit();
		g_nTimeElapsed += 200;
	}
	if (timeGetTime() - g_dwPrevItemtime > 30000)
	{
		g_dwPrevItemtime = timeGetTime();
		g_nItemKeyFlag = TRUE;
	}
	if (timeGetTime() - g_dwPrevCointime > 300)
	{
		g_dwPrevCointime = timeGetTime();
		g_nCoinYPos++;
		if (g_nCoinYPos > 19){
			CoinInit();
		}
	}
	if (timeGetTime() - g_dwPrevItemtime2 > 500)
	{
		g_dwPrevItemtime2 = timeGetTime();
		g_nItemYPos++;
		if (g_nItemYPos > 19){
			ItemInit();
		}
	}
	for (i = 0; i < 5; i++){
		if (g_nBulletFalg[i] == TRUE)
		{
			g_nBulletYPos[i]--;
			if (g_nBulletYPos[i] < 0){
				g_nBulletFalg[i] = FALSE;
				g_nBulletKeyPressed--;
			}
		}
	}
	if (timeGetTime() - g_dwPrevEnemytime > 400)
	{
		g_dwPrevEnemytime = timeGetTime();
		for (i = 0; i < 3; i++){
			g_nEnemyYPos[i]++;
			if (g_nEnemyYPos[i] > 19){
				Init(i);
				g_nLife--;
			}
		}
	}
}	

void Draw()
{
	int i;
	ScreenClear();
	SetColor(11, 0);

	DrawUI();
	SetColor(9, 0);
	ScreenPrint(g_nCharXPos, g_nCharYPos, "!!");
	SetColor(12, 0);
	for (i = 0; i < 3; i++){
		ScreenPrint(g_nEnemyXPos[i], g_nEnemyYPos[i], "00");
	}
	SetColor(14, 0);
	ScreenPrint(g_nCoinXPos, g_nCoinYPos, "$");
	for (i = 0; i < 5; i++){
		if (g_nBulletFalg[i] == TRUE)
		{
			SetColor(14, 0);
			ScreenPrint(g_nBulletXPos[i], g_nBulletYPos[i], "||");
		}
	}
	if (g_nItemKeyFlag == TRUE){
		SetColor(13, 0);
		ScreenPrint(g_nItemXPos, g_nItemYPos, "+");
	}

	sprintf(strTemp, "%d", g_nLife);
	sprintf(strTemp2, "%d", g_nTimeElapsed);
	sprintf(strTemp3, "%d", g_nKills);

	SetColor(15, 0);
	ScreenPrint(0, 22, "Life: ");
	ScreenPrint(6, 22, strTemp);
	ScreenPrint(0, 24, "Score: ");
	ScreenPrint(7, 24, strTemp2);
	ScreenPrint(0, 23, "Kills: ");
	ScreenPrint(7, 23, strTemp3);

	ScreenFlipping();
}

void gameOver(){
	Sleep(3000);
	exit(0);
}