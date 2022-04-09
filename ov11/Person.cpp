#include "Person.h"




//# PUBLIC

//##    Operator overloads
std::ostream& operator<<(std::ostream& os, Person p){
    os << p.getLName() << ", " << p.getFName();
    return os;
}