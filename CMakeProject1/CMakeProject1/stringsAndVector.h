#pragma once
// TODO : What does #pragma once do ?  Presumably this implements idempotency?

#include <string>

// See https://www.cqse.eu/en/blog/living-in-the-ifdef-hell/
#ifdef _WIN32
#include <corecrt_wstring.h>
#elif defined(__linux___) || defined(linux)
//#include <wstring>
#else
do not compile without a wstring implementation
#endif

//#include <corecrt_wstring.h>

void savDemo();
void hw_string();
void hw_string_mandarin();
