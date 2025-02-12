//
// Created by tizi2808 on 09/02/25.
//
#include "Withdrawal.h"
#include "BankAccount.h"
#include <sstream>
void Withdrawal::execute() {
    account.applyTransaction(*this);
}

std::string Withdrawal::serialize() const {
    std::ostringstream t;
    t << "W" << account.getId() << "Q" << amount << "@" << data;
    return t.str();
}

