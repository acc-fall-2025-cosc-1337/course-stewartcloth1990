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
			cout << "Enter a DNA string: " << "\n";
			cin >> dna;

			double gc_content = get_gc_content(dna);

			cout << fixed << setprecision(3);
			cout << "The GC content of " << dna << " is " << gc_content << "\n";
		}

		else if (choice == 2)
		{
			cout << "Enter a DNA string: " << "\n";
			cin >> dna;

			
		}

		else (choice == 3);

	} while (choice != 3);

	return 0;
}
