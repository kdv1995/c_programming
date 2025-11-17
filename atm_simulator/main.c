#include <stdbool.h>
#include <stdio.h>

// Ask for a PIN (compare it).

// Allow balance check, withdraw, deposit (use switch to select action).
//
// Store balance in a variable and update it./

int main() {

  static const int CORRECT_PIN = 1234;
  int currentBalance = 1000;
  char currency[] = "USD";
  int enteredPin;
  char operation;
  int attempts = 3;
  bool isOperationCompleted = false;

  while (attempts > 0) {
    if (isOperationCompleted) {
      break;
    }
    printf("Enter you PIN: ");
    scanf("%d", &enteredPin);
    if (enteredPin != CORRECT_PIN) {

      printf("Incorrect PIN. Exiting.\n");
      attempts--;
    } else {
      printf("Select operation: (b)alance, (w)ithdraw, (d)eposit. Please, use "
             "only "
             "the first letter for the operation: \n ");
      scanf(" %c", &operation);
      switch (operation) {
      case 'b':
        printf("Your current balance is: %d %s\n", currentBalance, currency);
        isOperationCompleted = true;
        break;
      case 'w': {
        int withdrawAmount = 0;
        printf("Enter amount to withdraw: ");
        scanf("%d", &withdrawAmount);
        if (withdrawAmount <= currentBalance) {
          if (withdrawAmount > 0) {
            currentBalance -= withdrawAmount;

            printf("Withdrawal successful. New balance: %d %s\n",
                   currentBalance, currency);
            isOperationCompleted = true;

          } else {
            printf("Withdrawal amount must be positive.\n");
          }
        }
      }
      case 'd': {
        int depositAmount = 0;

        printf("Enter amount to deposit: ");
        scanf("%d", &depositAmount);
        if (depositAmount < 0) {
          printf("Please, enter the positive amount to deposit.\n");
        } else {
          currentBalance += depositAmount;
          printf("Deposit successful. New balance: %d %s\n", currentBalance,
                 currency);
          isOperationCompleted = true;
        }
      }
      }
    }
  }

  return 1;
}
