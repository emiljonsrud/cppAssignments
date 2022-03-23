#include "Menu.h"

#include "exersizeFunctions.h"
#include "Matrix.h"
#include "Dummy.h"

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

    //  Exersize 3
    menu.addItem(MenuItem{
        "Dummy",
        []() {
            dummyTest();
        }
    });
    /*
        The program crashed because a,b and c are pointing to the
        same memory position. This causes problems when 
        each of them are to destructed.
    */

   //Exersize 4
   menu.addItem(MenuItem{
       "Matrix copy",
       []() {
           testMatrixCopy();
           std::cout << "heihei" << std::endl;
       }
   });

   //   Exersize 5
   menu.addItem(MenuItem{
       "Matrix addition",
       []() {
           testAddition();
       }
   });




    menu.activateMenu();
}