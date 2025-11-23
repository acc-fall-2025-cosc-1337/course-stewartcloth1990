//write include statements
#include <iostream>
#include "do_while.h"

//write using statements
using std::cout;
using std::cin;
using std::string;
using std::fixed;
using std::setprecision;

int main() 
{	
	// variable to hold user menu selection
	int user_choice;

	do // loop until user exits program
	{
		double amount;
		string bill_name;

		cout << "Main Menu" << "\n" << "1. Calculate Bill Totals" << "\n" << "2. Exit program" << "\n";
		cin >> user_choice;

		if (user_choice == 1) // option 1
		{
			int inner_choice;

			do // receiving input from user and calculating bill amounts
			{
				cout << "Give a name for this bill: ";
				cin >> bill_name;

				cout << "How much is due for the bill: " << "\n";
				cin >> amount;

				double new_amount = divide_bill_amount(amount);

				cout << "The amount you'll need to pay weekly for " << bill_name << " is $" << new_amount << ". \n";

				cout << "Do you want to enter another bill? Enter 1 to continue, 2 to exit the program: ";
				cin >> inner_choice;

			} while (inner_choice == 1);

			// setting user choice based on inner menu selection
			if (inner_choice == 1) user_choice = 1;
			else user_choice = 2;
		}

		else if (user_choice == 2) // exit option
		{
			cout << "Exiting the program." << "\n";
		}

		else // invalid input option
		{
			cout << "Invalid selection. Please enter either 1 or 2." << "\n";
		}

	} while (user_choice != 2); // continue looping until user chooses to exit
	return 0;
}