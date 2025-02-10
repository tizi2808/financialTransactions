//
// Created by tizi2808 on 09/02/25.
//
#include "Withdrawal.h"
#include "BankAccount.h"

void Withdrawal::execute() {
    account.decreaseBalance(amount);
}

