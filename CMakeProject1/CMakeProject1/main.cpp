#include <iostream>

#include "functions.h"

int main(int argc, char * argv[])
{
	// use of the extraction operator
	std::cout << "Hello CMake\n";

	// call functions unit tests (todo - learn how to use proper CppUnit or Google Test or ...yadayada
	// Note - throwing away the bool.
	ut_functions();

	// use of functions
	int a = 40;
	int b = 2;
	int sum = add(a, b);
	int diff = sub(b, a);
	std::cout << "Adding " << a << " and " << b << " gives " << sum << std::endl;
	std::cout << "Subtracting " << b << " from " << a << " gives " << diff;

	std::cout << "The End\n";
	return 0;
}