#include <iostream>

#include "BankAccount.h"

int BankAccount::counter = 0;
int Transaction::counter = 0;

int main() {
    BankAccount* acc1 = new BankAccount();
    BankAccount* acc2 = new BankAccount();
    acc1->deposit(100);
    acc2->deposit(100);
    BankAccount& account = *acc1;
    account.deposit(100);
    account.displayBalance();
    account = *acc2;
    account.displayBalance();
    account.withdraw(100);
    account.displayBalance();
    account.displayTransactions();

    return 0;
}
