//
// Created by tizi2808 on 09/02/25.
//
#include "BankAccount.h"
#include "Deposit.h"
#include <sstream>

void Deposit::execute() {
    account.applyTransaction(*this);
}

std::string Deposit::serialize() const {
    std::ostringstream t;
    t << "D" << id << "A" << account.getId() << "Q" << amount << "@" << data;
    return t.str();
}

