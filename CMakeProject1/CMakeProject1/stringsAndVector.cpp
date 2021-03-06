﻿// TODO : what's the best practice on double inclusion of system headers in both .cpp and .h ?

// TODO: Read https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/

#include <iostream>
#include <string>
#include "stringsAndVector.h"

// For unicode...
// The following bombs on MS windows?
//#include <wstring>
// This is suggested instead.
// See https://www.cqse.eu/en/blog/living-in-the-ifdef-hell/
#ifdef _WIN32
#include <corecrt_wstring.h>
#elif defined(__linux___) || defined(linux)
// No need for wstring to find std::wstring
//#include <wstring>
#else
do not compile without a wstring implementation
#endif

//#include <corecrt_wstring.h>

using namespace std;

void savDemo() {
	cout << "Simple challenge and response using cout and cin\n";
	hw_string();
	cout << "\nUsing UTF-8 Mandarin - how do we get on here using string not wstring?\n";
	hw_string_mandarin();
}


void hw_string() {
	string name;
	cout << "Hello Torin, what's your name?";
	cin >> name;
	string greeting = "Hello, " + name;
	if (name == "Torin") {
		greeting += "! I already told you that !";
	} else {
		greeting += "!  Hmmm.  Glad to meet you?";
	}
	cout << greeting << endl;

	// Some more interesting stuff.
	cout << "The greeting is " + to_string(greeting.length()) + "characters long\n";

	auto space = greeting.find(' ');
	auto ping = greeting.find('!');
	string found_name = greeting.substr(space+1, (ping-space-1));
	cout << "Pulled out >>" + found_name + "<< from the greeting\n";
}

void hw_string_mandarin() {
	string name;
	cout << "你好 你叫什么名字？";
	cin >> name;
	string greeting = "你好 " + name;
	if (name == "Torin") {
		greeting += ", I already told you that !";
	}
	else {
		greeting += ".  Hmmm. 认识你很高兴";
	}
	cout << greeting << endl;
}


// Vector introduction follows / Collections.
//
// including operations such as sum, sort
// and options to iterate over.
//

#include <vector> 
#include <algorithm> // for sort and count

void hw_vector_fib() {
	vector<int> fib;
	int last = 1;
	fib.push_back(last);
	fib.push_back(last);
	for (int i = 2; i < 10; i++) {
		last = fib[i - 1] + fib[i - 2];
		fib.push_back(last);
	}
	cout << "Created a vector for fibonacci series of size " << fib.size() << "\n";
	double dlast = fib[0];
	for (auto element : fib) {
		cout << element << " ";
		double gratio = static_cast<double>(element) / dlast;
		dlast = static_cast<double>(element);
		cout << gratio << " ";
	}
}

// Demonstrate the difference in passing by reference/pointer/value.

void hw_vector_passby_demo() {

}