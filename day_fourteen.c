#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
  char name[50];
  char lastName[50];
} Person;

struct Car {
  char brand[50];
  int year;
};
int main() {
  struct Car *myCar = (struct Car *)malloc(sizeof(struct Car));

  if (myCar == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  strcpy(myCar->brand, "Toyota");
  myCar->year = 2000;

  // Print values
  printf("Brand: %s\n", myCar->brand);
  printf("Year: %d\n", myCar->year);
  free(myCar);
  struct Car *anotherCars =
      (struct Car *)realloc(myCar, 3 * sizeof(struct Car));
  myCar = NULL;
  return 0;
}
