#include "Menu.h"

#include "exersizeFunctions.h"
#include "Matrix.h"

#include <iostream>


int main()
{
    //  Initialize the menu
    Menu menu;
    

    //  This is for testing
    menu.addItem(MenuItem{
        "Test function",
        []() {
            testCode();
        }
    });

    //  Exersize 1
    menu.addItem(MenuItem{
        "Fibonacci",
        []() {
            createFibonacci();
        }
    });

    //  Exersize 2
    menu.addItem(MenuItem{
        "Test matrix I_4",
        []() {
            testMatrix();
        }
    });





    menu.activateMenu();
}