#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>
// We can do this operation on the array
// Target of this sorting: to sort the elements in the ascending order
// what kind of data structure is used to iterate over:  {} array of numbers;
// which tool we would use => two for loops to iterate over
// Logic of the algorythm: we would compare every element of
// the outer loop with every element of the inner loop
// we will compare the every element of the outer loop with all
// elements of the inner loop, and if the current element of
// the outer loop is bigger of the current element of inner loop
// we would swap them by the position.
// Important note: on every full inner loop iteration we will
// decrease the iteration by one, because we know that
// at the end we have the largest sorted element
//
// int arr[] =  {2(0),4(1),8(2),1(3),2(8),19,20(5),5(20)}
// 2 > 4 -> false
// 2 > 8 -> false
// 2 > 1 -> true -> 1 .... 2

// for(int i = 0; i < n; i++) {
// for(int j = 0; j < n - i - 1; j++) {
// if(arr[j] > arr[j+1]) {
//
// int temp = arr[j] -> 8(2)
// arr[j] = arr[j+1]-> 1(3)
//
// arr[j+1] = temp;

// }
// }

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {

        int temp = arr[j];
        arr[j] = arr[j + 1];

        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  //int is taken as 4 bytes in the memory
  //so if we have 8 elements in the array it means we have 32 bytes for this array-> 32 bytes === 256 bits
  //If we want to know the size of the array we can do it by sizeof(arr) / sizeof(arr[0])
  // 32 bytes / 4 bytes = 8 elements in the array
  int arr[] = {2, 4, 8, 1, 2, 19, 20, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);
  printf("Sorted array: \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return EXIT_SUCCESS;
}
