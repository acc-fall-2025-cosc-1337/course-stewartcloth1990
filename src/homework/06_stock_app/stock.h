#ifndef STOCK_H
#define STOCK_H

#include <string>

#include "investment.h"

class Stock : public Investment {
public:
    Stock(const std::string& symbol, double price)
        : Investment(symbol, price) {}

    std::string getSymbol() const { return getName(); }
    double getPrice() const { return Investment::getPrice(); }

    void setPrice(double newPrice) { price_ = newPrice; }
};

#endif // STOCK_H