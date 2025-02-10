//
// Created by tizi2808 on 09/02/25.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <vector>
#include <string>
#include "Deposit.h"
#include "Withdrawal.h"

using namespace std;

class BankAccount {
    static int counter;
    string id;
    double balance = 0;
    vector<Transaction*> transactions;
public:
    BankAccount() {
        id = to_string(counter);
        counter++;
    }
    ~BankAccount() {
        for (const auto t : transactions) {
            delete t;
        }
        transactions.clear();
    };
    void deposit(const double amount) {
        auto transaction = new Deposit(*this, amount);
        transaction->execute();
        transactions.push_back(transaction);
    }

    void withdraw(const double amount) {
        auto transaction = new Withdrawal(*this, amount);
        transaction->execute();
        transactions.push_back(transaction);
    }
    void increaseBalance(const double amount) {
        balance += amount;
    }
    void decreaseBalance(const double amount) {
        balance -= amount;
    }
    void displayBalance() const {
        cout << "Saldo: " << balance << endl;
    }
    void displayTransactions() const {
        cout << "Transactions for " << id << ": " << endl;
        for (const auto t : transactions) {
            t->display();
        }
    }
};

#endif //BANKACCOUNT_H

