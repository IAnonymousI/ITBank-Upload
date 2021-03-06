﻿#define _CRT_SECURE_NO_WARNINGS

// 6/15/2015

/* 과제1
int main(void)
{
int arr1[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
int arr2[4][2];
int i, j;
for(i = 0; i < 2; i++){
for(j = 0; j < 4; j++){
arr2[j][i] = arr1[i][j];
}
}
for(i = 0; i < 4; i++){
for(j = 0; j < 2; j++){
printf("%d ", arr2[i][j]);
}
printf("\n");
}
return 0;
}*/

/* 과제2
int main(void)
{
int arr1[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
int arr2[4][2];
int i, j;
//Error
for( i = 0; i < 8; i++ )
{
arr2[i%4][i%2] = arr1[i%2][i%4];
}
for( i = 0; i < 4; i++ )
{
for( j = 0; j < 2; j++ )
{
printf( "%d ", arr2[i][j] );
}
printf( "\n" );
}
return 0;
}*/

// 6/16/2015

/* 과제
struct tagPerson{
char strName[10];

char strPhone[10];
int nAge;
char strAddress[40];
};
void Input(struct tagPerson *stPerson);
void ShowData(struct tagPerson *stPerson);
int main(){
struct tagPerson stPerson;
Input(&stPerson);
ShowData(&stPerson);
return 0;
}
void Input(struct tagPerson *stPerson){
printf("이름을 입력하세요: ");
scanf("%s", stPerson->strName);
printf("전화번호를 입력하세요: ");
scanf("%s", stPerson->strPhone);
printf("나이를 입력하세요: ");
scanf("%d", &stPerson->nAge);
fflush(stdin);
printf("주소를 입력하세요: ");
gets(stPerson->strAddress);
}
void ShowData(struct tagPerson *stPerson){
printf("이름: %s\n", stPerson->strName);
printf("전화번호: %s\n", stPerson->strPhone);
printf("나이: %d\n", stPerson->nAge);
printf("주소: %s\n", stPerson->strAddress);
}*/

// 6/17/2015

/* 과제
typedef struct tagWeapon{
	char strName[10];
	int nDamage;
}WEAPON, *PWEAPON, **PPWEAPON;

typedef struct tagCharacter{
	int nDefaultDamage;
	PWEAPON pWeapon;
}CHARACTER, *PCHARACTER, **PPCHARACTER;

void SetData(CHARACTER stCharacter, const int defaultDamage, const PWEAPON pWeapon);
void ShowData(CHARACTER stCharacter);
void ShowData2(PCHARACTER pCharacter);

int main(){
	WEAPON stWeapon = {"나무칼", 5};
	CHARACTER stCharacter = {0, };

	SetData(stCharacter, 1, &stWeapon);
	ShowData(stCharacter);
	ShowData2(&stCharacter);

	return 0;
}

void SetData(CHARACTER stCharacter, const int defaultDamage, const PWEAPON pWeapon){
	stCharacter.nDefaultDamage = defaultDamage;
	stCharacter.pWeapon = pWeapon;
}

void ShowData(CHARACTER stCharacter){
	printf("캐릭터 기본 데미지: %d\n", stCharacter.nDefaultDamage);
	printf("캐릭터 소지 무기: %s\n", stCharacter.pWeapon->strName);
	//여기서 Exception이 일어남
	printf("캐릭터 소지 무기 데미지:%d\n", stCharacter.pWeapon->nDamage);
	printf("캐릭터 총 데미지: %d\n", stCharacter.nDefaultDamage + stCharacter.pWeapon->nDamage);
}

void ShowData2(PCHARACTER pCharacter){
	printf("캐릭터 기본 데미지: %d\n", pCharacter->nDefaultDamage);
	printf("캐릭터 소지 무기: %s\n", pCharacter->pWeapon->strName);
	printf("캐릭터 소지 무기 데미지: %d\n", pCharacter->pWeapon->nDamage);
	printf("캐릭터 총 데미지: %d\n", pCharacter->nDefaultDamage + pCharacter->pWeapon->nDamage);
}*/

