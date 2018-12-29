// TODO: Read https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/
#include <iostream>
#include <string>

// See https://www.cqse.eu/en/blog/living-in-the-ifdef-hell/
#ifdef _WIN32
	#include <corecrt_wstring.h>
#elif defined(__linux___) || defined(linux)
// Bad idea - note for future reference
//	#include <wstring>
#else
	do not compile without a wstring implementation
#endif

#include <math.h>
#include "joelOnUnicode.h"



/**
* Implement some basic demonstrations of Unicode to show we understand Joel's point from 2003.
*/

/**
* Brief summary of Joel's main points.

char type is 8 bits, so 255 patterns.
0-127 used in common for ASCII
128-255 used variously for international mappings with different code pages
ANSI standard applied uniformity
For Asian languages, DBCS double byte character set invented
To be space efficient, may use one OR two characters
Now walking strings in memory by s++ is OK, but s-- YMMV (aka broken)
Windows invents AnsiNext and AnsiPrev.   How efficient.

Unicode extends concept of character to more than 8 bits.
A unicode letter is the abstraction of a letter.
Every human language distinct letter has a unique number: the code point
Notation : U+0639 : U+ = Unicode 0639 = 0x639 hex = arabic letter Ain
Unicode website decodes the code points at http://www.unicode.org/
Fonts are a different thing.
Note - you can adopt a character !  Also includes Emojis !
Encodings are ways to store and manipulate code points in memory.
Option 1 : pairs of 16 bit values, either big endian or little endian
First character in a unicode string will be the unicode byte order mark
If FE FF : normal, if FF FE : byte swap
This is called UCS-2 or UTF-16 (low or high endian)
UTF-8 : code point may need up to 6 consecutive bytes
UCS-4 : uses 4 bytes for each and every character (simple but inefficient)

Some legacy compatible encodings are permitted to be incomplete (i.e. certain code points render as invalid/?)

So : given an array of bytes, you also need an encoding to know how to treat it.

Internet Streams should exchange
Content-Type: text/plain; charset = "UTF-8"
Bootstrapping : the preamble of any well formed web page
<html><head><meta http-equiv="Content-Type" content="text/html; charset=utf-8">
is all rendered in characters ASCII 32-127 which will be identical in
all reasonable encodings.
In the absence of the hint, IE takes a statistical punt based on
knowledge of letter distributions (interesting)
Postel's law : " be conservative in what you emit, liberal in what you accept"

@2003 FogCreek policy was :
all strings in wchar_t (not char)
wcs functions in place of str (e.g. wcscat for strcat, wcslen for strlen)


Now - see also http://kunststube.net/encoding/
This claims that Joel was oversimplifying...
Unicode allocates space for 1,114,112 values
Hence : 4 bytes is enough, 3 bytes also, but somewhat awkward in terms of memory alignment.
*/

/**
* TODO : Exercise rewriting and then examining in godbolt compiler explore the constexpr versions.
*/


using namespace std;

string asBytesBitsPatterns(string entity, size_t size) {
	string desc = entity;
	int isize = static_cast<int>(size);
	string sizeInBytes = to_string(isize);
	string sizeInBits = to_string(8 * isize);
	string nOfPatterns = to_string(pow(2, static_cast<double>(8*isize)));
	desc += " is " + sizeInBytes + " bytes " + sizeInBits + " bits " + " can represent " + nOfPatterns + " patterns " + string("\n");
	return desc;
}

void basicDimensions() {
	string entity = "char";
	cout << asBytesBitsPatterns(entity, sizeof(char));
	entity = "wchar_t";
	cout << asBytesBitsPatterns(entity, sizeof(wchar_t));
	entity = "char[2]";
	cout << asBytesBitsPatterns(entity, sizeof(char[2]));
	entity = "char[3]";
	cout << asBytesBitsPatterns(entity, sizeof(char[3]));
	entity = "char[4]";
	cout << asBytesBitsPatterns(entity, sizeof(char[4]));
}

