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
#include "BankTransfer.h"

using namespace std;

class BankAccount {
    static int counter;
    string id;
    double balance = 0;
    vector<Transaction*> transactions;

    void increaseBalance(const double amount) {
        balance += amount;
    }
    void decreaseBalance(const double amount) {
        balance -= amount;
    }
public:
    BankAccount() {
        id = to_string(counter++);
    }
    ~BankAccount() {
        for (const auto t : transactions) {
            delete t;
        }
        transactions.clear();
    };
    const std::string& getId() const {return id;};

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
    void applyTransaction(Transaction& transaction) {
        const double amount = transaction.getAmount();
        if (auto t = dynamic_cast<Deposit*>(&transaction)) {
            this->increaseBalance(amount);
        } else if (auto t = dynamic_cast<Withdrawal*>(&transaction)) {
            this->decreaseBalance(amount);
        } else if (auto t = dynamic_cast<BankTransfer*>(&transaction)) {
            if (&(t->getSender()) == this) {
                this->decreaseBalance(amount);
            } else if (&(t->getReceiver()) == this) {
                this->increaseBalance(amount);
            }
        }
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