// 6/18/2015

/* 연습1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int arr[3] = {0, };
	int* p;
	int i;
	p = (int*)malloc(sizeof(int) * 3);
	memset(p, 0, sizeof(int) * 3);

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	p[0] = 10;
	p[1] = 20;
	p[2] = 30;
	printf("%d\n", p[0]);
	printf("%d\n", p[1]);
	printf("%d\n", p[2]);

	free(p);
	p = (int*)malloc(sizeof(int) * 2);
	free(p);

	return 0;
}*/

/* 연습2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagData{
	int nData;
}DATA, *PDATA;

int main(){

	DATA arr[3];
	PDATA p;
	int i;
	p = (PDATA)malloc(sizeof(DATA) * 3);
	memset(p, 0, sizeof(DATA) * 3);
	arr[0].nData = 10;
	arr[1].nData = 20;
	arr[2].nData = 30;

	//똑같은 코드
	//p->nData = 10;
	//(*(p + 0)).nData = 10;
	//(p + 0)->nData = 10;
	p[0].nData = 10;

	p[1].nData = 20;
	p[2].nData = 30;

	for (i = 0; i < 3; i++){
		printf("%d\n", p[i].nData);
	}
	free(p);

	return 0;
}*/

// 6/22/2015

/* 과제1
#include <stdio.h>

#define DATA_MAX 5

typedef struct tagArrayList {
	int arrData[DATA_MAX];
	int nTotal;
}ARRAY_LIST, *PARRAY_LIST;

void ListAdd(PARRAY_LIST pArrayList, const int nData);
void ShowAllList(const PARRAY_LIST pArrayList);
void ListBackRemove(PARRAY_LIST pArrayList);
void ListFrontRemove(PARRAY_LIST pArrayList);
void ListMiddleRemove(PARRAY_LIST pArrayList, const int nIndex);
void ListInsert(PARRAY_LIST pArrayList, const int nIndex, const int nData);

int main()
{
	ARRAY_LIST arrList = { 0, };
	ListAdd(&arrList, 5);
	ListAdd(&arrList, 1);
	ListAdd(&arrList, 4);
	ListAdd(&arrList, 3);
	ListAdd(&arrList, 2);
	ShowAllList(&arrList);

	ListBackRemove(&arrList);
	ShowAllList(&arrList);

	ListFrontRemove(&arrList);
	ShowAllList(&arrList);

	ListMiddleRemove(&arrList, 1);
	ShowAllList(&arrList);

	ListInsert(&arrList, 1, 100);
	ShowAllList(&arrList);

	getch();

	return 0;
}

void ListAdd(PARRAY_LIST pArrayList, const int nData)
{
	if (pArrayList->nTotal >= DATA_MAX)
	{
		printf("리스트가 가득 찼습니다.\n");
		return;
	}
	pArrayList->arrData[pArrayList->nTotal] = nData;
	pArrayList->nTotal++;
}

void ShowAllList(const PARRAY_LIST pArrayList)
{
	int i;
	if (pArrayList->nTotal == 0)
	{
		printf("리스트 요소가 비어 있습니다.\n");
		return;
	}
	printf("리스트 전체 요소 출력\n");
	for (i = 0; i < pArrayList->nTotal; i++)
	{
		printf("%d\n", pArrayList->arrData[i]);
	}
}

void ListBackRemove(PARRAY_LIST pArrayList)
{
	if (pArrayList->nTotal == 0)
	{
		printf("리스트 요소가 비어 있습니다.\n");
		return;
	}
	pArrayList->arrData[pArrayList->nTotal - 1] = 0;
	pArrayList->nTotal--;
	printf("리스트의 마지막 요소를 삭제했습니다.\n");
}

void ListFrontRemove(PARRAY_LIST pArrayList)
{
	int i;
	if (pArrayList->nTotal == 0)
	{
		printf("리스트 요소가 비어 있습니다.\n");
		return;
	}
	for (i = 0; i < pArrayList->nTotal - 1; i++)
	{
		pArrayList->arrData[i] = pArrayList->arrData[i + 1];
	}
	pArrayList->arrData[pArrayList->nTotal - 1] = 0;
	pArrayList->nTotal--;
	printf("리스트의 첫번째 요소를 삭제했습니다.\n");
}

void ListMiddleRemove(PARRAY_LIST pArrayList, const int nIndex)
{
	int i;
	if (nIndex < 0 || nIndex >= pArrayList->nTotal)
	{
		printf("nIndex 값이 잘못 되었습니다.\n");
		return;
	}
	if (pArrayList->nTotal == 0)
	{
		printf("리스트 요소가 비어 있습니다.\n");
		return;
	}
	for (i = nIndex; i < pArrayList->nTotal - 1; i++)
	{
		pArrayList->arrData[i] = pArrayList->arrData[i + 1];
	}
	pArrayList->arrData[pArrayList->nTotal - 1] = 0;
	pArrayList->nTotal--;
	printf("리스트의 %d번째 요소를 삭제했습니다.\n", nIndex);
}

void ListInsert(PARRAY_LIST pArrayList, const int nIndex, const int nData)
{
	int i;
	if (nIndex < 0 || nIndex >= pArrayList->nTotal)
	{
		printf("nIndex 값이 잘못 되었습니다.\n");
		return;
	}
	if (pArrayList->nTotal >= DATA_MAX)
	{
		printf("리스트가 가득 찼습니다.\n");
		return;
	}
	for (i = pArrayList->nTotal; i > nIndex; i--){
		pArrayList->arrData[i] = pArrayList->arrData[i - 1];
	}
	pArrayList->arrData[nIndex] = nData;
	pArrayList->nTotal++;
}*/

