#include "Person.h"

//   Public functions
Person::Person(
    std::string n,
    std::string mail,
    std::unique_ptr<Car> c
) : name{n}, email{mail}, car{std::move(c)} {
    
}

//  Operators
std::ostream& operator<<(std::ostream& os, const Person &person) {
    // This overloaded operator should use 'const', as its only 
    // purpouse is to return data to a stream, i.e. it is not indendet
    // to change anything

    // Print name
    os << std::left << std::setw(12) << std::setfill(' ');
    os << "Name:";
    os << std::right << std::setw(30) << std::setfill(' ');
    os << person.getName() << std::endl;


    // Print available seats if person has available seats
    os << std::left << std::setw(12) << std::setfill(' ');
    os << "Free seats:";
    os << std::right << std::setw(30) << std::setfill(' ');
    if (person.hasAvailableSeats()) {
        os << "Yes" << std::endl;
    } else {
        os << "No" << std::endl;
    }


    // Print email
    os << std::left << std::setw(12) << std::setfill(' ');
    os << "e-mail:";
    os << std::right << std::setw(30) << std::setfill(' ');
    os << person.getEmail() << std::endl;
    
    return os;
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

