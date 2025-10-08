#include <iostream>
#include <iomanip>
#include "func.h"

using namespace std;
using std::cout;
using std::cin;


int main() 
{
	int choice;
	string dna;

	do
	{
		cout << "Menu" << "\n" << "1 - Get GC Content " << "\n" << "2 - Get DNA Complement " << "\n" << "3 - Exit" << "\n";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Please enter a DNA string: " << "\n";
			cin >> dna;

			cout << "The GC content of the string provided is " << dna << "\n";
		}

		else if (choice == 2)
		{

		}

		else (choice == 3);

	} while (choice != 3);

	return 0;
}
