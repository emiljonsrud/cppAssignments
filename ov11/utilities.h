#pragma once
#include <string>

#include <iostream>
#include <ostream>

#include <set>
#include <vector>
#include <list>

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
    for(typename T1::iterator it = vec.begin(); it != vec.end(); it++) {
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


//##        Assignment 4
template<typename T1>
T1 maximum(T1 lhs, T1 rhs) {
    if(lhs >= rhs) {
        return lhs;
    } else {
        return rhs;
    }
    // This function only works for types with overloaded >=
}

template<typename T1>
void shuffle(std::vector<T1> &vec) {
    for (int i = 0; i < 1000000; i++) {
        int randI = std::rand() % vec.size();
        T1 temp = vec.at(randI);
        
        typename std::vector<T1>::iterator it = vec.begin();
        vec.erase(it + randI);
        vec.push_back(temp);
    }
}