/* 과제2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagList {
	int *pData;
	int nTotal;
}LIST, *PLIST;

void ListAdd(PLIST pList, const int nData);
void ShowAllList(PLIST pList);

int main()
{
	LIST List = { 0, };
	ListAdd(&List, 5);
	ListAdd(&List, 1);
	ListAdd(&List, 4);
	ListAdd(&List, 3);
	ListAdd(&List, 2);
	ShowAllList(&List);

	if (List.pData != NULL)
	{
		free(List.pData);
		List.pData = NULL;
	}
	return 0;
}

void ListAdd(PLIST pList, const int nData)
{
	int i;
	int *p = NULL;
	p = (int*)malloc(sizeof(int) * (pList->nTotal + 1));
	if (p == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}
	memset(p, 0, sizeof(int) * (pList->nTotal + 1));
	if (pList->pData != NULL)
	{
		for (i = 0; i < pList->nTotal; i++){
			p[i] = pList->pData[i];
		}
		free(pList->pData);
	}
	pList->pData = p;
	pList->pData[pList->nTotal] = nData;
	pList->nTotal++;
	printf("리스트에 %d값을 추가하였습니다.\n", nData);
}

void ShowAllList(PLIST pList){
	int i;
	if (pList->nTotal == 0){
		printf("리스트가 가득 찼습니다.\n");
		return;
	}
	for (i = 0; i < pList->nTotal; i++){
		printf("%d\n", pList->pData[i]);
	}
}*/

// 6/23/2015

