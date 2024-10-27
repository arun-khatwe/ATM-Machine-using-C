
#include <stdio.h>
#include <stdlib.h>

#define PIN 1234          // Hardcoded PIN for simplicity
#define INITIAL_BALANCE 1000

void displayMenu() {
    printf("\nATM Menu:\n");
    printf("1. Check Balance\n");
    printf("2. Withdraw Money\n");
    printf("3. Deposit Money\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int main() {
    int enteredPin;
    int balance = INITIAL_BALANCE;
    int choice;
    int amount;

    // User authentication
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != PIN) {
        printf("Invalid PIN. Exiting...\n");
        return 1;
    }

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your balance is $%d\n", balance);
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                if (amount > balance) {
                    printf("Insufficient funds!\n");
                } else {
                    balance -= amount;
                    printf("You have withdrawn $%d\n", amount);
                    printf("Your new balance is $%d\n", balance);
                }
                break;

            case 3:
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                balance += amount;
                printf("You have deposited $%d\n", amount);
                printf("Your new balance is $%d\n", balance);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
/*
  +---------------------+
  |        Start        |
  +---------------------+
             |
             v
  +---------------------+
  |     Enter PIN       |
  +---------------------+
             |
             v
  +---------------------+
  | Is PIN Correct?    |
  +---------------------+
     |          |
     | No       | Yes
     |          |
     v          v
  +---------------------+         +---------------------+
  | Display Error       |         |    Display Menu     |
  | (Invalid PIN)       |         +---------------------+
  +---------------------+                 |
             |                            v
             v                    +---------------------+
       +------------------+       | User Chooses Option |
       |    End Program   |       +---------------------+
       +------------------+                 |
                                             v
                         +--------------------------------+
                         |         Menu Options            |
                         |--------------------------------|
                         | 1: Check Balance               |
                         | 2: Withdraw Money              |
                         | 3: Deposit Money               |
                         | 4: Exit                        |
                         +--------------------------------+
                                       |
        +------------------------------+-----------------------+
        |                              |                       |
        v                              v                       v
  +-------------------+       +---------------------+   +--------------------+
  | Check Balance     |       | Withdraw Money      |   | Deposit Money      |
  +-------------------+       +---------------------+   +--------------------+
        |                           |                          |
        v                           v                          v
  +-------------------+       +---------------------+   +--------------------+
  | Display Balance   |       | Enter Amount        |   | Enter Amount       |
  +-------------------+       +---------------------+   +--------------------+
        |                           |                          |
        v                           |                          v
  +-------------------+       +---------------------+   +--------------------+
  | Return to Menu    |       | Amount <= Balance?  |   | Add to Balance     |
  +-------------------+       +---------------------+   +--------------------+
                                |           |                 |
                                |           | No              |
                                |           v                 v
                                |   +---------------------+   +--------------------+
                                |   | Display Error       |   | Return to Menu     |
                                |   | (Insufficient Funds)|   +--------------------+
                                |   +---------------------+
                                |
                                v
                      +---------------------+
                      | Update Balance      |
                      +---------------------+
                                |
                                v
                      +---------------------+
                      | Return to Menu      |
                      +---------------------+
                                |
                                v
                      +---------------------+
                      |      Exit           |
                      +---------------------+
                                |
                                v
                      +---------------------+
                      |      End            |
                      +---------------------+
*/