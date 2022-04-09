#include "Person.h"




//# PUBLIC

//##    Operator overloads
std::ostream& operator<<(std::ostream& os, Person &p){
    os << p.getLName() << ", " << p.getFName();
    return os;
}
// bool operator==(Person lhs, Person rhs) {
//     if (
//         lhs.getFName() == rhs.getFName() &&
//         lhs.getLName() == rhs.getLName()
//     ) {return true;}
//     else {return false;}
// }
bool operator<=(Person lhs, Person rhs) {
    // Wish to compare the last names
    std::string lhsName = lhs.getLName();
    std::string rhsName = rhs.getLName();

    // If the last names are equal, we compare the first name
    if(lhsName.compare(rhsName) == 0) {
        lhsName = lhs.getFName();
        rhsName = rhs.getFName();
    }

    if(lhsName.compare(rhsName) <= 0) {return true;}
    else {return false;}
}
// bool operator>=(Person lhs, Person rhs) {
//     return 
// }

//##    Utility functions
void insertOrdered(std::list<Person> &persList, const Person &person) {
    // Deklare a an iterator that will contain the comparison equality
    std::list<Person>::iterator breakPoint;

    // If the list is empty, the person is added as firs element
    if(persList.size() == 0) {
        persList.insert(persList.begin(), person);
        return;
    }
    
    // Iterate through persList and find the point where person <= it
    for(
        std::list<Person>::iterator it = persList.begin(); 
        it != persList.end(); 
        it++
        ) {
        // For every iteration, the breakpoint is updated
        breakPoint = it;

        // If the iterator has reached the end, the breakpoint is that last node 
        if(it == persList.end()) {
            persList.push_back(person);
            return;
        }
    }
    persList.insert(breakPoint, person);
}