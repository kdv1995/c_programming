// 🔵 Slightly advanced(combine logic)
//
//         9. Simple Menu
//     - Driven Unit Converter
//
//       A menu with :
//
//     Temperature
//
//     Length
//
//     Weight
//
//     Each option leads to its own calculation using switch.

// - Temperature: Celsius to Fahrenheit and vice versa
// - Length: Meters to Feet and vice versa
// - Weight: Kilograms to Pounds and vice versa

#include "main.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Give me the formula to calculate Celsius to Fahrenheit
// Fahrenheit = (Celsius * 9/5) + 32 and vice versa Celsius = (Fahrenheit - 32)
// * 5/9
// What is the formula of meters to feet ?
// 1 meter = 3.28084 feet and vice versa feet = meters / 3.28084

float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float metersToFeet(float meters);
float feetToMeters(float feet);
float kilogramsToPounds(float kilograms);
float poundsToKilograms(float pounds);

// Functions definitions
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}
float fahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 5.0 / 9.0;
}

float metersToFeet(float meters) { return meters * 3.28084; }
float feetToMeters(float feet) { return feet / 3.28084; }

float kilogramsToPounds(float kilograms) { return kilograms * 2.20462; }
float poundsToKilograms(float pounds) { return pounds / 2.20462; }

struct MenuOption {
  int id;
  const char *name;
};

int sum(int a, int b);
int sum(int a, int b) { return a + b; }

int main() {
  struct MenuOption options[3] = {{1, "Temperature Conversion"},
                                  {2, "Length Conversion"},
                                  {3, "Weight Conversion"}};

  assert(sum(2, 3) == 5);
  bool running = true;
  int optionChoice;
  int length = sizeof(options) / sizeof(options[0]);
  float choice;
  int tChoice = 0;
  float result = 0.0;

  while (running) {

    for (int i = 0; i < length; i++) {
      printf("%d. %s\n", options[i].id, options[i].name);
    }
    printf("Select an option (1-%d) or 0 to exit: \n", length);
    scanf("%d", &optionChoice);

    switch (optionChoice) {
    case 0:
      perror("Exiting the program.");
      running = false;
      break;

    case 1: {

      printf(
          "Enter 1 for Celsius to Fahrenheit or 2 for Fahrenheit to Celsius: ");
      scanf("%d", &tChoice);

      if (tChoice) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &choice);
        if (choice < 0) {
          perror("Invalid input. Temperature cannot be below absolute zero.");
          running = 0;
        } else {
          result = (celsiusToFahrenheit(choice));
          running = 0;
        }
      } else {
        if (choice < 0) {
          perror("Invalid input. Temperature cannot be below absolute zero.");
          running = 0;

        } else {
          result = (fahrenheitToCelsius(choice));
          running = 0;
        }
      }

      printf("Result: %.2f\n", result);

      break;
    }

    case 2:
      printf("Enter 1 for Meters to Feet or 2 for Feet to Meters: ");
      scanf("%d", &tChoice);

      if (tChoice) {
        printf("Enter your value in metters: ");
        scanf("%f", &choice);
        if (choice < 0) {
          perror("Invalid input. Metters cannot be below zero.");
          running = 0;
        } else {
          result = (metersToFeet(choice));
          running = 0;
        }
      } else {
        if (choice < 0) {
          perror("Invalid input. Temperature cannot be below absolute zero.");
          running = 0;

        } else {
          result = (feetToMeters(choice));
          running = 0;
        }
      }

      printf("Result: %.2f\n", result);

      break;

    case 3:
      printf("Enter 1 for Kilograms to Pounds or 2 for Pounds to Kilograms: ");
      scanf("%d", &tChoice);

      if (tChoice) {
        printf("Enter your value in kgs: ");
        scanf("%f", &choice);
        if (choice < 0) {
          perror("Invalid input. Kgs cannot be below zero.");
          running = 0;
        } else {
          result = (kilogramsToPounds(choice));
          running = 0;
        }
      } else {
        if (choice < 0) {
          perror("Invalid input. Temperature cannot be below absolute zero.");
          running = 0;

        } else {
          result = (poundsToKilograms(choice));
          running = 0;
        }
      }

      printf("Result: %.2f\n", result);

      break;
    }
  }
  printf("Thank you for using the converter!\n");
  return 0;
}
