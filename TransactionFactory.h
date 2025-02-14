//
// Created by tizi2808 on 13/02/25.
//

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H
#include <string>

#include "Transaction.h"

class TransactionFactory {
public:
    TransactionFactory() = default;
    ~TransactionFactory() = default;
    Transaction* unserializeTransaction(const std::string &serialized) {
        const char transactionType = serialized[0];

        const size_t posA = serialized.find('A');
        if (posA == std::string::npos) {
            std::cerr << "Formato errato: manca 'A'" << std::endl;
        }
        const size_t posQ = serialized.find('Q');
        if (posQ == std::string::npos) {
            std::cerr << "Formato errato: manca 'Q'" << std::endl;
        }
        const size_t posAt = serialized.find('@', posQ);
        if (posAt == std::string::npos) {
            std::cerr << "Formato errato: manca '@'" << std::endl;
        }
        std::string id = serialized.substr(1, posA - 1);
        std::string accountStr = serialized.substr(posA + 1, posQ - posA - 1);
        std::string quantityStr = serialized.substr(posQ + 1, posAt - posQ - posA - 1);
        std::string timestampStr = serialized.substr(posAt + 1);
        int account = std::stoi(accountStr);
        double amount = std::stod(quantityStr);
        const auto timestamp = static_cast<time_t>(std::stoi(timestampStr));
        /*
        if (transactionType == 'D') {

        }
        */
    }
};


#endif //TRANSACTIONFACTORY_H
