#include <stdio.h>
void newFunction() { printf("This is a new function.\n"); }
void calculateSum() {
  int x = 25;
  int y = 75;
  int sum = x + y;
  printf("sum is %d\n", sum);
}

int findSquare(int num) { return num * num; }
int main() {
  int myNumbers[] = {10, 20};
  char letters[] = "ABCD";
  int *pi = myNumbers;
  char *pc = letters;
  printf("%d\n", *pi);       // Outputs: 20
  printf("%c\n", *(pc + 3)); // Outputs: B
  printf("Day Nine: Advanced C Programming\n");
  int myNum = 10;    // normal variable
  int *ptr = &myNum; // pointer to int
  int **pptr = &ptr; // pointer to pointer

  **pptr = 25;

  newFunction();
  calculateSum();
  int result = findSquare(25);
  printf("Square of 25 is %d\n", result);

  printf("myNum = %d\n", myNum);
  printf("*ptr = %d\n", *ptr);
  printf("**pptr = %d\n", **pptr);
  return 0;
}
