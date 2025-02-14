//
// Created by tizi2808 on 09/02/25.
//

#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H
#include "Transaction.h"

class Withdrawal : public Transaction {
    BankAccount& account;
public:
    Withdrawal(BankAccount& account, const double amount) : Transaction(amount), account(account) {};
    Withdrawal(BankAccount& account, const std::string& id, const double amount, const time_t timestamp) : Transaction(id, amount, timestamp), account(account) {};

    void execute() override;
    std::string serialize() const override;
};

#endif //WITHDRAWAL_H

