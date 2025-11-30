#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  const char *path = "index.html";
  file = fopen(path, "w");
  char str[] = "<html><head></head><body><h1>This is my first website in"
               "C</h1><button>Increment</body><script></script></html>";
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  fputs(str, file);
  return EXIT_SUCCESS;
}
