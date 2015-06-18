#include "WhiteBoardConsole.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#if _DEBUG
#pragma comment(lib,"WhiteBoardConsole_d.lib")
#else
#pragma comment(lib,"WhiteBoardConsole.lib")
#endif

//주인공 캐릭터 변수
int g_nCharXPos = 30;
int g_nCharYPos = 14;
DWORD g_dwPrevChartime;
int g_nBulletFalg = FALSE;
int g_nBulletXPos;
int g_nBulletYPos;
int g_nBulletKeyFlag = FALSE;
int g_nEnemyXPos;
int g_nEnemyYPos;
DWORD g_dwPrevEnemytime;

void Init()
{
	g_nEnemyXPos = (rand() % 59) + 2;
	g_nEnemyYPos = 0;
}

void DrawUI()
{
	ScreenPrint(0, 0, "▩                                                            ▩");
	ScreenPrint(0, 1, "▩                                                            ▩");
	ScreenPrint(0, 2, "▩                                                            ▩");
	ScreenPrint(0, 3, "▩                                                            ▩");
	ScreenPrint(0, 4, "▩                                                            ▩");
	ScreenPrint(0, 5, "▩                                                            ▩");
	ScreenPrint(0, 6, "▩                                                            ▩");
	ScreenPrint(0, 7, "▩                                                            ▩");
	ScreenPrint(0, 8, "▩                                                            ▩");
	ScreenPrint(0, 9, "▩                                                            ▩");
	ScreenPrint(0, 10, "▩                                                            ▩");
	ScreenPrint(0, 11, "▩                                                            ▩");
	ScreenPrint(0, 12, "▩                                                            ▩");
	ScreenPrint(0, 13, "▩                                                            ▩");
	ScreenPrint(0, 14, "▩                                                            ▩");
	ScreenPrint(0, 15, "▩                                                            ▩");
	ScreenPrint(0, 16, "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");
}

void KeyProc()
{
	if (timeGetTime() - g_dwPrevChartime > 50)
	{
		g_dwPrevChartime = timeGetTime();
		if (GetKeyDownState(VK_LEFT) == KEY_DOWN)
		{
			g_nCharXPos -= 2;
			if (g_nCharXPos < 2) g_nCharXPos = 2;
		}
		if (GetKeyDownState(VK_RIGHT) == KEY_DOWN)
		{
			g_nCharXPos += 2;
		}
		if (GetKeyDownState(VK_UP) == KEY_DOWN)
		{
			g_nCharYPos--;
		}
		if (GetKeyDownState(VK_DOWN) == KEY_DOWN)
		{
			g_nCharYPos++;
		}
		if (GetKeyDownState(VK_SPACE) == KEY_DOWN)
		{
			g_nBulletKeyFlag = TRUE;
		}
		if (GetKeyDownState(VK_SPACE) == KEY_UP)
		{
			if (g_nBulletKeyFlag == TRUE)
			{
				g_nBulletKeyFlag = FALSE;
				if (g_nBulletFalg == FALSE)
				{
					g_nBulletFalg = TRUE;
					g_nBulletXPos = g_nCharXPos;
					g_nBulletYPos = g_nCharYPos - 1;
				}
			}
		}
	}
}

void Update()
{
	if (g_nBulletXPos + 2 > g_nEnemyXPos && g_nBulletXPos < g_nEnemyXPos + 2 && g_nBulletYPos <= g_nEnemyYPos + 1 && g_nBulletYPos + 1 >= g_nEnemyYPos){
		Init();
		g_nBulletFalg = FALSE;
	}
	if (g_nBulletFalg == TRUE)
	{
		g_nBulletYPos--;
		if (g_nBulletYPos < 0) g_nBulletFalg = FALSE;
	}
	if (timeGetTime() - g_dwPrevEnemytime > 300)
	{
		g_dwPrevEnemytime = timeGetTime();
		g_nEnemyYPos++;
		if (g_nEnemyYPos > 15){
			Init();
		}
	}
}

void Draw()
{
	ScreenClear();
	SetColor(11, 0);

	DrawUI();
	SetColor(9, 0);
	ScreenPrint(g_nCharXPos, g_nCharYPos, "▲");
	SetColor(12, 0);
	ScreenPrint(g_nEnemyXPos, g_nEnemyYPos, "▼");
	if (g_nBulletFalg == TRUE)
	{
		SetColor(14, 0);
		ScreenPrint(g_nBulletXPos, g_nBulletYPos, "★");
	}

	ScreenFlipping();
}

int main()
{
	ConsoleInit(80, 20);

	srand((unsigned int)time(NULL));
	Init();
	while (1)
	{
		Update();
		KeyProc();
		Draw();
		Sleep(30);
	}
	ConsoleRelease();
	return 0;
}