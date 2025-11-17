#include <stdio.h>
int main() {
  char a = 65;
  char b = 66;
  char myText[] = "Hello, World!";
  float f1 = 35e3;
  double d1 = 12E4;

  printf("%c\n", a);
  printf("%c\n", b);
  printf("%s\n", myText);
  printf("%f\n", f1);
  printf("%lf\n", d1);
  int myInt;
  float myFloat;
  double myDouble;
  char myChar;

  printf("%zu\n", sizeof(myInt));
  printf("%zu\n", sizeof(myFloat));
  printf("%zu\n", sizeof(myDouble));
  printf("%zu\n", sizeof(myChar));
  return 0;
}
