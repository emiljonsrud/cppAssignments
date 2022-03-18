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
            // Test the id-matrix constructor
            Matrix A{4};
            std::cout << A;
            
            // Test the M*N-matrix constructor
            Matrix B{5, 8};
            std::cout << B;

            // Test getRows() and getColumns()
            std::cout << "Rows: " << B.getRows() 
            << ", columns: " << B.getColumns() << std::endl;
            
            //  Test set and get
            B.set(3, 4, 6.9);
            std::cout << B[3][4] << " = " << B.get(3, 4) << std::endl;
            std::cout << B;

        }
    });





    menu.activateMenu();
}