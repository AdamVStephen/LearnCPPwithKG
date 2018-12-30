/**
* Demonstrate pass by semantics and overheads
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include "passing.h"

void passNativeByVal(int val) {
	val = 42;
	printf("%s: val at %p set to %d\n", __func__, &val, val);
}

void passNativeByRef(int& val) {
	val = 420;
	printf("%s: val at %p set to %d\n", __func__, &val, val);
}

void passNativeByPtr(int* val) {
	*val = 4200;
	printf("%s: val at %p set to %d\n", __func__, &val, val);
}
