// AUTHOR: Zach Azer
// FILE: mystring.cpp
// CLASS IMPLEMENTED: mystring (see mystring.h for documentation)
#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include <cstring>
#include <cmath>     // Provides pow(base, exponent)
#include <climits>   // Provides UINT_MAX
#include "mystring.h"

using namespace std;

namespace coen79_lab5
{
    string::string(const char str[ ] = ""){
        assert(str == '\0');
        
    }
    void string::operator +=(const string& addend) {

    }
    void string::operator +=(const char addend[ ]) {

    }
    void string::operator +=(char addend) {

    }

    void string::reserve(size_t n) {
        if (n == allocated) {
            return;
        }
        if (allocated > n) {
            n = allocated;
        }
        char *tmp = new char[n];
        copy(characters,characters+current_length, tmp);
        delete [] characters;
        characters = tmp;
        allocated = n+1;

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
