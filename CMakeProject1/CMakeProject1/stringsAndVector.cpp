// TODO : what's the best practice on double inclusion of system headers in both .cpp and .h ?

// TODO: Read https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/

#include <iostream>
#include <string>
#include "stringsAndVector.h"

// For unicode...
// The following bombs on MS windows?
//#include <wstring>
// This is suggested instead.
#include <corecrt_wstring.h>

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
		greeting += ", I already told you that !";
	} else {
		greeting += ".  Hmmm.  Glad to meet you?";
	}
	cout << greeting << endl;
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