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

    void execute() override;
};

#endif //WITHDRAWAL_H

