//
// Created by tizi2808 on 12/02/25.
//
#include "BankTransfer.h"
#include "BankAccount.h"
#include <sstream>
void BankTransfer::execute() {
    sender.applyTransaction(*this);
    receiver.applyTransaction(*this);
};

std::string BankTransfer::serialize() const {
    std::ostringstream t;
    t << "T" << sender.getId() << "-" << receiver.getId() << "Q" << amount << "@" << data;
    return t.str();
}