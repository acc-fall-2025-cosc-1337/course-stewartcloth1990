#include <iostream>
#include <iomanip>
#include "func.h"

using namespace std;
using std::cout;
using std::cin;


int main() 
{

	int choice;

	// Loop until user chooses to exit
	do
	{
		// intializing dna variable
		string dna;

		cout << "Menu" << "\n" << "1 - Get GC Content " << "\n" << "2 - Get DNA Complement " << "\n" << "3 - Exit" << "\n";
		cin >> choice;

		// GC content option
		if (choice == 1)
		{
			do
			{
				cout << "Enter a DNA string: " << "\n";
				cin >> dna;

				// input validation loop 
				if (!is_valid_dna(dna))
				{
					cout << "That's not a DNA string. Please enter only characters A, T, C, or G. \n";
				}
				
			} while (!is_valid_dna(dna));

			double gc_content = get_gc_content(dna);

			cout << fixed << setprecision(3);
			cout << "The GC content of " << dna << " is " << gc_content << "\n";
			
		}

		// DNA complement and reversal option
		else if (choice == 2)
		{
			string complement;
			string complement_reverse;

			do
			{
    			cout << "Enter a DNA string: " << "\n";
    			cin >> dna;

				// input validation loop
    			if (!is_valid_dna(dna))
				{
        			cout << "Invalid DNA string. Please enter only characters A, T, C, or G.\n";
    			}

			} while (!is_valid_dna(dna));

			complement = get_dna_complement(dna);
			complement_reverse = get_reverse_string(dna);

			cout << "The complement to the DNA string is " << complement << "\n";
			cout << "The reverse complement of the DNA string is " << complement_reverse << "\n";
		}

		// Exit option
		else if (choice == 3)
		{
			cout << "Exiting program..." << "\n";
		}

		// Invalid option handling
		else
		{
			cout << "Invalid choice. Please select 1, 2, or 3." << "\n";
		}

	// End of do-while loop
	} while (choice != 3);

	return 0;
}
