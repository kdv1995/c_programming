#include <stdio.h>
#include <string.h>

typedef int Year;

typedef enum { RED, GREEN, BLUE } Color;

enum Level { EASY = 25, MEDIUM, HARD };

struct Example {
  char a; // 1 byte
  int b;  // 4 bytes
  char c; // 1 byte
};

typedef struct {
  int year;
  char name[50];
} Person;

struct Owner {
  char firstName[50];
  char lastName[50];
};

union myUnion {
  char myLetter;
  int year;
};

struct Car {
  char brand[50];
  int year;
  struct Owner owner;
};

void updateCarBrand(struct Car *car, const char *newBrand);

void updateCarBrand(struct Car *car, const char *newBrand) {
  snprintf(car->brand, sizeof(car->brand), "%s", newBrand);
}

void updateCarYear(struct Car *car, int newYear);

void updateCarYear(struct Car *car, int newYear) { car->year = newYear; }

int main() {
  printf("Day Twelve: Code Completion Challenge\n");
  FILE *file = fopen("day_twelve.txt", "a");

  Person person2;
  strcpy(person2.name, "Danyil Kurka");

  struct Car myCar = {"BMW", 2006, {"Danyil", "Kurka"}};

  union myUnion carUnion;

  Year manufactureYear = 2006;

  carUnion.year = 2006;
  carUnion.myLetter = 'B';

  printf("myNum: %d\n", carUnion.year); // This value is no longer reliable
  printf("myLetter: %c\n", carUnion.myLetter); // Prints 'A'

  enum Level gameLevel = 3;

  struct Car *ptr = &myCar;
  printf("Car: %s (%d)\n", myCar.brand, myCar.year);
  printf("Owner: %s %s\n", myCar.owner.firstName, myCar.owner.lastName);

  updateCarYear(&myCar, 2020);

  printf("Car via pointer: %s (%d)\n", ptr->brand, ptr->year);

  printf("Updated Car Year: %d\n", myCar.year);

  fprintf(file, "Car: %s (%d)\n", myCar.brand, myCar.year);

  fclose(file);

  printf("Size of struct: %zu bytes\n", sizeof(struct Example));

  return 1;
}
