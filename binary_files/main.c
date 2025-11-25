// Binary File Writing /
// Reading
//
// Create a struct(e.g.struct Student {
// int id;
// char name[50];
// floa
//})
// Save an array of students into a binary file and read it back.
#include "main.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// C + D  -> half of the screen down size in neovim
// C + U  -> full of the screen up  size in neovim
// gg ->  go to the beginning of the file
// GG -> go to the end of the file
// /search_term -> cycle throgh found elements with n and N

// parameters names are names when we declare the function;
// Function definitions, because we have a body section
int sum(int a, int b) { return a + b; }
int sqrt(int a) { return a * a; }
int cube(int a) { return a * a * a; }
int factorial(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}
int fibonacci(int n) {
  if (n <= 1)
    return n;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int plus = 0, sqrted = 0, cubed = 0, fact = 0, fibo = 0;

  plus = sum(2, 3);

  sqrted = sqrt(4);
  cubed = cube(3);
  fact = factorial(5);
  fibo = fibonacci(6);
  printf("Sum: %d\n", plus);

  printf("Sqrt: %d\n", sqrted);
  printf("Cube: %d\n", cubed);
  printf("Factorial: %d\n", fact);
  printf("Fibonacci: %d\n", fibo);

  FILE *file;
  FILE *readBinary;
  file = fopen("source.bin", "wb");
  readBinary = fopen("source.bin", "rb");

  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  struct Student students[] = {
      {.name = "John",
       .surname = "Doe",
       .age = 20,
       .grade = 3.5,
       .isMarried = false,
       .subjects = {{"Math", 5}, {"Physics", 4}}},

      {.name = "Jane",
       .surname = "Smith",
       .age = 22,
       .grade = 3.8,
       .isMarried = true,
       .subjects = {{"Math", 5}, {"Physics", 4}}},

  };

  // unsigned char buffer[1024]; // A buffer to store read data
  // size_t bytes_read;

  // while ((bytes_read = fread(buffer, 1, sizeof(buffer), readBinary)) > 0) {
  //   // Process the read data (for demonstration, we'll just print the number
  //   of
  //   // bytes read)
  //   printf("Read %zu bytes from binary file.\n", bytes_read);
  // }

  int length = sizeof(students) / sizeof(students[0]);
  for (int i = 0; i < length; i++) {
    fwrite(&students[i], sizeof(struct Student), 1, file);
  }
  // How can I read raw binary and printf it back to console?

  fclose(file);
  if (readBinary == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  struct Student readStudents[2];

  for (int i = 0; i < length; i++) {
    fread(&readStudents[i], sizeof(struct Student), 1, readBinary);
  }

  // printf("Read Students from binary file:\n");
  // for (int i = 0; i < length; i++) {
  //   printf("Name: %s %s, Age: %d, Grade: %.2f, Is Married: %s\n",
  //          readStudents[i].name, readStudents[i].surname, readStudents[i].age,
  //          readStudents[i].grade, readStudents[i].isMarried ? "Yes" : "No");
  //   for (int j = 0; j < 5; j++) {
  //     if (strlen(readStudents[i].subjects[j].name) > 0) {
  //       printf("  Subject: %s, Credits: %d\n", readStudents[i].subjects[j].name,
  //              readStudents[i].subjects[j].credits);
  //     }
  //   }
  // }

  fclose(readBinary);


  return EXIT_SUCCESS;
}