/* 과제1/과제2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagList {
	int *pData;
	int nTotal;
}LIST, *PLIST;

void ListAdd(PLIST pList, const int nData);
void ShowAllList(const PLIST pList);
void ListBackRemove(PLIST pList);
void ListFrontRemove(PLIST pList);
void ListMiddleRemove(PLIST pList, const int nIndex);
void ListInsert(PLIST pList, const int nIndex, const int nData);

int main()
{
	LIST List = { 0, };
	ListAdd(&List, 5);
	ListAdd(&List, 1);
	ListAdd(&List, 4);
	ListAdd(&List, 3);
	ListAdd(&List, 2);
	ShowAllList(&List);

	ListBackRemove(&List);
	ShowAllList(&List);

	ListFrontRemove(&List);
	ShowAllList(&List);

	ListMiddleRemove(&List, 2);
	ShowAllList(&List);

	ListInsert(&List, 1, 100);
	ShowAllList(&List);

	getch();

	if (List.pData != NULL)
	{
		free(List.pData);
		List.pData = NULL;
	}
	return 0;
}

void ListAdd(PLIST pList, const int nData)
{
	int *p = NULL;
	p = (int*)malloc(sizeof(int) * (pList->nTotal + 1));
	if (p == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}
	memset(p, 0, sizeof(int) * (pList->nTotal + 1));
	if (pList->pData != NULL)
	{
		//memcpy 인자값들: (복사를 받을 대상의 시작 주소값, 복사를 할 원본 메모리의 시작 주소값, 복사할 메모리의 사이즈)
		memcpy(p, pList->pData, sizeof(int) * pList->nTotal);
		free(pList->pData);
	}
	pList->pData = p;
	pList->pData[pList->nTotal] = nData;
	pList->nTotal++;
	printf("리스트에 %d값을 추가하였습니다.\n", nData);
}

void ShowAllList(const PLIST pList){
	int i;
	if (pList->nTotal == 0){
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	printf("리스트 전체 요소 출력\n");
	for (i = 0; i < pList->nTotal; i++){
		printf("%d\n", pList->pData[i]);
	}
}

void ListBackRemove(PLIST pList){
	int* p = NULL;
	if (pList->nTotal == 0){
		printf("리스트가 요소가 비어 있습니다.\n");
		return;
	}
	if (pList->nTotal == 1){
		free(pList->pData);
		pList->pData = p;
		pList->nTotal--;
		return;
	}
	p = (int*)malloc(sizeof(int) * (pList->nTotal - 1));
	if (p == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}

	memset(p, 0, sizeof(int) * (pList->nTotal - 1));
	memcpy(p, pList->pData, sizeof(int) * (pList->nTotal - 1));
	free(pList->pData);
	pList->pData = p;
	pList->nTotal--;
	printf("리스트 마지막 요소를 삭제했습니다.\n");
}

void ListFrontRemove(PLIST pList){
	int* p = NULL;
	if (pList->nTotal == 0){
		printf("리스트 요소가 비었습니다.");
		return;
	}
	if (pList->nTotal != 1){
		p = (int*)malloc(sizeof(int) * (pList->nTotal - 1));
		if (p == NULL){
			printf("메모리 할당 실패\n");
			return;
		}
		memset(p, 0, sizeof(int) * (pList->nTotal - 1));
		memcpy(p, pList->pData + 1, sizeof(int) * (pList->nTotal - 1));
	}
	free(pList->pData);
	pList->pData = p;
	pList->nTotal--;
	printf("리스트 첫번째 요소를 삭제했습니다.\n");
}

void ListMiddleRemove(PLIST pList, const int nIndex){
	int* p = NULL;
	if (pList->nTotal == 0){
		printf("리스트 요소가 비었습니다.");
		return;
	}
	if (nIndex < 0 || nIndex >= pList->nTotal){
		printf("nIndex의 값이 잘못되었습니다.");
		return;
	}
	if (pList->nTotal != 1){
		p = (int*)malloc(sizeof(int) * (pList->nTotal - 1));
		if (p == NULL){
			printf("메모리 할당 실패\n");
			return;
		}
		memset(p, 0, sizeof(int) * (pList->nTotal - 1));
		memcpy(p, pList->pData, sizeof(int) * nIndex);
		memcpy(p + nIndex, pList->pData + (nIndex + 1), sizeof(int) * ((pList->nTotal - 1) - nIndex));
	}
	free(pList->pData);
	pList->pData = p;
	pList->nTotal--;
	printf("리스트 %d번째 요소를 삭제했습니다.\n", nIndex);
}

void ListInsert(PLIST pList, const int nIndex, const int nData){
	int* p = NULL;
	if (nIndex < 0 || nIndex > pList->nTotal){
		printf("nIndex의 값이 잘못되었습니다.");
		return;
	}
	if (pList->nTotal == 0){
		p = (int*)malloc(sizeof(int));
		if (p == NULL){
			printf("메모리 할당 실패\n");
			return;
		}
		pList->pData[0] = nData;
		return;
	}
	p = (int*)malloc(sizeof(int) * (pList->nTotal + 1));
	if (p == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}
	memset(p, 0, sizeof(int) * (pList->nTotal + 1));
	if (nIndex == 0){
		memcpy(p + 1, pList->pData, sizeof(int) * pList->nTotal);
	}
	else if (nIndex == pList->nTotal){
		memcpy(p, pList->pData, sizeof(int) * pList->nTotal);
	}
	else{
		memcpy(p, pList->pData, sizeof(int) * nIndex);
		memcpy(p + nIndex + 1, pList->pData + nIndex, sizeof(int) * (pList->nTotal - nIndex));
	}
	free(pList->pData);
	pList->pData = p;
	pList->pData[nIndex] = nData;
	pList->nTotal++;
	printf("리스트 %d를 %d번째 요소에 삽입했습니다.\n", nData, nIndex);
}*/

