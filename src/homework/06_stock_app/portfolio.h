#pragma once
#include <vector>
#include <string>
#include "holding.h"

class Portfolio {
public:
    Portfolio() = default;

    // Add a holding to the portfolio
    void addHolding(const Holding& holding);

    // Remove a holding by symbol
    bool removeHolding(const std::string& symbol);

    // Get total value of the portfolio
    double totalValue() const;

    // Get a const reference to holdings
    const std::vector<Holding>& getHoldings() const;

private:
    std::vector<Holding> holdings_;
};