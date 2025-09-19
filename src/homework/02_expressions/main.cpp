//write include statements
#include <iostream>
#include "hwexpressions.h"

//write namespace using statement for cout
using namespace std;


int main(){
	double meal_amount, tip_rate;
	// Get user input for meal amount and tip rate
	cout << "Enter the meal amount: ";
	cin >> meal_amount;

	cout << "Enter the tip rate (as a decimal - ex. 0.20 for 20%): ";
	cin >> tip_rate;

	// Calculate sales tax, tip amount, and total
	double tax_amount = get_sales_tax_amount(meal_amount);
	double tip_amount = get_tip_amount(meal_amount, tip_rate);
	double total = meal_amount + tax_amount + tip_amount;

	// Display the results
	cout << "Meal Amount: " << meal_amount << endl;
	cout << "Sales Tax Amount: " << tax_amount << endl;
	cout << "Tip Amount: " << tip_amount << endl;
	cout << "Total: " << total << endl;

	return 0;
}