// 6/24/2015

/* 과제
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagList{
	int nData;
	struct tagList* pNext;
}LIST;

typedef struct tagLinkedList{
	LIST* pHead;
	LIST* pTail;
}LINKEDLIST;

void ListInit(LINKEDLIST* pLinkedList);
void ListAdd(LINKEDLIST* pLinkedList, const int nData);
void ShowAllList(LINKEDLIST* pLinkedList);


int main(){
	LINKEDLIST LinkedList = { 0, };
	ListInit(&LinkedList);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 5);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 1);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 4);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 3);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 2);
	ShowAllList(&LinkedList);
	
	getch();
	free(&LinkedList);
	return 0;
}

void ListInit(LINKEDLIST* pLinkedList){
	pLinkedList->pHead = (LIST*)malloc(sizeof(LIST));
	memset(pLinkedList->pHead, 0, sizeof(LIST));

	pLinkedList->pTail = (LIST*)malloc(sizeof(LIST));
	memset(pLinkedList->pTail, 0, sizeof(LIST));

	pLinkedList->pHead->pNext = pLinkedList->pTail;
	pLinkedList->pTail->pNext = NULL;
}

void ListAdd(LINKEDLIST* pLinkedList, const int nData){
	LIST* pNewList = (LIST*)malloc(sizeof(LIST));
	if (pNewList == NULL){
		printf("메모리 할당 실패\n");
		return;
	}

	memset(pNewList, 0, sizeof(LIST));
	pLinkedList->pTail->nData = nData;
	pLinkedList->pTail->pNext = pNewList;
	pLinkedList->pTail = pNewList;
	pLinkedList->pTail->pNext = NULL;
	free(pNewList);
	printf("리스트에 %d의 값을 더하였습니다.\n", nData);
}

void ShowAllList(LINKEDLIST* pLinkedList){
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	printf("리스트 전체 요소 출력\n");
	int i, rep = 1;
	LIST* pLastList = (LIST*)malloc(sizeof(LIST));
	if (pLastList == NULL){
		printf("메모리 할당 실패\n");
		return;
	}
	while (1){
		for (i = 0; i < rep; i++){
			if (i == 0){
				pLastList = pLinkedList->pHead->pNext;
			}
			else{
				pLastList = pLastList->pNext;
			}
		}
		if (pLastList == pLinkedList->pTail){
			return;
		}
		printf("%d\n", pLastList->nData);
		rep++;
	}
}*/

// 6/25/2015

