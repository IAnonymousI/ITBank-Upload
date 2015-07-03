#include <stdio.h>
#include <Windows.h>

#define ROW 5
#define COL 10

#define SUCCESS 1
#define FAILURE 0

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

typedef struct tagList{
	struct tagList* pPrev;
	CHAR_DATA Data;
	struct tagList* pNext;
}LIST, *PLIST;

typedef struct tagLinkedList{
	PLIST pHead;
	PLIST pTop;
	PLIST pTail;
}LINKEDLIST, *PLINKEDLIST;

int compareCDStructs(CHAR_DATA f, CHAR_DATA s);
CHAR_DATA CreateCDStruct(int x, int y);
int ReverseDirection(int dir);
void ListInit(PLINKEDLIST pLinkedList);
void Ins(PLINKEDLIST pLinkedList, CHAR_DATA Data);
CHAR_DATA SetToPrevious(PLINKEDLIST pLinkedList);
int isFamiliar(PLINKEDLIST pLinkedList, CHAR_DATA Data);
void Draw();
void Exploration(PLINKEDLIST pLinkedList);

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

	LINKEDLIST LinkedList;
	ListInit(&LinkedList);

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

int compareCDStructs(CHAR_DATA f, CHAR_DATA s){
	int sameXPos = 0, sameYPos = 0;
	if (f.nXPos == s.nXPos){
		sameXPos = 1;
	}
	if (f.nYPos = s.nYPos){
		sameYPos = 1;
	}
	if (sameXPos && sameYPos){
		return SUCCESS;
	}
	return FAILURE;
}

CHAR_DATA CreateCDStruct(int x, int y){
	CHAR_DATA newCD;
	memset(&newCD, 0, sizeof(CHAR_DATA));
	newCD.nXPos = x;
	newCD.nYPos = y;
	return newCD;
}

int ReverseDirection(int dir){
	switch (dir){
	case RIGHT:
		return LEFT;
	case LEFT:
		return RIGHT;
	case UP:
		return DOWN;
	case DOWN:
		return UP;
	default:
		return 0;
	}
}

void ListInit(PLINKEDLIST pLinkedList){
	memset(pLinkedList->pHead, 0, sizeof(LIST));
	memset(pLinkedList->pTop, 0, sizeof(LIST));
	memset(pLinkedList->pTail, 0, sizeof(LIST));

	pLinkedList->pHead->pPrev = NULL;
	pLinkedList->pTail->pPrev = pLinkedList->pHead;
	pLinkedList->pHead->pNext = pLinkedList->pTail;
	pLinkedList->pTail->pNext = NULL;
}

void Ins(PLINKEDLIST pLinkedList, CHAR_DATA Data){
	PLIST pNewList = (PLIST)malloc(sizeof(LIST));
	pNewList->Data = Data;
	pNewList->pPrev = pLinkedList->pTop;
	pNewList->pNext = pLinkedList->pTop->pNext;
	pLinkedList->pTop->pNext->pPrev = pNewList;
	pLinkedList->pTop->pNext = pNewList;
	pLinkedList->pTop = pNewList;
}

CHAR_DATA SetToPrevious(PLINKEDLIST pLinkedList){
	CHAR_DATA tempCD;
	pLinkedList->pTop = pLinkedList->pTop->pPrev;
	tempCD = pLinkedList->pTop->Data;
	tempCD.nDir = ReverseDirection(tempCD.nDir);
	return tempCD;
}

int isFamiliar(PLINKEDLIST pLinkedList, CHAR_DATA Data){
	PLIST pCurList = pLinkedList->pHead->pNext;
	while (pCurList != pLinkedList->pTail){
		if (compareCDStructs(pCurList->Data, Data)){
			return SUCCESS;
		}
		pCurList = pCurList->pNext;
	}
	return FAILURE;
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

void Exploration(PLINKEDLIST pLinkedList){
	switch (g_stCharData.nDir){
	case RIGHT:
		if ((arr[g_stCharData.nYPos][g_stCharData.nXPos + 1] == ROAD) && (!isFamiliar(pLinkedList, CreateCDStruct(g_stCharData.nXPos + 1, g_stCharData.nYPos)))){
			g_stCharData.nXPos++;
			Ins(pLinkedList, g_stCharData);
		}
		else if ((arr[g_stCharData.nYPos + 1][g_stCharData.nXPos] == ROAD) && (!isFamiliar(pLinkedList, CreateCDStruct(g_stCharData.nXPos, g_stCharData.nYPos + 1)))){
			g_stCharData.nYPos++;
			g_stCharData.nDir = DOWN;
			Ins(pLinkedList, g_stCharData);
		}
		else if ((arr[g_stCharData.nYPos - 1][g_stCharData.nXPos] == ROAD) && (!isFamiliar(pLinkedList, CreateCDStruct(g_stCharData.nXPos, g_stCharData.nYPos - 1)))){
			g_stCharData.nYPos--;
			g_stCharData.nDir = UP;
			Ins(pLinkedList, g_stCharData);
		}
		else{
			g_stCharData = SetToPrevious(pLinkedList);
		}
		break;
	case LEFT:
		if ((arr[g_stCharData.nYPos][g_stCharData.nXPos - 1] == ROAD) && (!isFamiliar(pLinkedList, CreateCDStruct(g_stCharData.nXPos - 1, g_stCharData.nYPos)))){
			g_stCharData.nXPos--;
			Ins(pLinkedList, g_stCharData);
		}
		else if ((arr[g_stCharData.nYPos + 1][g_stCharData.nXPos] == ROAD) && (!isFamiliar(pLinkedList, CreateCDStruct(g_stCharData.nXPos, g_stCharData.nYPos + 1)))){
			g_stCharData.nYPos++;
			g_stCharData.nDir = DOWN;
			Ins(pLinkedList, g_stCharData);
		}
		else if ((arr[g_stCharData.nYPos - 1][g_stCharData.nXPos] == ROAD) && (!isFamiliar(pLinkedList, CreateCDStruct(g_stCharData.nXPos, g_stCharData.nYPos - 1)))){
			g_stCharData.nYPos--;
			g_stCharData.nDir = UP;
			Ins(pLinkedList, g_stCharData);
		}
		else{
			g_stCharData = SetToPrevious(pLinkedList);
		}
		break;
	case UP:
		if (){
			
		}
		else if (){
			
		}
		else if (){
			
		}
		else{
			
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