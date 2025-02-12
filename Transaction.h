//
// Created by tizi2808 on 07/02/25.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <ctime>
#include <iostream>
#include <cstring>


class BankAccount;
class Transaction {
protected:
    static int counter;
    std::string id;
    time_t data;
    double amount;
public:
    explicit Transaction(const double amount) {
        this->id = std::to_string(counter++);
        this->amount = amount;
        data = time(nullptr);
    };
    virtual ~Transaction() = default;

    const std::string &getId() const { return id; }
    const time_t &getData() const { return data; }
    double getAmount() const { return amount; }

    virtual std::string serialize() const = 0;
    virtual void execute() = 0;

    void display() const {
        std::cout << "Transaction " << id << ": " << amount << " (done on "<< strtok(ctime(&data), "\n") << ")" << std::endl;
    }
};

#endif //TRANSACTION_H

