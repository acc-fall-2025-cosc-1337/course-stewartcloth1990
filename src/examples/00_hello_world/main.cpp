#include <iostream>
#include <iomanip>
#include "practice.h"

using namespace std;

int main()
{
    double meal_amount, tip_rate;
    cout << "\nEnter the amount for the meal as a decimal (ex, 10.50): $";
    cin >> meal_amount;
    cout << "Enter the tip rate as a decimal (ex. 0.2 for 20%): $";
    cin >> tip_rate;

    double sales_tax = get_sales_tax(meal_amount);
    double tip_total = get_tip_amount(meal_amount, tip_rate);
    double meal_total = meal_amount + sales_tax + tip_total;

    cout << fixed << setprecision(2);
    cout << "\n--Receipt--" << endl;
    cout << "\n***************" << endl;
    cout << "\nMeal Amount: $" << meal_amount << endl;
    cout << "Sales Tax: $" << sales_tax << endl;
    cout << "Tip Amount: $" << tip_total << endl;
    cout << "\n***************" << endl;
    cout << "\nTotal: $" << meal_total << endl;

    return 0;
}