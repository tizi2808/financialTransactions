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

    void execute() override;
    std::string serialize() const override;
};
#endif //DEPOSIT_H

