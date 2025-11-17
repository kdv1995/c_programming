#include <stdio.h>

int main() {
  int counter = 0;
  int secondCounter = 23;
  while (counter < 5) {
    printf("Counter: %d\n", counter);
    counter++;
  }
  do {
    printf("Second Counter: %d\n", secondCounter);
    secondCounter++;

  } while (secondCounter < 25);

  int testNumber;
  do {
    printf("Enter a positive number: ");
    scanf(" %d", &testNumber);
    printf("You entered: %d\n", testNumber);
  } while (testNumber > 0);

  int i;
  for (i = 0; i <= 6; i++) {
    printf("For Loop Iteration: %d\n", i);
  }

  for (i = 0; i <= 10; i += 2) {
    printf("Even Number: %d\n", i);
  }

  int sum = 0;
  int c;

  for (c = 1; c <= 5; c++) {
    sum += c;
  }
  printf("Sum from 0 to 50: %d\n", sum);
  for (c = 5; c >= 0; c--) {
    printf("Countdown: %d\n", c);
  }
  return 0;
}
