#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define SUCCESS 1
#define FAILURE 0

#define REGISTRATION 1
#define MODIFY 2
#define SEARCH 3
#define DELETE 4
#define ALL_SHOW_DATA 5
#define EXIT 6

typedef struct tagPersonInfo{
	char strID[15];
	char strName[20];
	int nAge;
	char strPhone[20];
}PERSON_INFO;

typedef struct tagList{
	struct tagList* pPrev;
	struct tagList* pNext;
	PERSON_INFO stPersonInfo;
}LIST, *PLIST;

typedef struct tagLinkedList{
	PLIST pHead;
	PLIST pTail;
}LINKEDLIST, *PLINKEDLIST;

int ListInit(PLINKEDLIST pLinkedList);
int isValidPersonInfo(PERSON_INFO stPersonInfo);
int isValidStrID(char strID[15]);
int isValidStrName(char strName[15]);
int isValidStrPhone(char strPhone[15]);
int Push(PLINKEDLIST pLinkedList, PERSON_INFO stPersonInfo);
int Release(PLINKEDLIST pLinkedList);

int main(){
	int result;
	int nMainMenu;
	int nSubMenu;
	char tempStrID[15];
	char tempStrName[20];
	char tempStrPhone[20];

	LINKEDLIST LinkedList = { 0, };
	PERSON_INFO stTempPersonInfo;

	result = ListInit(&LinkedList);
	if (result == FAILURE){
		printf("리스트 초기화를 실패하였습니다.\n");
		return 0;
	}

	printf("고객 관리 프로그램\n");

	while (1){
		memset(&stTempPersonInfo, 0, sizeof(PERSON_INFO));
		printf("\n------------------------------------------\n");
		printf("1. 고객 등록\n");
		printf("2. 고객 수정\n");
		printf("3. 고객 조회\n");
		printf("4. 고객 삭제\n");
		printf("5. 전체 조회\n");
		printf("6. 프로그램 종료\n");
		printf("------------------------------------------\n\n");

		printf("> ");
		scanf("%d", &nMainMenu);
		system("cls");

		switch (nMainMenu){
		case REGISTRATION:
			REG:
			printf("고객님의 정보를 입력해 주십시오.\n\n");
			Sleep(2000);
			fflush(stdin);
			printf("주민등록번호(XXXXXX-XXXXXXX): ");
			gets(stTempPersonInfo.strID);
			fflush(stdin);
			printf("성함(예: 홍길동): ");
			gets(stTempPersonInfo.strName);
			printf("연세(예: 21): ");
			scanf("%d", &stTempPersonInfo.nAge);
			fflush(stdin);
			printf("전화번호(XXX-XXXX-XXXX): ");
			gets(stTempPersonInfo.strPhone);
			result = isValidPersonInfo(stTempPersonInfo);
			if (!result){
				printf("고객님의 정보가 올바르지 않아 등록이 실패하였습니다.\n");
			}
			else {
				result = Push(&LinkedList, stTempPersonInfo);
				if (!result){
					printf("Push함수에서 에러가 발생하였습니다.\n");
				}
				else {
					printf("등록을 성공하였습니다.\n");
				}
			}
			while (1){
				printf("무엇을 하시겠습니까?\n\n1. 다시 등록\n2. 메인 메뉴로\n\n>");
				scanf("%d", &nSubMenu);
				if (nSubMenu == 1){
					goto REG;
				}
				else if (nSubMenu == 2){
					break;
				}
			}
		case MODIFY:
			break;
		case SEARCH:
			printf("무엇으로 조회를 하시겠습니까?\n\n1. 주민등록번호\n2. 성함\n3. 전화번호\n\n> ");
			scanf("%d", &nSubMenu);
			if (nSubMenu == 1){
				printf("주민등록번호: ");
				fflush(stdin);
				gets(tempStrID);
			}
			else if (nSubMenu == 2){
				
			}
			else if (nSubMenu == 3){
				
			}
			else{
				printf("잘못 입력하셨습니다. 다시 선택하세요.\n");
				goto 
			}
			break;
		case DELETE:
			break;
		case ALL_SHOW_DATA:
			printf("%15s | %10s | %5s | %15s\n");
			break;
		case EXIT:
			printf("이용해주셔서 감사합니다.\n\n");
			Release(&LinkedList);
			system("pause");
			return 0;
		default:
			printf("잘못 입력하셨습니다. 다시 선택하세요.\n");
			Sleep(3000);
			system("cls");
			break;
		}
	}

	return 0;
}

