#include <iostream>

#include "BankAccount.h"

int BankAccount::counter = 0;
int Transaction::counter = 0;
std::string BankAccount::db = "db";

int main() {
    BankAccount* acc1 = new BankAccount();
    BankAccount* acc2 = new BankAccount();
    acc1->deposit(100);
    acc2->deposit(100);
    BankAccount& account = *acc1;
    account.deposit(100);
    account.displayBalance();
    BankAccount& account2 = *acc2;
    account2.displayBalance();
    account2.withdraw(100);
    account2.displayBalance();
    account2.displayTransactions();

    return 0;
}
