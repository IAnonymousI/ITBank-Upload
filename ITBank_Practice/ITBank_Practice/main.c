#define _CRT_SECURE_NO_WARNINGS

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

// 연습2
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
}