/* 과제1/과제2/과제3/과제4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagList{
	int nData;
	struct tagList* pNext;
}LIST;

typedef struct tagLinkedList{
	LIST* pHead;
	LIST* pTail;
}LINKEDLIST;

void ListInit(LINKEDLIST* pLinkedList);
void ListAdd(LINKEDLIST* pLinkedList, const int nData);
void ShowAllList(LINKEDLIST* pLinkedList);
void ListBackRemove(LINKEDLIST* pLinkedList);
void ListFrontRemove(LINKEDLIST* pLinkedList);
void ListMiddleRemove(LINKEDLIST* pLinkedList, const int nIndex);
void ListInsert(LINKEDLIST* pLinkedList, const int nIndex, const int nData);
void Release(LINKEDLIST* pLinkedList);

int main(){
	LINKEDLIST LinkedList = { 0, };
	ListInit(&LinkedList);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 5);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 1);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 4);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 3);
	ShowAllList(&LinkedList);
	ListAdd(&LinkedList, 2);
	ShowAllList(&LinkedList);
	ListBackRemove(&LinkedList);
	ShowAllList(&LinkedList);
	ListFrontRemove(&LinkedList);
	ShowAllList(&LinkedList);
	ListMiddleRemove(&LinkedList, 1);
	ShowAllList(&LinkedList);
	ListInsert(&LinkedList, 2, 100);
	ShowAllList(&LinkedList);

	Release(&LinkedList);

	getch();

	return 0;
}

void ListInit(LINKEDLIST* pLinkedList){
	pLinkedList->pHead = (LIST*)malloc(sizeof(LIST));
	memset(pLinkedList->pHead, 0, sizeof(LIST));

	pLinkedList->pTail = (LIST*)malloc(sizeof(LIST));
	memset(pLinkedList->pTail, 0, sizeof(LIST));

	pLinkedList->pHead->pNext = pLinkedList->pTail;
	pLinkedList->pTail->pNext = NULL;
}

void ListAdd(LINKEDLIST* pLinkedList, const int nData){
	LIST* pNewList = (LIST*)malloc(sizeof(LIST));
	if (pNewList == NULL){
		printf("메모리 할당 실패\n");
		return;
	}

	memset(pNewList, 0, sizeof(LIST));
	pLinkedList->pTail->nData = nData;
	pLinkedList->pTail->pNext = pNewList;
	pLinkedList->pTail = pNewList;
	pLinkedList->pTail->pNext = NULL;
	printf("리스트에 %d의 값을 더하였습니다.\n", nData);
}

void ShowAllList(LINKEDLIST* pLinkedList){
	LIST* pCurList = pLinkedList->pHead->pNext;
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	printf("리스트 전체 요소 출력\n");
	while (pCurList != pLinkedList->pTail){
		printf("%d\n", pCurList->nData);
		pCurList = pCurList->pNext;
	}
}

void ListBackRemove(LINKEDLIST* pLinkedList){
	LIST* pCurList = pLinkedList->pHead->pNext;
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	while (pCurList->pNext != pLinkedList->pTail){
		pCurList = pCurList->pNext;
	}
	pCurList->nData = 0;
	pCurList->pNext = NULL;
	pLinkedList->pTail = pCurList;
	printf("리스트 마지막 요소를 삭제했습니다.\n");
}

void ListFrontRemove(LINKEDLIST* pLinkedList){
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	pLinkedList->pHead->pNext->nData = 0;
	pLinkedList->pHead = pLinkedList->pHead->pNext;
	printf("리스트 첫번째 요소를 삭제했습니다.\n");
}

void ListMiddleRemove(LINKEDLIST* pLinkedList, const int nIndex){
	LIST* pTempList = NULL;
	LIST* pCurList = pLinkedList->pHead->pNext;
	int rep = 0;
	while (pCurList != pLinkedList->pTail){
		pCurList = pCurList->pNext;
		rep++;
	}
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	if (nIndex < 0 || nIndex >= rep){
		printf("nIndex의 값이 잘못되었습니다.\n");
		return;
	}
	rep = 0;
	pCurList = pLinkedList->pHead;
	while (rep != nIndex){
		pCurList = pCurList->pNext;
		rep++;
	}
	pTempList = pCurList->pNext;
	pCurList->pNext = pCurList->pNext->pNext;
	free(pTempList);
	printf("리스트 %d번째 요소를 삭제했습니다.\n", nIndex);
}

void ListInsert(LINKEDLIST* pLinkedList, const int nIndex, const int nData){
	LIST* pCurList = pLinkedList->pHead->pNext;
	int rep = 0;
	LIST* pTempList = NULL;
	LIST* pNewList = (LIST*)malloc(sizeof(LIST));
	while (pCurList != pLinkedList->pTail){
		pCurList = pCurList->pNext;
		rep++;
	}
	if (nIndex < 0 || nIndex > rep){
		printf("nIndex의 값이 잘못되었습니다.\n");
		return;
	}
	rep = 0;
	pCurList = pLinkedList->pHead;
	while (rep != nIndex){
		pCurList = pCurList->pNext;
		rep++;
	}
	pNewList->nData = nData;
	pTempList = pCurList->pNext;
	pCurList->pNext = pNewList;
	pNewList->pNext = pTempList;
	printf("리스트 %d번째에 %d의 값을 삽입했습니다.\n", nIndex, nData);
}

void Release(LINKEDLIST* pLinkedList){
	LIST* pCurList = pLinkedList->pHead;
	LIST* pTempList = NULL;
	do {
		pTempList = pCurList->pNext;
		free(pCurList);
		pCurList = pTempList;
	} while (pCurList != pLinkedList->pTail);
}*/

