#include "exersizeFunctions.h"
#include "std_lib_facilities.h"

#include "Animal.h"


void testAnimal() {
    // Create an empty vector of Animal types and fill it 
    // cats and dogs 
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Dog("Terry", 35));
    animals.emplace_back(new Cat("Jerry", 35));
    animals.emplace_back(new Cat("Garfield", 40));
    animals.emplace_back(new Cat("Spot", 2));
    animals.emplace_back(new Dog("Tucker", 12));
    animals.emplace_back(new Cat("Max", 6));
    animals.emplace_back(new Dog("Toby", 4));
    animals.emplace_back(new Dog("Tank", 14));

    for (auto const& animal : animals) {
        cout << animal -> toString() << endl;
    }

     
    
}


