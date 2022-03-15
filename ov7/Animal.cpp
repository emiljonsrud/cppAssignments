#include "Animal.h"
#include "std_lib_facilities.h"



//      Animal
// PUBLIC



Animal::Animal(string n, int a) : name{n}, age{a} {

}

string Animal::toString() {
    return "Animal: " + name + ", " + to_string(age);
}




//      Cat
Cat::Cat(string n, int a) : Animal{n, a} {

}

string Cat::toString() {
    return "Cat: " + name + ", " + to_string(age);
}


//      Dog
Dog::Dog(string n, int a) : Animal{n, a} {
    
}
string Dog::toString() {
    return "Dog: " + name + ", " + to_string(age);
}