// 6/26/2015

// 과제
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagList{
	struct tagList* pPrev;
	struct tagList* pNext;
	int nData;
}LIST, *PLIST;

typedef struct tagLinkedList{
	PLIST pHead;
	PLIST pTail;
}LINKEDLIST, *PLINKEDLIST;

void ListInit(PLINKEDLIST pLinkedList);
void ListAdd(PLINKEDLIST pLinkedList, const int nData);
void ShowAllList(PLINKEDLIST pLinkedList);
void ShowAllList2(PLINKEDLIST pLinkedList);
void ListBackRemove(PLINKEDLIST pLinkedList);
void ListFrontRemove(PLINKEDLIST pLinkedList);
void ListMiddleRemove(PLINKEDLIST pLinkedList, const int nIndex);
void ListInsert(PLINKEDLIST pLinkedList, const int nIndex, const int nData);
void Release(PLINKEDLIST pLinkedList);

int main(){

	LINKEDLIST LinkedList = { 0, };
	ListInit(&LinkedList);

	ListAdd(&LinkedList, 5);
	ListAdd(&LinkedList, 1);
	ListAdd(&LinkedList, 4);
	ListAdd(&LinkedList, 3);
	ListAdd(&LinkedList, 2);
	ShowAllList(&LinkedList);
	ShowAllList2(&LinkedList);

	ListBackRemove(&LinkedList);
	ShowAllList(&LinkedList);
	ShowAllList2(&LinkedList);

	ListFrontRemove(&LinkedList);
	ShowAllList(&LinkedList);
	ShowAllList2(&LinkedList);

	ListMiddleRemove(&LinkedList, 1);
	ShowAllList(&LinkedList);
	ShowAllList2(&LinkedList);

	ListInsert(&LinkedList, 1, 100);
	ShowAllList(&LinkedList);
	ShowAllList2(&LinkedList);

	Release(&LinkedList);

	getch();

	return 0;
}

void ListInit(PLINKEDLIST pLinkedList){
	pLinkedList->pHead = (PLIST)malloc(sizeof(LIST));
	memset(pLinkedList->pHead, 0, sizeof(LIST));
	pLinkedList->pTail = (PLIST)malloc(sizeof(LIST));
	memset(pLinkedList->pTail, 0, sizeof(LIST));

	pLinkedList->pHead->pPrev = NULL;
	pLinkedList->pHead->pNext = pLinkedList->pTail;
	pLinkedList->pTail->pPrev = pLinkedList->pHead;
	pLinkedList->pTail->pNext = NULL;
}

void ListAdd(PLINKEDLIST pLinkedList, const int nData){
	PLIST pNewList = (PLIST)malloc(sizeof(LIST));
	if (pNewList == NULL){
		printf("메모리 할당을 실패했습니다.\n");
		return;
	}
	memset(pNewList, 0, sizeof(LIST));
	pLinkedList->pTail->nData = nData;
	pLinkedList->pTail->pNext = pNewList;
	pNewList->pPrev = pLinkedList->pTail;
	pLinkedList->pTail = pNewList;
}

