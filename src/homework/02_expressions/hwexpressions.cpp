#include "hwexpressions.h"

// Calculate the sales tax amount
double get_sales_tax_amount(double meal_amount) {
	return meal_amount * tax_rate;
}

// Calculate the tip amount
double get_tip_amount(double meal_amount, double tip_rate) {
	return meal_amount * tip_rate;
}
