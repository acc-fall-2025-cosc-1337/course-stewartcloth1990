#include "hwexpressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write function code here

// Sales tax rate is 6.75/100 -> 0.0675
const double tax_rate = 0.0675;

// Calculate the sales tax amount
double get_sales_tax_amount(double meal_amount)
{
	return meal_amount * tax_rate;
}

// Calculate the tip amount
double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * tip_rate;
}
