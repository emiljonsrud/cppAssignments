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
    Person(
        std::string n, 
        std::string mail 
        );

};