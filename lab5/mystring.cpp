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
        current_length = strlen(str);
        allocated = current_length + 1;
        characters = new char(allocated);
        strncpy(characters, str, current_length);
    }
    string::string(char c){
        current_length = 1;
        allocated = current_length + 1;
        characters = new char(allocated);
        characters[0] = c;
    }
    string::string(const string& source){
        current_length = source.current_length;
        allocated = current_length + 1;
        characters = new char(allocated);
        strncpy(characters, source.characters, current_length);
    }
    string::~string(){
        delete [] characters;
    }

    void string::operator +=(const string& addend) {
        current_length = current_length + addend.current_length;
        reserve(current_length);
        copy(addend.characters, addend.characters + addend.current_length, characters + current_length);
    }
    void string::operator +=(const char addend[ ]) {
        current_length = current_length + strlen(addend);
        characters = strncat(characters, addend, current_length);
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
        reserve(source.current_length + 1);
        copy(source.characters,source.characters + source.current_length, characters);
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
