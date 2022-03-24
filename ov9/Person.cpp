#include "Person.h"

Person::Person(
    std::string n,
    std::string mail
) : name{n}, email{mail} {
    car = nullptr;
}

Person::Person(
    std::string n,
    std::string mail,
    Car c
) : name{n}, email{mail}, car{std::make_unique<Car>(c)} {
    
}