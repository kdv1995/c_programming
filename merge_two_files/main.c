// Merge Two Files
//
// Take two files as inputs and merge them into one output file.

#include <stdio.h>

int main() {
  char buffer_one;
  char buffer_two;
  char output_buffer;
  FILE *file1, *file2, *outputFile;
  file1 = fopen("source_one.txt", "r");
  file2 = fopen("source_two.txt", "r");
  outputFile = fopen("merged_output.txt", "w");

  if (file1 == NULL || file2 == NULL || outputFile == NULL) {
    perror("Error opening one of the files.");
    return 1;
  }

  while ((buffer_one = fgetc(file1)) != EOF) {
    fputc(buffer_one, outputFile);
  }
  fclose(file1);

  while ((buffer_two = fgetc(file2)) != EOF) {
    fputc(buffer_two, outputFile);
  }

  fclose(file2);
  fclose(outputFile);

  return 0;
}
