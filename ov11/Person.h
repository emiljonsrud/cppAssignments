#pragma once
#include "utilities.h"

class Person{
private:
    std::string fName;
    std::string lName;

public:
    //# Constructor
    Person(std::string firstName, std::string lastName) 
    : fName{firstName}, lName{lastName}{};

    //# Gets
    std::string getFName() const {return fName;}
    std::string getLName() const {return lName;}

    //# Sets
    void setFName(std::string n) {fName = n;}
    void setLName(std::string n) {lName = n;}

    
};
//# Operator overloads
std::ostream& operator<<(std::ostream& os, Person& p);