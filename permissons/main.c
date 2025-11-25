#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
// NEovim -> this is a vim
//  but written in lua

int main() {
  int a = 'a';

  const char *path = "source.txt";
  struct stat file_info;
  int result;

  result = access(path, R_OK);

  if (result == 0) {
    printf("Read accesss allowed.\n");
  } else {
    printf("Read access forbidden\n");
  }

  stat(path, &file_info);

  printf("File size: %lld bytes\n", (long long)file_info.st_size);
  printf("File permissions: %o\n", file_info.st_mode & 0777);
  printf("Last modified time: %ld\n", file_info.st_mtime);

  return EXIT_SUCCESS;
}
