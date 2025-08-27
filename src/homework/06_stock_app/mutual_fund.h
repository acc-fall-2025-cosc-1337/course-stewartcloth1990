#pragma once
#include <string>
#include <vector>
#include <memory>
#include "holding.h"
#include "investment.h"
#include "stock.h"

#ifndef MUTUAL_FUND_H
#define MUTUAL_FUND_H

class MutualFund: public Investment {
public:
    MutualFund(const std::string& name);

    void AddHolding(const std::shared_ptr<Holding>& holding);
    double GetTotalValue() const;
    std::string GetName() const;

private:
    std::string name_;
    std::vector<std::shared_ptr<Holding>> holdings_;
    double liabilities_;
    int outstanding_shares_;
};

#endif // MUTUAL_FUND_H