// Macros
#include <stdio.h>
#define PI 3.14
#define SQUARE(x) ((x) * (x))

int main() {
  int x = 5;
  printf("Square of %d: %d\n", x, SQUARE(x));

  printf("Value of PI: %f\n", PI);
}
