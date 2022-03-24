#include "Person.h"

//   Public functions
Person::Person(
    std::string n,
    std::string mail,
    std::unique_ptr<Car> c
) : name{n}, email{mail}, car{std::move(c)} {
    
}

//      Other funcitons
bool Person::hasAvailableSeats() const {
    // If the person both has a car, and said car
    // has available seats, the function returns true

    if (car.get() != nullptr) {
        if (car.get()->hasFreeSeats()) {
            return true;
        }
    }
    return false;
}