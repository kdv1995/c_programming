#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  FILE *src;
  FILE *dest;

  time_t now;
  now = time(&now);
  struct tm *t = localtime(&now);

  printf("Year: %d\n", t->tm_year + 1900); // Add 1900 to get the actual year
  printf("Month: %d\n",
         t->tm_mon + 1); // Months are numbered from 0 to 11, so add 1 to match
                         // real month numbers (1-12)
  printf("Day: %d\n", t->tm_mday);
  printf("Hour: %d\n", t->tm_hour);
  printf("Minute: %d\n", t->tm_min);
  printf("Second: %d\n", t->tm_sec);

  printf("Current time: %s", ctime(&now));

  int numItems = 15;
  int *myArray = malloc(numItems * sizeof(int));

  int currentTime = time(NULL);

  src = fopen("source.txt", "r");
  dest = fopen("reversed.txt", "w");

  fseek(src, 0, SEEK_END);

  int position = ftell(src);

  if (src == NULL) {
    perror("Error opening source file");
  };

  if (src != NULL) {
    for (int i = position - 1; i >= 0; i--) {
      fseek(src, i, SEEK_SET);
      char ch = fgetc(src);
      fputc(ch, dest);
    }
  }

  // Display the contents of the memory
  for (int i = 0; i < numItems; i++) {
    printf("%d ", myArray[i]);
  }

  // Free the memory
  free(myArray);
  myArray = NULL;

  fclose(src);
  fclose(dest);

  return 0;
}
