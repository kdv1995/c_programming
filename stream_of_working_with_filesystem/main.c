#include <curl/curl.h>
#include <stdio.h>
#include <string.h>

struct Person {
  char name[50];
  int age;
  char nationality[50];
  char phoneNumber[15];
};

int main() {

  CURL *curl = curl_easy_init();
  struct Person person1 = {"Alice Smith", 30, "American", "123-456-7890"};
  char fileContent[2048];

  int ch;
  int numberOfLines = 0;

  FILE *src, *dest;
  FILE *file = fopen("myfile.dat", "w");
  fwrite(&person1, sizeof(struct Person), 1, file);

  src = fopen("example.txt", "r");

  if (src == NULL) {
    perror("Could not open source file.\n");
    return 0;
  }

  dest = fopen("copy.txt", "w");

  if (dest == NULL) {
    perror("Could not open destination file.\n");
    fclose(src);
    return 1;
  }

  while ((ch = fgetc(src)) != EOF) {
    fputc(ch, dest);
  }

  fclose(src);
  fclose(dest);

  return 1;
}
