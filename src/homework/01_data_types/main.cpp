//write include statements

#include "data_types.h"
#include "data_types.cpp"

//main function definition for multiply_numbers
int main()
{

	int result = multiply_numbers(7, 7);
	cout << "Result: " << result << "\n";

	result = multiply_numbers(5, 5);
	cout << "Result: " << result << "\n";

	int num1, num2;
	std::cout << "Enter first number: ";
	std::cin >> num1;
	std::cout << "Enter second number: ";
	std::cin >> num2;

	int result = multiply_numbers(num1, num2);
	std::cout << "Result: " << result << std::endl;

	return 0;
}