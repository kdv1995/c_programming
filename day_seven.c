#include <stdio.h>

int main() {
  int myNumbers[] = {25, 50, 75, 100};
  int i;
  char mySentence[] = "Hello, World!";
  int mySentenceLength = sizeof(mySentence) / sizeof(mySentence[0]);

  for (i = 0; i < mySentenceLength - 1; i++) {
    printf("%c\n", mySentence[i]);
  }

  int length = sizeof(myNumbers) / sizeof(myNumbers[0]);

  for (i = 0; i < length; i++) {
    printf("%d\n", myNumbers[i]);
  }
  return 1;
}
