// Search for a Word in File
// Ask the user for a word, then search for it in the file and show how many
// times it appears.
#include <stdio.h>
#include <string.h>

int main() {
  int count = 0;
  char input[42];
  FILE *file;
  file = fopen("source.txt", "r");

  char buffer[512];

  printf("Enter a word to search: ");
  scanf("%s", input);

  // hello hello hello hello hello welcome welcome welcome
  // 0 1 2 3 4 5 6 7 8
  // hello hello hello hello hello welcome welcome welcome

  while (fgets(buffer, 512, file)) {
    printf("Read line: %s", buffer);
    char *pos = buffer;
    while ((pos = strstr(pos, input)) != NULL) {
      count++;
      pos += strlen(input);
    }
  }
  // strstr moves like a sliding window over the buffer to find occurrences of the input word;
  // each time it finds one, it increments the count and moves the position forward by the length of the input word to continue searching.

  printf("The word '%s' appears %d times in the file.\n", input, count);

  fclose(file);

  return 0;
}
