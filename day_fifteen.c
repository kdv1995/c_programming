#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Always initialize your variables
// Use meaningful variable names
// Keep your code clean and use indentation to stay organized
// Keep functions short and focused
// Check if loops or conditions are running as expected
// Read error messages carefully - they often tell you exactly where the problem
// is

int main() {
  int number; // Variable to store the user's number

  do {
    printf("Choose a number between 1 and 5: ");
    scanf("%d", &number); // Read number input
    while (getchar() != '\n')
      ;
  } while (number < 1 || number > 5);

  printf("You chose: %d\n", number); // Print the valid number
  return 0;
}
