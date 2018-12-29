#include <iostream>

#include "functions.h"
#include "stringsAndVector.h"
#include "joelOnUnicode.h"
#include "portable.h"

using namespace std;

int main(int argc, char * argv[])
{
	// use of the extraction operator
	std::cout << "Hello CMake\n";

	// portability checks
	showPortabilitySymbols();

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


	// String Exploration
	savDemo();

	// To get to unicode slowly.
	string entity = "char";
	size_t charsize = sizeof(char);
	int charsize_int = static_cast<int>(charsize);
	//string entitysize = string(charsize);
	cout << (
		string("information about char follows\n")	+ \
		string("information\n") + \
		to_string(5) + to_string(charsize_int) + \
		string("char size is ") + to_string(static_cast<int>(sizeof(char))) + string("\n")
		);

	// Unicode Exploration
	basicDimensions();

	std::cout << "The End\n";
	return 0;
}