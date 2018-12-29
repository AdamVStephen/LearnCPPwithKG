#include <iostream>

#include "portable.h"

/**
* Routine to show which compiler/platform symbols are recognised
*/

using namespace std;

// TODO: does the C++ standard say anything about this?

void showPortabilitySymbols() {
	cout << "shortPortabilitySymbols from portable.cpp finds definitions for:\n";
#ifdef linux
		cout << "#ifdef linux : Y\n";
#endif

#ifdef __linux__
	cout << "#elif __linux__ : Y\n";
#endif

#ifdef _WIN32
	cout << "#elif _WIN32 : Y\n";
#endif

#ifdef WIN32
	cout << "#elif WIN32 : Y\n";
#endif // WIN32

#if !defined(linux) && !defined(__linux__) && !defined(WIN32) && !defined(_WIN32)
#	cout << "none of linux, __linux__, WIN32, _WIN32 defined\n";
#endif

}