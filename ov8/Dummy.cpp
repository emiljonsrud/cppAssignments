#include "Dummy.h"

#include <iostream>
#include <utility>

Dummy::Dummy(const Dummy &other) {
    this ->num = new int{};
    *num = *other.num;
}
Dummy Dummy::operator=(Dummy rhs) {
    //  Spørsmål til studass: hva er greia her, jeg 
    //  skjønner ikke. 
    
    // this ->num = rhs.num;
    std::swap(num, rhs.num);
    return *this;
}