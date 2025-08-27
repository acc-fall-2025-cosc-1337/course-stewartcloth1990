// filepath: /workspaces/course-artgonzalezacc/src/homework/stock-app/bond.h
#ifndef BOND_H
#define BOND_H

#include "investment.h"
#include <string>

class Bond : public Investment {
public:
    Bond(const std::string& name, double price, double interestRate)
        : Investment(name, price), interestRate_(interestRate) {}

    double getInterestRate() const { return interestRate_; }

private:
    double interestRate_;
};

#endif // BOND_H