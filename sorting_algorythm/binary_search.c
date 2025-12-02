// 1.Basic algorythm to process data
//  Лінійний пошук
//  Бінарний пошук
//  Сортування (bubble, insertion, selection)
//  Merge sort
//  Quick sort
//  Heap sort
//  Counting sort / Radix sort
// We have an array of numbers;
// we need start of the array and end of the array and we have to found out
// middle
// Our array should be sorted first
// if we have 10 elements in the array we search the middle if the middle
// elements is equal to target we return the index.
// if elements is less than
int binarySearch(int arr[], int size, int target) {
  // we search elements on the 3rd index which is  7;
  // length = 6
  int start = 0;
  int end = size - 1;
  int middle = start + (end - start) / 2;
  // if the target element is bigger
  while (start <= end) {
    if (arr[middle] == target) {
      return middle;
    } else if (arr[middle] < target) {
      start = middle + 1;
    } else if (arr[middle] > target) {
      end = middle - 1;
    } else {
      return -1;
    }
  }
  return -1;
}

#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  int arr[] = {1, 2, 3, 4, 7, 9};
  int arrSize = sizeof(arr) / sizeof(arr[0]);
  int linearSearchResult = binarySearch(arr, arrSize, 7);
}
