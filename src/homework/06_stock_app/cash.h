#ifndef CASH_H
#define CASH_H

#include <iostream>
#include <iomanip>

class Cash {
private:
    double balance;

public:
    Cash(double initial_balance = 0.0) : balance(initial_balance) {}

    double get_balance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void print_balance() const {
        std::cout << "Cash Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }
};

#endif // CASH_H