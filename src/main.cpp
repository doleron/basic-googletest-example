#include <iostream>

#include "very_important_operations.h"

int main(int argc, char** argv) {
	std::cout << "This project is just an example of cmake build for google test API";

	const int n = 13;
	auto result = int_factorial(n);

	std::cout << "The factorial of " << n << " is " <<  result << '\n';

	std::cout << "The project can be built for testing or not testing";

}