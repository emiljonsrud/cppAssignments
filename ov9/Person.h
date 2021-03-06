#pragma once
#include "Car.h"

#include <string>
#include <memory>

#include <iostream>
#include <iomanip>

class Person{
private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> car;

public:
    //  Constructors 
    Person(
        std::string n,      // Name
        std::string mail,   // Email
        std::unique_ptr<Car> = nullptr // Car
    );

    //  Gets
    std::string getName() const {return name;}      // Name
    std::string getEmail() const {return email;}    // Email

    //  Sets
    void setEmail(const std::string newEmail) {email = newEmail;}
    
    //  Operators

    //  Other functions
    bool hasAvailableSeats() const;

};
// Non-member functions
std::ostream& operator<<(std::ostream& os, const Person &person);