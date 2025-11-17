#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int randomNum = rand() % 100; // Generate a random number between 0 and 99
  int userInput;
  bool isGameCompleted = false;
  printf("Random Number: %d\n", randomNum);

  while (!isGameCompleted) {
    printf("Enter your guess (0-99): ");
    scanf("%d", &userInput);
    if (userInput > randomNum) {
      printf("Too high! Try again.\n");
    } else if (userInput < randomNum) {
      printf("Too low! Try again.\n");
    } else {
      printf("Congratulations! You've guessed the correct number.\n");
      isGameCompleted = true;
    }
  }

  return 0;
}

// 1. Generate a random number between 0 and 99 and store it in a variable named
// randomNum.
// 2. Create a boolean variable named isGameCompleted and set it to false.
// 3. Print the value of randomNum to the console.
// 4. Create a while loop that continues as long as isGameCompleted is false.
