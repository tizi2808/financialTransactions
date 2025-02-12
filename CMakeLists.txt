cmake_minimum_required(VERSION 3.30)
project(banking_transfers)

set(CMAKE_CXX_STANDARD 20)

add_executable(banking_transfers main.cpp
        Transaction.h
        Deposit.h
        BankAccount.h
        Withdrawal.h
        Deposit.cpp
        Withdrawal.cpp
        BankTransfer.h
        BankTransfer.cpp)
