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

