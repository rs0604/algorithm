/*
  選択ソート
*/

#include <stdio.h>

void trace(int array[],int length) {
  for(int i=0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[],int length) {
  for(int i = 0; i < length; i++) {
    int minj = i;
    for(int j = i; j < length; j++) {
      if(array[j] < array[minj]) minj = j;
    }
    swap(&array[i],&array[minj]);
    trace(array, length);
  }
}

int main(void) {
  int N, i, j;
  int A[100];

  printf("length : "); scanf("%d", &N);
  for(i=0; i<N; i++) scanf("%d", &A[i]);

  trace(A,N);
  selectionSort(A,N);

  return 0;
}
