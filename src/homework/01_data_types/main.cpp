//write include statements
#include "data_types.h"
#include <iostream>


//write namespace using statement for cout
using std::cout;

int main()
{

	int result = multiply_numbers(7, 7);
	cout << "Result: " << result << "\n";

	result = multiply_numbers(5, 5);
	cout << "Result: " << result << "\n";

	return 0;
}