#include <stdio.h>
int main() {
  int input;
  int counter;
  int odd = 0;
  int even = 0;
  printf("%d\n", odd);
  printf("Enter a positive integer: ");
  scanf("%d", &input);

  while (input > 1) {
    if (input % 2 == 0) {
      even++;
      input--;
    } else {
      odd++;
      input--;
    }
  }
  printf("%d odd numbers and %d even numbers\n", odd, even);
  return 0;
}
