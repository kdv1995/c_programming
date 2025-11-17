// 8. Traffic Light Simulation
//
// Ask the user to type a color (red, yellow, green).
//
// Use switch to print what action to take (“Stop”, “Wait”, “Go”).
#include "main.h"
#include <stdio.h>

void print_message(int number) { printf("The number is: %d\n", number); }

int main() {
  int choice;

  printf(
      "Enter a traffic light color (0 for RED, 1 for YELLOW, 2 for GREEN): ");
  scanf("%d", &choice);
  switch (choice) {
  case RED:
    printf("Stop\n");
    break;
  case YELLOW:
    printf("Wait\n");
    break;
  case GREEN:
    printf("Go\n");
    break;
  default:
    printf("Invalid color\n");
    break;
  }

  printf("Thx for using the program!\n");

  return 0;
}
