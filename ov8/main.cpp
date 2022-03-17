#include "Menu.h"

#include "exersizeFunctions.h"
#include "Matrix.h"

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
            Matrix A{4};
            std::cout << A[0][2] << ", " << A[3][3] << std::endl;
        }
    });





    menu.activateMenu();
}