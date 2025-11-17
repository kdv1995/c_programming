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
#include <stdio.h>
#include <stdlib.h>

int main() {
  int amountOfWords, amountOfLines, amountOfChars = 0;
  FILE *file;
  char *buffer;
  buffer = malloc(2048 * sizeof(char)); // this 1024 === 1kb

  // how to create dynamic char array in C ?
  //  We can create dynamic char array in C using malloc function from stdlib.h
  //  library

  file = fopen("source.txt", "r");
  // We have to start the while loop until we face with the end of the file. We
  // have EOF macro for that === "\0"
  // fgets()
  while (fgetc(file) != EOF) {
    char *pos = buffer;

    if (buffer[amountOfChars] == '\n') {
      amountOfLines++;
    }

    if (buffer[amountOfChars] == EOF) {
      break;
    }
    if (buffer[amountOfChars] == ' ' || buffer[amountOfChars] == '\n') {
      amountOfWords++;
    }

    // we have to get to know where the words start and where they end? /
    //

    // printf("%c", buffer[amountofChars]);
    // How we could calculate the amount of words inside this while loop ?
    amountOfChars++;
  }

  printf("%zu\n", sizeof(buffer));
  printf("Amount of chars: %d\n", amountOfChars);
  printf("Amount of words: %d\n", amountOfWords);
  printf("Amount of lines: %d\n", amountOfLines);
  // if we get 2303 characters and we allocated only 2048 bytes to the buffer,
  //  we have to reallocate more memory to the buffer so we can fit all the
  //  characters from the file ? we can use realloc function for that

  free(buffer);
  buffer = NULL;
  return 0;
}
