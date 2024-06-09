#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a bank account
typedef struct {
    int accountNumber;
    char accountHolderName[100];
    double balance;
} Account;

// Function prototypes
void createAccount(Account *account);
void depositMoney(Account *account, double amount);
void withdrawMoney(Account *account, double amount);
void checkBalance(const Account *account);

int main() {
    Account account;
    int choice;
    double amount;

    // Main menu
    while (1) {
        printf("\n=====Banking System Menu=====\n");
        printf("\n=====by Tamim=====\n");
        printf("\n=====Who let`s Code.=====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                depositMoney(&account, amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdrawMoney(&account, amount);
                break;
            case 4:
                checkBalance(&account);
                break;
            case 5:
                printf("Thank you for using our banking system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new account
void createAccount(Account *account) {
    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", account->accountHolderName);
    account->balance = 0.0;
    printf("Account created successfully!\n");
}

// Function to deposit money into the account
void depositMoney(Account *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Amount deposited successfully! New balance: %.2f\n", account->balance);
    } else {
        printf("Invalid amount. Please enter a positive value.\n");
    }
}

// Function to withdraw money from the account
void withdrawMoney(Account *account, double amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Amount withdrawn successfully! New balance: %.2f\n", account->balance);
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}

// Function to check the account balance
void checkBalance(const Account *account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->accountHolderName);
    printf("Account Balance: %.2f\n", account->balance);
}












