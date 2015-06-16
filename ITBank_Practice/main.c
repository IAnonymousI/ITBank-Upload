#include <stdio.h>

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
