#include "selection_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
// Data structure and algorithm
// We are working with strings, array, number, boolean(0,1) , object(key value
// pair) -> dictironary in python, map, set, enum
enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

// npm  package.json -> save the string commands that you can call through bash
// terminal npx -> run the command without installing globally npx
// create-react-app my-app - >curl
// https://create-react-app.dev/docs/getting-started/ && start.sh -> npm i react
// recat-dom react-script

// I'm using NVIM text editor with FULL IDE FEATURES SUPPORTED
// Normal mode
//  INSERT MODE
//  Visual mode
//  V-BLOCK
//  Text wise visual mode
// Text line wise visual mode

// 1. We have to make a function definition
// 2. Selection sort algorithm
// a. By default we expect that the first element is the minimum;->
// it will be assigned to the mind_index variable whcih is int

// double for loop =>  inside outer loop we dfine int mind_index = i;
//  and with the inner loop we compare the rest of the elements with current
//  one, and if we find any smaller element we update the mind_index variable
//  {5, 2, 1, 9, 6 , 7}
// int min_index = 0(5)
// for()
//   for()
// if (arr[min_index] > arr[j]) {
//   min_index = j;
// }
// calculate mean => sum / n
// calculate median => sort the array and find the middle element
// calculate variance => mean of squared differences from the mean

// Splice =>

// after the inner  loop we can make
// 0123456....50   25

// if w3e want to insert the inside the string into the middle
// we have to knwo from which index we would do insertation
// 2 is considered to be the lowest
// arrays and object in javascript is passed to function by reference
//  in c language array is passed by reference withh * asterisk
// if  you pass in the function the object or array you can modify the original
// object or array
// {}

// {2, 3, 1}
// on the first iteration the element 2 is considered to be the minimum
// then we compare with 3 and 1
// 2 >3 -> false
//
// every data that we store in the memory has an address => 0x7ffeefbff5c0
// char => 1 byte
// int => 4 bytes
// float => 4 bytes-> with 6-7 decimal precision
// double => 8 bytes -> with 15-16 decimal precision
// enum => it should be the same type of data , by default it is int  ant tikes
// the
// amount of space as the element chosen
// struct => struct has multiple data types inside it; the size of struct is a
// sum of
// all the data types inside it
// we can pass values to the function by value or by reference
// Does function also have the memory address?/
// Yes, every function in C has a memory address where its code is stored.
// We have also offset and aliasing in C language
// Neovim

// {2,3,1}
// 1. Outer loop i=0 -> min_index = 0
// 2. Inner loop j=1 -> arr[0] > arr[1] -> 2 > 3 false
// 3. Inner loop j=2 -> arr[0] > arr[2] -> 2 > 1 true -> min_index = 2
// 4. After inner loop swap arr[0] and arr[2] -> {1,3,2}
// 5. Outer loop i=1 -> min_index = 1
// 6. Inner loop j=2 -> arr[1] > arr[2] -> 3 > 2 true -> min_index = 2
// 7. After inner loop swap arr[1] and arr[2] -> {1,2,3}
// 8. Outer
void selectionSort(int *arr, int size) {
  int temp = 0;
  int minIdx = 0;
  for (int i = 0; i < size - 1; i++) {
    minIdx = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[minIdx];
    arr[minIdx] = temp;
  }
}

int main() {
  FILE *file;
  file = fopen("selection_sort_result.txt", "w");
  int arr[] = {64, 25, 12, 22, 11};
  int size = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, size);

  // join
  for (int i = 0; i < size; i++) {
    fprintf(file, "%d,", arr[i]);
  }
  fclose(file);
  return EXIT_SUCCESS;
}
