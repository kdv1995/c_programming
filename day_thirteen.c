#include <stdio.h>
#include <stdlib.h>

// The asterisk symbol is responsible for referencing and dereferencing pointers
// in C.
// Examples:-> int *ptr;
// printf("%d", *ptr);

int main() {
  FILE *file = fopen("day_thirteen.txt", "r");
  FILE *dest;
  dest = fopen("day_thirteen_copy.txt", "w");
  int *students;
  int numStudents = 12;
  students = calloc(numStudents, sizeof(*students));
  // printf("%ld\n", numStudents * sizeof(*students)); // 48 bytes

  // Allocate memory
  int *ptr;
  ptr = calloc(4, sizeof(*ptr));

  // Write to the memory
  *ptr = 2;
  ptr[1] = 4;
  ptr[2] = 6;

  // Read from the memory
  // printf("%d\n", *ptr);
  // printf("%d %d %d\n", ptr[1], ptr[2], ptr[3]);

  int *ptr1 = malloc(4);
  char *ptr2 = (char *)ptr1;
  printf("%d %d %d \n", ptr2[0], ptr2[1], ptr2[2]);

  // ptr1[0] = 1684234849;
  // printf("%d is %c %c %c %c", *ptr1, ptr2[0], ptr2[1], ptr2[2], ptr2[3]);
  return 0;
}
