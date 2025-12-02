#include <stdio.h>

void changeValue(int *ptr) { *ptr = 10; }

int main() {
  int x = 4;
  int *y = &x;
  printf("Value of x: %d\n", *y);
  changeValue(y);
  printf("Value of x after changeValue: %d\n", *y);
  return 0;
}
