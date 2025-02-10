//
// Created by tizi2808 on 07/02/25.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

class BankAccount;
class Transaction {
    static int counter;
protected:
    string id;
    time_t data;
    double amount;
public:
    explicit Transaction(const double amount) {
        this->id = to_string(counter);
        counter++;
        this->amount = amount;
        time(&data);
    };
    virtual ~Transaction() = default;

    const string &getId() const { return id; }
    const time_t &getData() const { return data; }
    double getAmount() const { return amount; }

    virtual void execute() = 0;

    void display() const {
        cout << "Transaction " << id << ": " << amount << " (done on "<< ctime(&data) << ")" << endl;

    }
};

#endif //TRANSACTION_H

