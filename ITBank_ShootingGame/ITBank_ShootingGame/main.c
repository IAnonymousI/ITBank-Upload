#include "WhiteBoardConsole.h"
#include <windows.h>
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
int   g_nBulletFalg = FALSE;
int   g_nBulletXPos;
int   g_nBulletYPos;
int   g_nBulletKeyFlag = FALSE;

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
	if (g_nBulletFalg == TRUE)
	{
		g_nBulletYPos--;
		if (g_nBulletYPos < 0) g_nBulletFalg = FALSE;
	}
}

void Draw()
{
	ScreenClear();
	SetColor(11, 0);

	DrawUI();
	SetColor(9, 0);
	ScreenPrint(g_nCharXPos, g_nCharYPos, "▲");
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