#include <stdio.h>
#include <stdlib.h>
// I have to create a source char array with the alphabet;
// I have to create a target cipher offset array of chars;
// toLower("char") => it seems it has a mapping of ASCII values where lowercase
// and uppercase are mapped;  return string which is the lowercase version of
// the input string;
// toUpper("char") => it seems it has a mapping of ASCII values where lowercase
// and uppercase are mapped; return string which is the uppercase version of the
// input string;
// const char *a;
// const char *b;
// With two pointers we can find matching characters in two strings;
// Ask the user the offset for the cipher;
// Person enters the offset;
// Iterate over the stream of chars from the file;
// push => when we increment the length of the array and add a new char at the
// created index; mutable; pop => when we remove the last char from the array
// and decrement the length; mutable; shift => when we remove the first char
// from the array and decrement the length; mutable;
// [0, 1, 2, 3, 4] -> we can't  by one for loop remove the first element and
// make a shift unshift() -> we have to shift all the elements to
// the right from zero index until the ennd of the array; mutable;
// and fill the first index

// for(let i=length; i>0; i--){ arr[i] = arr[i-1]; } arr[0] = newElement;
// splice(startIndex, delete, 1,2,3)
//.map, filter, reduce
// EOF -1
// every string finishes with null terminaltor \0

char shift_char(char ch, int offset) {

  if (ch >= 'a' && ch <= 'z') {
    return 'a' + (ch - 'a' + offset + 26) % 26;
  }
  // 97 < 105 && 105 < 122
  // 97 + (105 - 97 + 3) % 26 = 100;

  if (ch >= 'A' && ch <= 'Z') {
    return 'A' + (ch - 'A' + offset + 26) % 26;
  }
  return ch; // не літера — не чіпаємо
}


int main() {
  int offset = 0;

  FILE *source;
  FILE *target;
  const char *path = "target.txt";
  source = fopen(path, "r");
  target = fopen("decoded.txt", "w");

  if (!source) {
    perror("Source open");
    return EXIT_FAILURE;
  }
  if (!target) {
    perror("Target open");
    return EXIT_FAILURE;
  }
  int ch = 0;

  printf("Please, enter the offset for the cipher: ");
  scanf("%d", &offset);

  while ((ch = fgetc(source)) != EOF) {

    fputc(shift_char((char)ch, offset), target);
  }

  fclose(source);
  fclose(target);
  return EXIT_SUCCESS;
}
