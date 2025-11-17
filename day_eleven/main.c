#include <stdio.h>
#include <string.h>

struct Person {
  int age;
  char letter;
  char name[50];
};

int main() {
  struct Person p1;
  struct Person p2 = {25, 'B', "Bob"

  };
  p1.age = 30;
  p1.letter = 'A';
  strcpy(p1.name, "Alice");

  // FILE *file;
  // FILE *created;
  FILE *new;
  char buffer[1024];
  // file = fopen("./file.txt", "r");
  // created = fopen("created.txt", "a");
  new = fopen("new.txt", "r");

  if (new != NULL) {
    while (fgets(buffer, sizeof(buffer), new)) {
      printf("%s", buffer);
    }
  } else {
    perror("Error opening file");
  }

  fclose(new);
  // fclose(file);

  printf("%s", buffer);
  return 0;
}
