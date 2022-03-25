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

    //#     Exersize 3
    menu.addItem(MenuItem{
        "Test campus",
        []() {
            std::cout << Campus::trd << std::endl;
            std::cout << Campus::aal << std::endl;
            std::cout << Campus::gjo << std::endl;
        }
    });
    /*
            Exersize 3e
            When we create the Meeting class, it does not allocate any new space for 
            Persons, instead it uses a shared pointer pointing to the Persons in the
            memory. When Meeting is destructed, the shared pointer is deleted, which
            means that the count of pointers pointing to the Persons si decreased by 
            one.
    */

   menu.addItem(MenuItem{
       "Test meeting",
       []() {
           // Create shared pointers to people to test with
            std::shared_ptr<Person> p1_ptr = std::make_unique<Person>(Person{
                "Emil", 
                "emil@gmail.com"
            });
            std::shared_ptr<Person> p2_ptr = std::make_unique<Person>(Person{
                "Sindre", 
                "miatalover69@hotmail.com", 
                std::make_unique<Car>(Car(1))
            });
            std::shared_ptr<Person> p3_ptr = std::make_unique<Person>(Person{
                "Matias", 
                "stud@ass.com", 
                std::make_unique<Car>(Car{3})
            });
            
            // Create a Meeting to test with
            Meeting meet1{
                2, 
                815, 
                1000, 
                Campus::trd, 
                "Intro Topologi", 
                p1_ptr
            };
            meet1.addParticipant(p2_ptr);
            meet1.addParticipant(p3_ptr);
            std::cout << meet1;
       }
   });


    

    menu.activateMenu();
}