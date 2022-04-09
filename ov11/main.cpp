#include "Menu.h"

int main(){
    //  Create a menu
    Menu menu;


    //#     Assignment 1
    menu.addItem(MenuItem{
        "Iterator",
        []() {
            // Create a vector containing strings, and add some strings
            std::vector<std::string> stringVec;
            stringVec.push_back("Lorem");
            stringVec.push_back("Ipsum");
            stringVec.push_back("Dolor");
            stringVec.push_back("Sit");
            stringVec.push_back("Amet");
            stringVec.push_back("Consectetur");


            
        }
    });
    

    menu.activateMenu();
}