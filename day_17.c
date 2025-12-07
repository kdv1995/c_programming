#define PI 3.14
#define DEBUG
#define SQUARE(x) ((x) * (x))
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int dice1 = (rand() % 6) + 1;
  int dice2 = (rand() % 6) + 1;
  printf("You rolled %d and %d (total = %d)\n", dice1, dice2, dice1 + dice2);
  printf("Value of PI is approximately %.2f\n", PI);
  printf("Square of 5 is %d\n", SQUARE(5));
#ifdef DEBUG
  printf("Debug mode is ON\n");
#endif

  return EXIT_SUCCESS;
}
