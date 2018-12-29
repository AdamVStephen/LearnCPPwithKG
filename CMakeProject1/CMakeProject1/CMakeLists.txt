# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Note integration with VS code uses some extra files such as 
# C:\Users\astephen\Source\Repos\LearnCPPwithKG\CMakeProject1\.vs\launch.vs.json
# Solution "Explorer" hides the .vs files so this is still using the typical MS strategy of hidden files.


# Add source to this project's executable.
#add_executable (CMakeProject1 "CMakeProject1.cpp" "CMakeProject1.h")
add_executable (main "main.cpp" 
	"functions.cpp" "functions.h" 
	"stringsAndVector.cpp" "stringsAndVector.h"
	"joelOnUnicode.cpp" "joelOnUnicode.h"
	"portable.cpp" "portable.h"
	)

# TODO: Add tests and install targets if needed.
