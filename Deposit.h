//
// Created by tizi2808 on 09/02/25.
//

#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "Transaction.h"



class Deposit : public Transaction {
    BankAccount& account;
public:
    Deposit(BankAccount& account, const double amount) : Transaction(amount), account(account) {};
    Deposit(BankAccount& account, const std::string& id, const double amount, const time_t timestamp) : Transaction(id, amount, timestamp), account(account) {};

    void execute() override;
    std::string serialize() const override;
};
#endif //DEPOSIT_H

