#include "exersizeFunctions.h"

#include <iostream>


void testCode() {
    constexpr int tableSize {3};
    int numTable[tableSize] = {2, 4, 6};

    printArray(numTable, tableSize);

}


//          Assignment 1 - Fibonacci numbers

void fillInFibonacciNumbers(int* result, int length) {
    //  Define the inital condition
    *result = 0;
    *(result + 1) = 1;

    //  Calcultate the fib.-numbers from the initial condition    
    for (int i = 2; i < length; i++) {
        //  Make a pointer to the current iteration in result
        int* i_ptr = result + i; 
        
        //  Get the relevant fib.-values
        int n2 = *(i_ptr - 2);  // The n-2 value
        int n1 = *(i_ptr - 1);  // The n-1 value

        *(i_ptr) = n2 + n1; // Assing the calculated fib-number to i_ptr
    }
}
void printArray(int* arr, int length) {
    std::cout << "[";
    for (int i = 0; i < length; i++) {
        std::cout << *(arr + i);
        if (i < length - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
void createFibonacci() {
    //  Ask user how many Fib-numbers they want
    std::cout << "How many Fibonacci numbers do you wish?" << std::endl;
    int inpLength{0};
    while(!(std::cin >> inpLength) || inpLength < 1) {
        std::cout << "Please insert a positive integer.\n> ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };
    //  Spørsmpl til studass: hvordan kan jeg få en const variabel 
    //  fra en std::cin?
    const int fibLenth = inpLength;
    
    //  Allocate memory for the array
    int* fibTable = new int[fibLenth]{0}; // All entries 0

    //  Fill the array with the fib.-numbers and print it
    fillInFibonacciNumbers(fibTable, fibLenth);
    printArray(fibTable, fibLenth);

    //  Deallocate the array
    delete[] fibTable;
}




//          Assignment 2

