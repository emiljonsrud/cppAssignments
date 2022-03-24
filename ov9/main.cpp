#include "Menu.h"

#include "Person.h"
#include "Meeting.h"

int main(){
    Menu menu;
    
    menu.addItem(MenuItem{
        "Test people class",
        []() {
            // Create some people to test with
            Person p1{"Emil", "emil@gmail.com"};
            std::cout << p1 << std::endl;

            Person p2{"Sindre", "miatalover69@hotmail.com", std::make_unique<Car>(Car(1))};
            std::cout << p2 << std::endl;

            Person p3{"Matias", "stud@ass.com", std::make_unique<Car>(Car{3})};
            std::cout << p3 << std::endl;
        }
    });

    menu.addItem(MenuItem{
        "Test campus",
        []() {
            std::cout << Campus::trd << std::endl;
            std::cout << Campus::aal << std::endl;
            std::cout << Campus::gjo << std::endl;
        }
    });
    

    menu.activateMenu();
}