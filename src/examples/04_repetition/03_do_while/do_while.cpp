#include "do_while.h"

double divide_bill_amount(double amount) // dividing the bill amount due into 4 chunks to spread out over a month
{
    double total_to_pay = amount / 4;

    return total_to_pay;
}
