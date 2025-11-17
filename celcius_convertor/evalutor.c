#include <stdio.h>
// We want to create avaluator that evaluates the grade of a student based on
// their score
// There is a five grades: A, B, C, D, F

int main() {
  int score;

  printf("Enter the score (0-100): \n ");
  scanf("%d", &score);
  printf("The grade is: %d\n", score);
  switch (score) {
  case 90:
    printf("Grade: A\n");
    break;
  case 80:
    printf("Grade: B\n");
    break;

  case 70:
    printf("Grade: C\n");
    break;

  case 60:
    printf("Grade: D\n");
    break;
  default:
    printf("Grade: F\n");
    break;
  }
  return 0;
}
