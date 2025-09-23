//write include statements
#include "decisions.h"
#include "iostream"

using namespace std;

int main() 
{
	int grade;
	std::cout << "Main Menu\n 1 - Letter grade using if\n 2- Letter grade using switch\n 3 - Exit\n";
	std::cin >> grade;

	// IF STATEMENTS FOR 1st OPTION
	if (grade == 1){
		std::cout << "Enter a number between 0 and 100: \n";
		std::cin >> grade;
		
		// show letter grade if number within range
		if (grade >= 0 && grade <= 100){
			std::cout << "Letter grade: " << get_letter_grade_using_if(grade) << "\n";
		}

		// informs user if numbers outside of range
		else {
			std::cout << "Number is out of range.";
		}

	}

	// SWITCH STATEMENTS FOR 2nd OPTION
	if (grade == 2){
		std::cout << "Enter a number between 0 and 100: \n";
		std::cin >> grade;

		// show letter grade if number within range
		if (grade >= 0 && grade <= 100){
			std::cout << "Letter grade: " << get_letter_grade_using_if(grade) << "\n";
		}

		// informs user if numbers outside of range
		else {
			std::cout << "Number is out of range.";
		}

	}

	// exiting program if 3 or anything else is entered
	else{
		std::cout << "Exit";
	}
	
	return 0;
}

