//
// Created by tizi2808 on 09/02/25.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include "Deposit.h"
#include "Withdrawal.h"
#include "BankTransfer.h"

namespace fs = std::filesystem;

class BankAccount {
    static int counter;
    std::string id;
    double balance = 0;
    std::vector<Transaction*> transactions;
    static std::string db;

    void increaseBalance(const double amount) {
        balance += amount;
    }
    void decreaseBalance(const double amount) {
        balance -= amount;
    }
public:
    BankAccount() {
        id = std::to_string(counter++);
    }
    explicit BankAccount(const std::string& id) {
        this->id = id;
    }
    ~BankAccount() {
        for (const auto t : transactions) {
            delete t;
        }
        transactions.clear();
    };
    const std::string& getId() const {return id;};

    void deposit(const double amount) {
        auto transaction = new Deposit(*this, amount);
        transaction->execute();
    }

    void withdraw(const double amount) {
        auto transaction = new Withdrawal(*this, amount);
        transaction->execute();
    }
    void applyTransaction(Transaction& transaction) {
        const double amount = transaction.getAmount();
        if (auto t = dynamic_cast<Deposit*>(&transaction)) {
            this->increaseBalance(amount);
        } else if (auto t = dynamic_cast<Withdrawal*>(&transaction)) {
            this->decreaseBalance(amount);
        } else if (auto t = dynamic_cast<BankTransfer*>(&transaction)) {
            if (&(t->getSender()) == this) {
                this->decreaseBalance(amount);
            } else if (&(t->getReceiver()) == this) {
                this->increaseBalance(amount);
            }
        }
        transactions.push_back(&transaction);
        storeTransaction(transaction);
    }

    static void createDB() {
        fs::path dir{db};

        // Crea la directory se non esiste
        if (!fs::exists(dir)) {
            if (fs::create_directory(dir))
                std::cout << "Directory 'db' creata con successo" << std::endl;
            else {
                std::cerr << "Errore nella creazione della directory 'db'" << std::endl;
            }
        }
    }
/*
    void readStateFromFile(std::string& filename) {
        std::ifstream fileIn(db + "/" + filename);
        std::string line;
        std::string savedData;
        std::string balanceLine;
        if (fileIn.is_open()) {
            if (std::getline(fileIn, line)) {
                balanceLine = line;
            }
            while (std::getline(fileIn, line)) {
                savedData += line + "\n";
            }
            fileIn.close();
        }
        size_t posB = balanceLine.find('B');

        std::string id = balanceLine.substr(2, posB-2);
        if (posB == std::string::npos) {
            std::cerr << "Formato errato: manca 'B'" << std::endl;
        }
        this->id = id;
        double balance = std::stod(balanceLine.substr(posB+1));
        this->balance = balance;
        std::istringstream previousTransactions(savedData);
        while (std::getline(previousTransactions, line)) {

        }

    }
*/
    void storeTransaction(Transaction& transaction) {
        std::string filename = id + ".txt";
        try {
            std::ifstream fileIn(db + "/" + filename);
            std::string out;
            std::ostringstream savedData;

            if (fileIn.is_open()) {
                std::string line;
                if (std::getline(fileIn, line)) {
                    std::string balanceLine;
                    balanceLine = line;
                }
                while (std::getline(fileIn, line)) {
                    savedData << line << std::endl;
                }
                fileIn.close();
            }

            /*
            if (balanceLine.empty() || balanceLine[0] != 'B') {
                std::cerr << "Il file è vuoto o il formato non è valido." << std::endl;
            }
            */

            out += "ID" + id + "B" + std::to_string(balance) + "\n";
            out += savedData.str() + "\n";
            out += transaction.serialize() + "\n";

            std::ofstream fileOut(db + "/" + filename);
            fileOut << out;
            fileOut.close();
        }catch (const std::exception& err) {
            std::cout << err.what() << std::endl;
        }
    }

    void saveState() {

    }

    void displayBalance() const {
        std::cout << "Saldo conto " << id << ": " << balance << std::endl;
    }
    void displayTransactions() const {
        std::cout << "Transactions for " << id << ": " << std::endl;
        for (const auto t : transactions) {
            t->display();
        }
    }
};

#endif //BANKACCOUNT_H

