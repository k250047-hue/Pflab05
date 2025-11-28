#include <stdio.h>
#include <string.h>
#include <time.h>

struct Transaction {
    char type[10];
    double amount;
    char date[20];
};

struct Account {
    char name[50];
    int accountNumber;
    char type[20];
    double balance;
    double interestRate;
    double minBalance;
    char creationDate[20];
    char lastTransactionDate[20];
    struct Transaction history[100];
    int transactionCount;
};

void addTransaction(struct Account *acc, char *transType, double amount) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(acc->history[acc->transactionCount].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    strcpy(acc->history[acc->transactionCount].type, transType);
    acc->history[acc->transactionCount].amount = amount;
    strcpy(acc->lastTransactionDate, acc->history[acc->transactionCount].date);
    acc->transactionCount++;
}

void deposit(struct Account *acc, double amount) {
    acc->balance += amount;
    addTransaction(acc, "Deposit", amount);
}

void withdraw(struct Account *acc, double amount) {
    if (acc->balance - amount >= acc->minBalance) {
        acc->balance -= amount;
        addTransaction(acc, "Withdraw", amount);
    } else {
        printf("Cannot withdraw. Minimum balance required.\n");
    }
}

void printAccount(struct Account acc) {
    printf("Name: %s\nAccount No: %d\nType: %s\nBalance: %.2f\nInterest: %.2f%%\nCreated: %s\nLast Transaction: %s\n",
           acc.name, acc.accountNumber, acc.type, acc.balance, acc.interestRate, acc.creationDate, acc.lastTransactionDate);
    printf("Transactions:\n");
    for (int i = 0; i < acc.transactionCount; i++) {
        printf("%s - %s: %.2f\n", acc.history[i].date, acc.history[i].type, acc.history[i].amount);
    }
}

int main() {
    struct Account user1;
    strcpy(user1.name, "Ali Khan");
    user1.accountNumber = 101;
    strcpy(user1.type, "Savings");
    user1.balance = 1500;
    user1.interestRate = 4;
    user1.minBalance = 1000;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(user1.creationDate, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    strcpy(user1.lastTransactionDate, user1.creationDate);
    user1.transactionCount = 0;

    deposit(&user1, 500);
    withdraw(&user1, 200);
    withdraw(&user1, 2000);

    printAccount(user1);

    return 0;
}
