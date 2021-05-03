// AUTHOR: Zach Azer
// FILE: mystring.cpp
// CLASS IMPLEMENTED: mystring (see mystring.h for documentation)
#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include <cstring>
#include "mystring.h"

using namespace std;

namespace coen79_lab5{
    string::string(const char str[ ] = ""){
        assert(str == '\0');
        
    }
}
