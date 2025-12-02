#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *source;
  FILE *target;
  int ch1, ch2;
  bool identical = true;

  source = fopen("source.txt", "r");
  target = fopen("target.txt", "r");
  if (source == NULL || target == NULL) {
    fprintf(stderr, "Error opening files\n");
    return EXIT_FAILURE;
  }
  do {
    ch1 = fgetc(source);
    ch2 = fgetc(target);
    if (ch1 != ch2) {
      printf("files differ on this character: %c %c\n", ch1, ch2);
      identical = false;
      break;
    }

  } while (ch1 != EOF && ch2 != EOF);

  fclose(source);
  fclose(target);

  return EXIT_SUCCESS;
}
