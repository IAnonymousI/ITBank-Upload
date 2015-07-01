#include <stdio.h>
#include <Windows.h>

#define ROW 5
#define COL 10

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

#define WALL 0
#define ROAD 1

#define START_XPOS 1
#define START_YPOS 1

typedef struct tagCharData{
	int nXPos;
	int nYPos;
	int nDir;
}CHAR_DATA, *PCHAR_DATA;

void Draw();
void Exploration();

const int arr[ROW][COL] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const char *strCharacter[4] = { ">", "<", "^", "V" };
CHAR_DATA g_stCharData = { START_XPOS, START_YPOS, RIGHT };

int main(){

	system("pause");
	while (1){
		system("cls");

		Draw();
		Exploration();

		Sleep(200);
	}
	system("pause");

	return 0;
}

void Draw(){
	int i, j;
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			if (i == g_stCharData.nYPos && j == g_stCharData.nXPos){
				printf("%s", strCharacter[g_stCharData.nDir]);
			}
			else{
				if (arr[i][j] == WALL){
					printf("#");
				}
				else if (arr[i][j] == ROAD){
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

void Exploration(){
	switch (g_stCharData.nDir){
	case RIGHT:
		if (arr[g_stCharData.nYPos][g_stCharData.nXPos + 1] == ROAD){
			g_stCharData.nXPos++;
		}
		else if (arr[g_stCharData.nYPos + 1][g_stCharData.nXPos] == ROAD){
			g_stCharData.nYPos++;
			g_stCharData.nDir = DOWN;
		}
		else if (arr[g_stCharData.nYPos - 1][g_stCharData.nXPos] == ROAD){
			g_stCharData.nYPos--;
			g_stCharData.nDir = UP;
		}
		else{
			g_stCharData.nDir = LEFT;
		}
		break;
	case LEFT:
		if (arr[g_stCharData.nYPos][g_stCharData.nXPos - 1] == ROAD){
			g_stCharData.nXPos--;
		}
		else if (arr[g_stCharData.nYPos + 1][g_stCharData.nXPos] == ROAD){
			g_stCharData.nYPos++;
			g_stCharData.nDir = DOWN;
		}
		else if (arr[g_stCharData.nYPos - 1][g_stCharData.nXPos] == ROAD){
			g_stCharData.nYPos--;
			g_stCharData.nDir = UP;
		}
		else{
			g_stCharData.nDir = RIGHT;
		}
		break;
	case UP:
		if (arr[g_stCharData.nYPos - 1][g_stCharData.nXPos] == ROAD){
			g_stCharData.nYPos--;
		}
		else if (arr[g_stCharData.nYPos][g_stCharData.nXPos + 1] == ROAD){
			g_stCharData.nXPos++;
			g_stCharData.nDir = RIGHT;
		}
		else if (arr[g_stCharData.nYPos][g_stCharData.nXPos - 1] == ROAD){
			g_stCharData.nXPos--;
			g_stCharData.nDir = LEFT;
		}
		else{
			g_stCharData.nDir = DOWN;
		}
		break;
	case DOWN:
		if (arr[g_stCharData.nYPos + 1][g_stCharData.nXPos] == ROAD){
			g_stCharData.nYPos++;
		}
		else if (arr[g_stCharData.nYPos][g_stCharData.nXPos + 1] == ROAD){
			g_stCharData.nXPos++;
			g_stCharData.nDir = RIGHT;
		}
		else if (arr[g_stCharData.nYPos][g_stCharData.nXPos - 1] == ROAD){
			g_stCharData.nXPos--;
			g_stCharData.nDir = LEFT;
		}
		else{
			g_stCharData.nDir = UP;
		}
		break;
	}
}