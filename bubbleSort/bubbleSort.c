#include <stdio.h>

void trace(int array[], int array_length) {
  for (int i = 0; i < array_length; i++) {
    printf("%d ",array[i]);
  }
  printf("\n");
}

// 間違えて劣化挿入ソートを作ってしまった。
void bubbleSort(int array[], int array_length) {
  int compare_count = 0;
  for(int i = 1; i < array_length; i++) {
    for(int j = i-1; j >= 0; j--) {
      if(array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
        trace(array, array_length);
      }
      compare_count++;
    }
  }
  printf("compare_count : %d\n", compare_count);
}

void bubbleSort2(int array[], int array_length) {
  int flag = 1;
  int compare_count = 0;
  while(flag == 1) {
    flag = 0;
    for(int j = array_length-1; j >= 1; j--) {
      if (array[j] < array[j-1]) {
        int temp = array[j];
        array[j] = array[j-1];
        array[j-1] = temp;
        flag = 1;
        trace(array, array_length);
      }
      compare_count++;
    }
  }
  printf("compare_count : %d\n", compare_count);
}

int main(void) {
  int array[] = {5, 2, 6, 3, 4, 1};
  trace(array, 6);

  bubbleSort2(array, 6);
}
