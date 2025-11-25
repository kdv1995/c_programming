#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct Subject {
  char name[30];
  int credits;
};

struct Student {
  float grade;
  int age;
  bool isMarried;
  char name[20];    // 20 bytes
  char surname[20]; // 20 bytes
  struct Subject subjects[5];
};

//Function declarations
int sum(int a, int b);
int sqrt(int a);
int cube(int a);
int factorial(int n);
int fibonacci(int n);

#endif
