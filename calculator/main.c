// Title: Calculator
// Description: A simple calculator program that performs basic arithmetic
// operations.
// To do list that should be implemented:
// 1. Addition
// 2. Subtraction
// 3. Multiplication
// 4. Division
// 5. Error handling for division by zero
// 6. Exit option
#include <stdio.h>
// The visual part of the calculator is being created with ui visual buttons;
// For our use case, we would provider an input string that user will be forced
// to write down. We have to somehow understand which operation user want to
// perform. We could do that with if-else statements

// number (implicit conversion) in js
// bigint

int main() {
  float x;
  float y;
  while (1) {
    printf("Type your first number:\n");
    scanf("%f", &x);
    printf("Type your second number:\n");
    scanf("%f", &y);
    printf("Your chosen number are %.0f and %.0f\n", x, y);
    char operation;
    if (x == 0 && y == 0) {
      printf("Exiting the calculator. Goodbye!\n");
      break;
    }

    printf("Type the operation you want to perform (+, -, *, /):\n");
    scanf(" %c", &operation);
    printf("You chose the operation: %c", operation);

    switch (operation) {
    case '+':
      printf("Result: %.0f\n", x + y);
      break;
    case '-':
      printf("Result: %.0f\n", x - y);
      break;
    case '*':
      printf("Result: %.0f\n", x * y);
      break;
    case '/':
      if (y == 0) {
        printf("Error: Division by zero is not allowed.\n");
      } else {
        printf("Result: %.0f\n", x / y);
      }
      break;
    default:
      printf("Invalid operation. Please try again.\n");
      break;
    }
  }
}