void ShowAllList(PLINKEDLIST pLinkedList){
	PLIST pCurList = pLinkedList->pHead->pNext;
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어있습니다.\n");
		return;
	}
	printf("리스트 전체 요소 출력\n");
	while (pCurList != pLinkedList->pTail){
		printf("%d\n", pCurList->nData);
		pCurList = pCurList->pNext;
	}
}

void ShowAllList2(PLINKEDLIST pLinkedList){
	PLIST pCurList = pLinkedList->pTail->pPrev;
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어있습니다.\n");
		return;
	}
	printf("리스트 전체 요소 역순으로 출력\n");
	while (pCurList != pLinkedList->pHead){
		printf("%d\n", pCurList->nData);
		pCurList = pCurList->pPrev;
	}
}

void ListBackRemove(PLINKEDLIST pLinkedList){
	PLIST pCurList = pLinkedList->pTail;
	PLIST pDelList = NULL;
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어있습니다.\n");
		return;
	}
	pDelList = pCurList->pPrev;
	pCurList->pPrev = pDelList->pPrev;
	pDelList->pPrev->pNext = pCurList;
	free(pDelList);
}

void ListFrontRemove(PLINKEDLIST pLinkedList){
	PLIST pCurList = pLinkedList->pHead;
	PLIST pDelList = NULL;
	if (pLinkedList->pHead->pNext == pLinkedList->pTail){
		printf("리스트가 비어있습니다.\n");
		return;
	}
	pDelList = pCurList->pNext;
	pCurList->pNext = pDelList->pNext;
	pDelList->pNext->pPrev = pCurList;
	free(pDelList);
}

void ListMiddleRemove(PLINKEDLIST pLinkedList, const int nIndex){
	LIST* pCurList = pLinkedList->pHead;
	LIST* pDelList = NULL;
	int rep = 0;
	if (nIndex < 0) {
		printf("Index값이 잘못되었습니다.\n");
		return;
	}
	if (pLinkedList->pHead->pNext == pLinkedList->pTail) {
		printf("리스트가 비어있습니다.\n");
		return;
	}
	while (pCurList->pNext != pLinkedList->pTail)
	{
		if (rep == nIndex)
			break;
		pCurList = pCurList->pNext;
		rep++;
	}
	if (pCurList->pNext == pLinkedList->pTail) {
		printf("%d번째 리스트는 존재하지 않습니다.\n", nIndex);
		return;
	}
	pDelList = pCurList->pNext;
	pCurList->pNext = pDelList->pNext;
	pDelList->pNext->pPrev = pCurList;
	free(pDelList);
	printf("%d번째 리스트를 삭제했습니다.\n", nIndex);
}

void ListInsert(PLINKEDLIST pLinkedList, const int nIndex, const int nData){
	LIST* pCurList = pCurList = pLinkedList->pHead;
	LIST* pNewList = NULL;
	int rep = 0;
	if (nIndex < 0) {
		printf("index값이 잘못되었습니다.\n");
		return;
	}
	while (pCurList->pNext != pLinkedList->pTail)
	{
		if (rep == nIndex)
			break;
		pCurList = pCurList->pNext;
		rep++;
	}
	if (pCurList->pNext == pLinkedList->pTail) {
		printf("%d번째 리스트는 존재하지 않습니다.\n", nIndex);
		return;
	}
	pNewList = (LIST*)malloc(sizeof(LIST));
	if (pNewList == NULL) {
		printf("메모리 할당 실패\n");
		return;
	}
	pNewList->nData = nData;
	pNewList->pNext = pCurList->pNext;
	pCurList->pNext->pPrev = pNewList;
	pCurList->pNext = pNewList;
	pNewList->pPrev = pCurList;
	printf("%d번째에 리스트를 삽입했습니다.\n", nIndex);
}

void Release(PLINKEDLIST pLinkedList){
	LIST* pCurList = pLinkedList->pHead;
	LIST* pDelList = NULL;
	do {
		pDelList = pCurList->pNext;
		free(pCurList);
		pCurList = pDelList;
	} while (pCurList != pLinkedList->pTail);
}