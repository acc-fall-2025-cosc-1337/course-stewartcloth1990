#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>

class Investment {
public:
    Investment(const std::string& name, double price)
        : name_(name), price_(price) {}

    virtual ~Investment() = default;

    std::string getName() const { return name_; }
    double getPrice() const { return price_; }

protected:
    std::string name_;
    double price_;
};

#endif // INVESTMENT_H