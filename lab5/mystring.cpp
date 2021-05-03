// AUTHOR: James Dameris
// FILE: mystring.cpp
// CLASS IMPLEMENTED: mystring (see mystring.h for documentation)
#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include <cmath>     // Provides pow(base, exponent)
#include <climits>   // Provides UINT_MAX
#include "mystring.h"

using namespace std;

namespace coen79_lab5
{

    void string::operator +=(const string& addend) {

    }
    void string::operator +=(const char addend[ ]) {

    }
    void string::operator +=(char addend) {

    }

    void string::reserve(size_t n) {

    }

    string& string::operator =(const string& source) {

    }

    void string::insert(const string& source, unsigned int position) {

    }

    void string::dlt(unsigned int position, unsigned int num) {

    }

    void string::replace(char c, unsigned int position) {

    }

    void string::replace(const string& source, unsigned int position) {

    }

    char string::operator [](size_t position) const {

    }

    int string::search(char c) const {

    }

    int string::search(const string& substring) const {

    }

    unsigned int string::count(char c) const {

    }

    std::ostream& operator <<(std::ostream& outs, const string& source) {

    }

    bool operator ==(const string& s1, const string& s2) {

    }

    bool operator !=(const string& s1, const string& s2) {

    }

    bool operator > (const string& s1, const string& s2) {

    }

    bool operator < (const string& s1, const string& s2) {

    }

    bool operator >=(const string& s1, const string& s2) {

    }

    bool operator <=(const string& s1, const string& s2) {

    }

    string operator +(const string& s1, const string& s2) {

    }

    string operator +(const string& s1, const char addend[ ]) {

    }

    std::istream& operator >> (std::istream& ins, string& target) {

    }


}