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

int g_nCharXPos = 30;
int g_nCharYPos = 14;
DWORD g_dwPrevChartime;
int g_nBulletFalg[5] = {FALSE, FALSE, FALSE, FALSE, FALSE};
int g_nBulletXPos[5];
int g_nBulletYPos[5];
int g_nBulletKeyFlag[5] = {FALSE, FALSE, FALSE, FALSE, FALSE};
int g_nBulletKeyPressed = 0;
int g_nPowerUpFlag = FALSE;
int g_nPowerUpKeyFlag = FALSE;
int g_nPowerUpItemFlag = FALSE;
int g_nPowerUpPossessionFlag = FALSE;
int g_nPowerUpBulletXPos[59];
int g_nPowerUpBulletYPos;
int g_nPowerUpXPos;
int g_nPowerUpYPos;
int g_nItemXPos;
int g_nItemYPos;
int g_nItemKeyFlag = FALSE;
int g_nEnemyXPos[3];
int g_nEnemyYPos[3];
int g_nCoinXPos;
int g_nCoinYPos;
DWORD g_dwPrevEnemytime;
DWORD g_dwPrevItemtime;
DWORD g_dwPrevPowerUptime;
DWORD g_dwPrevPowerUpBullettime;
char strTemp[100];
int g_nLife = 5;
int g_nTimeElapsed = 1;
int g_nKills = 0;
char strTemp2[100];
char strTemp3[100];
char strTemp4[100];

boolean checkRightBoundary();
boolean checkDownBoundary();
void activatePowerUp();
void Init(i);
void ItemInit();
void CoinInit();
void PowerUpInit();
void PowerUpBulletInit();
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
	PowerUpInit();
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

void activatePowerUp(){
	int i;
	PowerUpBulletInit();
	SetColor(7, 0);
	for (i = 0; i < 59; i++){
		ScreenPrint(g_nPowerUpBulletXPos[i], g_nPowerUpBulletYPos, "O");
	}
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
	srand((unsigned int)time(NULL));
	g_nItemXPos = (rand() % 59) + 10;
	g_nItemYPos = (rand() % 20);
}

void CoinInit(){
	srand((unsigned int)time(NULL));
	g_nCoinXPos = (rand() % 59) + 10;
	g_nCoinYPos = (rand() % 20);
}

void PowerUpInit(){
	srand((unsigned int)time(NULL));
	g_nPowerUpXPos = (rand() % 59) + 10;
	g_nPowerUpYPos = (rand() % 20);
}

void PowerUpBulletInit(){
	int i;
	for (i = 0; i < 60; i++){
		g_nPowerUpBulletXPos[i] = i + 10;
	}
	g_nPowerUpBulletYPos = 19;
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
			g_nCharYPos--;
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
		if (GetKeyDownState(VK_SHIFT) == KEY_DOWN){
			g_nPowerUpKeyFlag = TRUE;
		}
		if (GetKeyDownState(VK_SHIFT) == KEY_UP){
			if (g_nPowerUpKeyFlag = TRUE){
				g_nPowerUpKeyFlag = FALSE;
				if (g_nPowerUpFlag == FALSE && g_nPowerUpPossessionFlag == TRUE){
					g_nPowerUpFlag = TRUE;
					g_nPowerUpPossessionFlag = FALSE;
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
	if (g_nPowerUpItemFlag == TRUE && ((g_nPowerUpXPos == g_nCharXPos) || (g_nPowerUpXPos == (g_nCharXPos + 1))) && (g_nPowerUpYPos == g_nCharYPos)){
		PowerUpInit();
		g_nPowerUpPossessionFlag = TRUE;
		g_nPowerUpItemFlag = FALSE;
	}
	if (timeGetTime() - g_dwPrevPowerUptime > 20000){
		g_dwPrevPowerUptime = timeGetTime();
		g_nPowerUpItemFlag = TRUE;
	}
	if (((g_nCoinXPos == g_nCharXPos) || (g_nCoinXPos == (g_nCharXPos + 1))) && (g_nCoinYPos == g_nCharYPos)){
		CoinInit();
		g_nTimeElapsed += 200;
	}
	if (timeGetTime() - g_dwPrevItemtime > 3000)
	{
		g_dwPrevItemtime = timeGetTime();
		g_nItemKeyFlag = TRUE;
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
	if (timeGetTime() - g_dwPrevEnemytime > 300)
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
	if (g_nPowerUpFlag == TRUE && timeGetTime() - g_dwPrevPowerUpBullettime > 200){
		g_dwPrevPowerUpBullettime = timeGetTime();
		g_nPowerUpBulletYPos++;
		if (g_nPowerUpBulletYPos == 0){
			g_nPowerUpFlag = FALSE;
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
	if (g_nPowerUpItemFlag == TRUE){
		SetColor(1, 0);
		ScreenPrint(g_nPowerUpXPos, g_nPowerUpYPos, "@");
	}
	if (g_nPowerUpFlag == TRUE){
		activatePowerUp();
	}

	sprintf(strTemp, "%d", g_nLife);
	sprintf(strTemp2, "%d", g_nTimeElapsed);
	sprintf(strTemp3, "%d", g_nKills);
	sprintf(strTemp4, "%d", g_nPowerUpPossessionFlag);

	SetColor(15, 0);
	ScreenPrint(0, 22, "Life: ");
	ScreenPrint(6, 22, strTemp);
	ScreenPrint(0, 24, "Score: ");
	ScreenPrint(7, 24, strTemp2);
	ScreenPrint(0, 23, "Kills: ");
	ScreenPrint(7, 23, strTemp3);
	ScreenPrint(0, 21, "Power: ");
	ScreenPrint(7, 21, strTemp4);

	ScreenFlipping();
}

void gameOver(){
	Sleep(3000);
	exit(0);
}