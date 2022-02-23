#include "std_lib_facilities.h"
#include "utilities.h"


void charToLower(char &c) {
    int lower = static_cast<int>(char a);
    int upper = static_cast<int>(char z);
    int intervall = 32;

    if (
        (c < lower or c > upper) and 
        (c + intervall < lower or c + intervall > upper) {
        trow invalid_argument(c + " is not a letter Aa-Zz");
    }
    else if (c < lower) {
        c += intervall;
    }
} 
