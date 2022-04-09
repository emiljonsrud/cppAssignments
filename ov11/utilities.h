#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include <set>

template<typename T1, typename T2>
void replace(T1 &vec, T2 old, T2 replacement) {
    // Iterate through vec
    for(typename T1::iterator it = vec.begin(); it != vec.end(); it++) {
        // If the current elem. is old, it is to ble replaced
        if(*it == old) {
            vec.erase(it);
            vec.insert(it, replacement);
        }
    }
}
//      Spørsmål til studass: Må denne^^^  deklarasjonen ligge her i .h filen?

template<typename T1>
void print(T1 vec) {
    // Iterate through the vector in the reversed direction
    for(typename T1::const_iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << "    " << *it << std::endl;
    }
}
template<typename T1>
void printReversed(T1 vec) {
    for(typename T1::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++) {
        std::cout << "    " << *it << std::endl;
    }
}

// void replace(std::vector<std::string> &vec, std::string old, std::string replacement);