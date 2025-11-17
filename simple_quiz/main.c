#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// 1. Print the question
// 2. Print the options
// 3. Get user input
// 4. Check the answer using switch
// 5. Keep track of the score

struct Question {
  char text[100];
  char options[4][50];
  char correct_answer;
};

int main() {
  int correct_answers = 0;
  int total_questions = 0;
  int wrong_answers = 0;
  char user_answer;
  struct Question quiz[] = {
      {"What is the capital of France?",
       {"Paris", "Berlin", "Rome", "Madrid"},
       'A'},
      {"Which data type is used to store whole numbers in C?",
       {"float", "char", "int", "double"},
       'C'},
      {"What symbol is used to get the address of a variable?",
       {"&", "*", "#", "%"},
       'A'}};

  int length = sizeof(quiz) / sizeof(quiz[0]);

  for (int i = 0; i < length; i++) {
    printf("Q%d: %s\n", i + 1, quiz[i].text);
    for (char option = 'A'; option <= 'D'; option++) {

      bool isAnswered = false;

      int index = option - 'A';
      printf("%c) %s\n", option, quiz[i].options[index]);
    }
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &user_answer);

    if (user_answer == quiz[i].correct_answer) {
      printf("Correct!\n\n");
      correct_answers++;

    } else {
      printf("Wrong! The correct answer was %c.\n\n", quiz[i].correct_answer);
      wrong_answers++;
    }
  }
  printf("Quiz Over!\n");
  printf("Correct Answers: %d\n", correct_answers);
  printf("Wrong Answers: %d\n", wrong_answers);

  return 0;
}