int ListInit(PLINKEDLIST pLinkedList){
	if (pLinkedList == NULL){
		printf("pLinkedList is NULL\n");
		return FAILURE;
	}
	if (pLinkedList->pHead == NULL){
		pLinkedList->pHead = (PLIST)malloc(sizeof(LIST));
		if (pLinkedList->pHead == NULL){
			printf("메모리 할당 실패");
			return FAILURE;
		}
		memset(pLinkedList->pHead, 0, sizeof(LIST));
	}
	if (pLinkedList->pTail == NULL){
		pLinkedList->pTail = (PLIST)malloc(sizeof(LIST));
		if (pLinkedList->pTail == NULL){
			printf("메모리 할당 실패");
			return FAILURE;
		}
		memset(pLinkedList->pTail, 0, sizeof(LIST));
	}
	pLinkedList->pHead->pNext = pLinkedList->pTail;
	pLinkedList->pTail->pPrev = pLinkedList->pHead;
	return SUCCESS;
}

int isValidPersonInfo(PERSON_INFO stPersonInfo){
	if (isValidStrID){
		printf("고객님의 주민등록번호가 올바르지 않습니다.\n");
	}
	if (testStrName == 0){
		printf("고객님의 이름이 올바르지 않습니다.\n");
	}
	if (testStrPhone == 0){
		printf("고객님의 전화번호가 올바르지 않습니다.\n");
	}
	if (!testStrID || !testStrName || !testStrPhone){
		return FAILURE;
	}
	return SUCCESS;
}

int isValidStrID(char strID[15]){
	int i;
	int testStrID = 1;
	if (strID[6] != '-'){
		testStrID = 0;
	}
	for (i = 0; i < (sizeof(strID) / sizeof(strID[0])); i++){
		if (strID[i] == ' '){
			testStrID = 0;
		}
	}
	return testStrID;
}

int isValidStrName(char strName[15]){
	int i;
	int testStrName = 1;
	for (i = 0; i < (sizeof(strName) / sizeof(strName[0])); i++){
		if (strName[i] == ' '){
			testStrName = 0;
		}
	}
	return testStrName;
}

int isValidStrPhone(char strPhone[15]){
	int i;
	int testStrPhone = 1;
	for (i = 0; i < (sizeof(strPhone) / sizeof(strPhone[0])); i++){
		if (strPhone[i] == ' '){
			testStrPhone = 0;
		}
	}
	return testStrPhone;
}

int Push(PLINKEDLIST pLinkedList, PERSON_INFO stPersonInfo){
	PLIST pNewList = (PLIST)malloc(sizeof(LIST));
	if (pNewList == NULL){
		printf("Push함수에서 메모리 할당 실패\n");
		return FAILURE;
	}
	memcpy(pNewList->stPersonInfo.strID, stPersonInfo.strID, sizeof(stPersonInfo.strID));
	memcpy(pNewList->stPersonInfo.strName, stPersonInfo.strName, sizeof(stPersonInfo.strName));
	pNewList->stPersonInfo.nAge = stPersonInfo.nAge;
	memcpy(pNewList->stPersonInfo.strPhone, stPersonInfo.strPhone, sizeof(stPersonInfo.strPhone));
	pNewList->pPrev = pLinkedList->pTail->pPrev;
	pNewList->pNext = pLinkedList->pTail;
	pLinkedList->pTail->pPrev->pNext = pNewList;
	pLinkedList->pTail->pPrev = pNewList;
	return SUCCESS;
}

int Release(PLINKEDLIST pLinkedList){
	PLIST pCurList = pLinkedList->pHead;
	PLIST pDelList = NULL;
	if (pLinkedList == NULL){
		printf("pLinkedList is NULL\n");
		return FAILURE;
	}
	do {
		pDelList = pCurList->pNext;
		free(pCurList);
		pCurList = pDelList;
	} while (pCurList != pLinkedList->pTail);
	free(pLinkedList->pTail);
	return SUCCESS;
}