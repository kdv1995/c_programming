// 1.Basic algorythm to process data
//  Лінійний пошук
//  Бінарний пошук
//  Сортування (bubble, insertion, selection)
//  Merge sort
//  Quick sort
//  Heap sort
//  Counting sort / Radix sort

// neovim 0.0.11++
#include "linear_search.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
// linear search has a Bio O type as O(n);
// It depends on how many elements data structure has

int linearSearch(int arr[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {4, 2, 7, 1, 9, 3};
  int arrSize = sizeof(arr) / sizeof(arr[0]);
  int linearSearchResult = linearSearch(arr, arrSize, 7);
  if (linearSearchResult != -1) {
    printf("Element found at index: %d\n", linearSearchResult);
  } else {
    printf("Element not found in the array.\n");
  }
  char buffer[] = "WelcoME to the club";
  int length = sizeof(buffer) / sizeof(buffer[0]);
  int ch;
  char copy[50];
  for (int i = 0; i < length; i++) {
    ch = buffer[i];
    copy[i] = tolower(ch);
  }
  printf("%s\n", copy);

  return EXIT_SUCCESS;
}
