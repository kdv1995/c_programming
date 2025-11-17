#include <stdbool.h>
#include <stdio.h>
int main() {
  int x = 5;
  int y = 10;
  bool isSunny = true;
  printf("Hello, World!\n");
  printf("%d\n", x > y);
  int passwordLength = 8;
  printf("%d\n", passwordLength >= 8);
  bool isHamburgerTasty = true;
  bool isPizzaTasty = true;

  // Find out if both hamburger and pizza is tasty
  printf("%d\n", isHamburgerTasty == isPizzaTasty);
  return 0;
}
