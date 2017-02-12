/*
  TODO : 固定長の配列でなく、ポインタを使って動的に決めたい。
  TODO : ソート関数は画面出力するだけではなく、ポインタを渡してメモリ内のデータを入れ替えるようにしたい。
*/

/*
  挿入ソート
  外側のループで、比較元を記憶。
  内側のループで、比較元の移動先を決めるために、値をコピーしてずらす。
*/

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
    int j = i-1;
    while( j >= 0 && A[j] > v ) {
      A[j+1] = A[j];
      j--;
      trace(A, N);
    }
    A[j+1] = v;
    trace(A, N);
  }
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
  insertionSort(A, N);
}
