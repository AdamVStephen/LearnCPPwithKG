#include <iostream>
#include <climits>
#include "functions.h"

using namespace std;

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return b - a;
}

int mul(int a, int b) {
	return a * b;
}


/**
* Unit tests and exploring the obvious limitations with respect to type safety of the above functions.
*/

bool ut_functions() {
	bool res = true;
	res |= ut_add_overflow();
	return res;
}

bool ut_add_overflow() {
	int imax = INT_MAX;
	int imin = INT_MIN;
	int imaxinc = add(imax, 1);
	int imindec = sub(1, imin);
	
	cout << "sizeof(int) is " << sizeof(int) << endl;
	cout << "INT_MAX is " << imax << " adding 1 gives " << imaxinc << endl;
	cout << "INT_MIN is " << imin << " subtracting 1 gives " << imindec << endl;

	return true;
}
