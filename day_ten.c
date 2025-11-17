#include <math.h>
#include <stdio.h>

void firstFunction();
void secondFunction();

void sayHello() { printf("Hello from the callback!\n"); }

void runCallback(void (*callback)()) {
  printf("Before calling the callback...\n");
  callback();
  printf("After calling the callback.\n");
}

int anSum(int k);
int factorial(int n);
void countDown(int n);

int sum(int x, int y);

int main() {
  int result = sum(5, 7);
  printf("The sum of 5 and 7 is: %d\n", result);
  firstFunction();
  int value = 16;
  printf("The square root of %d is: %.2f\n", value, sqrt(value));
  float secondValue = 26.7;
  printf("The ceiled value of %f is: %.2f\n", secondValue, ceil(secondValue));
  printf("The floor value of %f is: %.0f\n", secondValue, floor(secondValue));
  printf("The power value of %f is: %.0f\n", secondValue, pow(secondValue, 4));
  int fR = anSum(5);
  printf("The anSum of 5 is: %d\n", fR);
  runCallback(sayHello);

  return 0;
}

int sum(int x, int y) { return x + y; }

void firstFunction() {
  printf("This is the first function.\n");
  secondFunction();
}

void secondFunction() { printf("This is the second function.\n"); }

inline int multiply(int a, int b) { return a * b; }

int anSum(int k) {
  if (k > 0) {
    return k + anSum(k - 1);

  } else {
    return 0;
  }
}

void countDown(int n) {
  if (n > 0) {
    countDown(n - 1);
  }
}

int factorial(int n) {
  if (n > 1) {
    return n * factorial(n - 1);
  } else {
    return 1;
  }
}

