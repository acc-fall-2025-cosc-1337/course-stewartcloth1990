#pragma once
#include "investment.h"
#include <string>

class Holding {
public:
    Holding(const Investment& investment, int shares)
        : investment_(investment), shares_(shares) {}

    const Investment& getInvestment() const { return investment_; }
    int getShares() const { return shares_; }
    void setShares(int shares) { shares_ = shares; }

    double getMarketValue() const {
        return shares_ * investment_.getPrice();
    }

    std::string getName() const {
        return investment_.getName();
    }

private:
    Investment investment_;
    int shares_;
};