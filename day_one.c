#include <stdio.h>

int myNumber = 42;
float myFloat = 3.239;
int newNumber;
int secondNumber;
int anotherNumber = 15;

int main() {
  int copyOfAnotherNumber;
  int x = 5, y = 10, z = 20;

  newNumber = 8;
  secondNumber = 25.0;
  copyOfAnotherNumber = anotherNumber;
  printf("%d\n", myNumber);
  printf("Hello my frend %f and the digit number is %d\n", myFloat, newNumber);
  printf("%d\n", secondNumber);
  printf("%d\n", copyOfAnotherNumber);
  printf("%d\n", x + y + z);

  return 0;
}
