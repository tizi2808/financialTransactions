//
// Created by tizi2808 on 09/02/25.
//
#include "BankAccount.h"
#include "Deposit.h"

void Deposit::execute() {
    account.increaseBalance(amount);
}

