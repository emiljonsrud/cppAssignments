#include "Menu.h"
#include "LinkedList.h"
#include "utilities.h"


int main(){
    //  Create a menu
    Menu menu;


    //#     Assignment 1
    menu.addItem(MenuItem{
        "String vector iterators",
        []() {
            // Create a vector containing strings, and add some strings
            std::vector<std::string> stringVec {
                "Lorem",
                "Ipsum",
                "Dolor",
                "Sit",
                "Lorem",
                "Amet",
                "Consectetur",
                "Lorem"
            };
            
            std::cout << "String vector:" << std::endl;
            print(stringVec);

            std::cout << "\nString vector revesed:" << std::endl;
            printReversed(stringVec);


            std::cout << "\n";
            std::string old = "Lorem";
            std::string rep = "Modern english word";
            
            std::cout << "Repacing <<" << old << ">> with <<" << rep << ">> :" << std::endl;
            replace(stringVec, old, rep);
            // Print the changed stringVec
            print(stringVec);
        }
    });
    
    //#     Doing the same porcedure for sets
    menu.addItem(MenuItem{
        "String set iterators",
        []() {
            //Create a set of strings
            std::set<std::string> strSet{
                "Lorem",
                "Ipsum",
                "Dolor",
                "Sit",
                "Lorem",
                "Amet",
                "Consectetur",
                "Lorem"
            };
            std::cout << "String set:" << std::endl;
            print(strSet);

            std::cout << "\nReversed string set:" << std::endl;
            printReversed(strSet);


            std::cout << "\n";
            std::string old = "Lorem";
            std::string rep = "Modern english word";
            
            std::cout << "Repacing <<" << old << ">> with <<" << rep << ">> :" << std::endl;
            replace(strSet, old, rep);
            // Print the changed stringVec
            print(strSet);
        }        
    });


    

    menu.activateMenu();
}