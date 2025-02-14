//
// Created by tizi2808 on 12/02/25.
//

#ifndef BANKTRANSFER_H
#define BANKTRANSFER_H
#include "Transaction.h"


class BankTransfer : public Transaction {
    BankAccount& sender;
    BankAccount& receiver;
    public:
    BankTransfer(BankAccount& sender, BankAccount& receiver, const double amount): Transaction(amount), sender(sender), receiver(receiver) {}
    BankTransfer(BankAccount& sender, BankAccount& receiver, const std::string& id, const double amount, const time_t timestamp): Transaction(id, amount, timestamp), sender(sender), receiver(receiver) {}

    BankAccount& getSender(){ return sender;};
    BankAccount& getReceiver(){ return receiver;};
    void execute() override;
    std::string serialize() const override;
};

#endif //BANKTRANSFER_H
