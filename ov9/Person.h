#pragma once
#include "Car.h"

#include <string>
#include <memory>

class Person{
private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> car;

public:
    // Er det en måte å lage bare én kontstruktør?
    //  Constructors 
    Person(
        std::string n, 
        std::string mail
    );
    Person(
        std::string n, 
        std::string mail,
        Car c
    );

    //  Gets
    std::string getName() const {return name;}
    std::string getEmail() const {return email;}

    //  Sets
    void setEmail(const std::string newEmail) {email = newEmail;}
    

};