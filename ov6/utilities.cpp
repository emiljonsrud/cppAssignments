#include "std_lib_facilities.h"
#include "utilities.h"


void charToLower(char &c) {
    char lower = 'a';
    char upper = 'z';
    int intervall = 32;

    if (
        (c < lower or c > upper) and 
        (c + intervall < lower or c + intervall > upper)
        ) {
            string errMsg = "This is not a letter Aa-Zz: ";
            throw invalid_argument(errMsg.push_back(c));
    }
    else if (c < lower) {
        c += intervall;
    }
} 

map<char, int> generateAlphabet() { //char is the key, and int is char-count
    map<char, int> alphabet;
    char lower = 'a';
    char upper = 'z';

    for (char i = lower; i <= upper; i++) {
        alphabet.insert({i, 0});
    }
    return alphabet;
}