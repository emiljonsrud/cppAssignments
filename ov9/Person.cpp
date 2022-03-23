#include "Person.h"

Person::Person(
    std::string n, 
    std::string mail) : name{n}, email{mail} {
    car = nullptr;
}
Person::Person(
    std::string n,
    std::string mail,
    std::unique_ptr<Car> c
    ) : name{n}, email{mail}, car{c} {

    }