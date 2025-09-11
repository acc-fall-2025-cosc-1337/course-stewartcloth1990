//write include statements
#include <iostream>
#include "data_types.h"

//main function definition for multiply_numbers
int main()
{
	int num1, num2;
	std::cout << "Enter first number: ";
	std::cin >> num1;
	std::cout << "Enter second number: ";
	std::cin >> num2;

	int result = multiply_numbers(num1, num2);
	std::cout << "Result: " << result << std::endl;

	return 0;
}