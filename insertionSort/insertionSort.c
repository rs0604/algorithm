#include <stdio.h>

// 配列の要素に格納された値を添字順に画面出力する。
void trace(int A[], int N) {
  for(int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}
    
void insertionSort(int A[], int N) {
  for(int i = 1; i < N; i++) {
    int v = A[i];
    while( j >= 0 && A[j] > v )
}

int main(void) {
  int N; // 配列のサイズ
  printf("配列のサイズ :");
  scanf("%d", &N);

  int A[100];
  for(int i = 0; i < N; i++) {
    int tmp;
    printf("配列の要素の値 A[%d] :", i); 
    scanf("%d", &tmp);
    A[i] = tmp;
  }

  trace(A, N);
  //insertionSort(A, N);
}
