#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int calcualteAmountOfLines(FILE *file) {
  int amountOfLines = 0;
  char ch;

  while ((ch = fgetc(file)) != EOF) {
    if (ch == '\n') {
      amountOfLines++;
    }
  }

  return amountOfLines;
};
int calculateAmountOfWords(FILE *file) {
  int amountOfWords = 0;
  char ch;

  while ((ch = fgetc(file)) != EOF) {
    if (ch == ' ' || ch == '\n') {
      amountOfWords++;
    }
  }

  return amountOfWords;
}
int calculateAmountOfChars(FILE *file) {
  int amountOfChars = 0;
  char ch;

  while ((ch = fgetc(file)) != EOF) {
    amountOfChars++;
  }

  return amountOfChars;
}

int main() {

  int amountOfWords = 0, amountOfLines = 0, amountOfChars = 0;
  FILE *file;

  char ch;

  file = fopen("source.txt", "r");
  if (file != NULL) {
    printf("File opened successfully\n");
  } else {
    perror("Error opening file");
    return 1;
  }

  amountOfChars = calculateAmountOfChars(file);
  rewind(file);
  amountOfWords = calculateAmountOfWords(file);
  rewind(file);
  amountOfLines = calcualteAmountOfLines(file);
  fclose(file);

  printf("Amount of chars: %d\n", amountOfChars);
  printf("Amount of words: %d\n", amountOfWords);
  printf("Amount of lines: %d\n", amountOfLines);

  return 0;
}

// Operators that I would use: sizeof for getting the size of the file in bytes
// fopen() to open and read the file in the read mode as the second argument
// fopen("file.txt", "r") Task:  File Statistics A. Count and display:
// IN JS we would use the split methods with space to split the the whole string
// to the formatted array of string where we definetely know how many words we
// have in the file; If we want to use the for loop to iterate over the array of
// chars, inside the for loop we could check if we met the space or new line
// character to increase the word count variable by one; if current iteration
// element would be equal to '\n' | ' ' we would increase the words count by
// one; You have to use initially a brute force solution. Brute force solution
// is a solution that is not optimized, not efficeient, but it works. After you
// have the brute force solution, you can optimize it later.
// 1.Number of
// characters
//
// 2.Number of words
//
// 3.Number of lines
// When we will read the stream line by line with fgets fucntion we would be
// able to increment the line count variable by one each time we read the line
// from the file
//
// 4.File size in bytes
// Should we calculate all of the specific symbols as spaces, new lines and so
// far. POV, I think that computer allocate memory for each character in the
// file including spaces and new lines. Am I right? Yes, you are correct. Each
// character in a file, including spaces and new lines, occupies memory.
// Therefore, when calculating the file size in bytes, all characters should be
// counted. If i will read to the char array the whole file content, then I will
// be able to use sizeof function to get the size of the file in bytes My
// suggestion to calculate the number of characters is to read the file with
// buffer and write it it to char array where I will be able to count the
// characters with sizeof function
