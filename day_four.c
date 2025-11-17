#include <stdio.h>
int main() {
  int x = 5;
  int y = 2;
  int z = x / y;
  float myFloat = 10;
  int a = 7.0000;
  int b = 9.98;
  float sum = (float)5 / 2;
  printf("%d\n", z);
  printf("%f\n", myFloat);
  printf("%f\n", (float)a);
  printf("%d\n", a);
  printf("%d\n", b);
  printf("%f\n", sum);
  printf("%.1f\n", sum);

  int maxUserScore = 500;
  int currentUserScore = 423;

  float percentage = (float)currentUserScore / maxUserScore * 100;
  unsigned int myVar;
  printf("The size of this var is equal to %zu bytes\n", sizeof(myVar));

  printf("User's percentage is %.2f", percentage);
  int normalInt = 1000;       // standard int
  double normalDouble = 3.14; // standard double

  short int small = -100;                      // smaller int
  unsigned int count = 25;                     // only positive int
  long int big = 1234567890;                   // larger int
  long long int veryBig = 9223372036854775807; // very large int
  unsigned long long int huge =
      18446744073709551615U;                   // very large, only positive
  long double precise = 3.141592653589793238L; // extended precision

  printf("Normal int: %d\n", normalInt);
  printf("Normal double: %lf\n", normalDouble);
  printf("Small: %hd\n", small);
  printf("Count: %u\n", count);
  printf("Big: %ld\n", big);
  printf("Very Big: %lld\n", veryBig);
  printf("Huge: %llu\n", huge);
  printf("Precise: %Lf\n", precise);
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Size of double: %zu bytes\n", sizeof(double));
  printf("Size of short int: %zu bytes\n", sizeof(short int));
  printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
  printf("Size of long int: %zu bytes\n", sizeof(long int));
  printf("Size of long long int: %zu bytes\n", sizeof(long long int));
  printf("Size of unsigned long long int: %zu bytes\n",
         sizeof(unsigned long long int));
  printf("Size of long double: %zu bytes\n", sizeof(long double));

  const int NUM = 100;
  printf("The constant number is: %d\n", NUM);

  const int minutesPerHour = 60;
  const float PI = 3.14159;
  const int monthInYear = 12;

  for (int i = 0; i < 10; i++) {
  }

  return 0;
}
