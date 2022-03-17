#include "Menu.h"

#include "exersizeFunctions.h"

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




    menu.activateMenu();
}