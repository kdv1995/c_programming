// We have to define farhenheit formula to celsius conversion
// We have to defiene celsius formula to farhenheit conversion
// The formula to convert Celsius to Fahrenheit is \(F=(C\times
// \frac{9}{5})+32\)
// and the formula to convert Fahrenheit to Celsius is \(C=(F-32)\times
// \frac{5}{9}\).
#include <stdio.h>

int main() {
  int value;
  char option;

  printf("Enter your value to convert: \n");
  scanf("%d", &value);
  printf("Enter 'A' if you want to conver from Celsius to Fahrenheit or 'B' "
         "for Fahrenheit to Celsius:  \n");
  scanf(" %c", &option);
  switch (option) {
  case 'A':
    printf("The value in Fahrenheit is: %d\n", (value * 9 / 5) + 32);
    break;

  case 'B':
    printf("The value in Celsius is: %d\n", (value - 32) * 5 / 9);
    break;

  default:
    printf("Invalid option selected.\n");
    break;
  }

  return 0;
}
