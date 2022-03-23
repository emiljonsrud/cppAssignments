#include "exersizeFunctions.h"

#include "Matrix.h"
#include "Dummy.h"

#include <iostream>
#include <limits>



void testCode() {
    // constexpr int tableSize {3};
    // int numTable[tableSize] = {2, 4, 6};
    // int* numTable = new int[tableSize]{1};

    // printArray(numTable, tableSize);

    // int nRows = 3;
    // int nCols = 4;
    // int** rows = new int*[nRows]{nullptr};
    // for (int i = 0; i < nCols; i++) {
    //     int* column = new int[nCols]{0};
    //     *(rows + i) = column;
    // }
    // *(*(rows + 1) + 3) = 1;
    // printMatrix(rows, nRows, nCols);
    // for (int i = 0; i < nRows; i++) {
    //     delete[] *(rows + i);        
    // }
    // printMatrix(rows, nRows, nCols);
    // // delete[] rows;
    // // std::cout << *(*(rows + 2) + 3) << std::endl;

    
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
    std::cout << "How many Fibonacci numbers do you wish?\n> " << std::endl;
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




//          Assignment 2 - Matrix
void testMatrix() {
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
            std::cout << B.get(3, 4);
            std::cout << B;
}

//          Assignment 3 - Dummy code
void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';

    *b.num = 3;
    *c.num = 5;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';
}

//          Assignment 4 - Matrix copy
void testMatrixCopy() {
    Matrix A{3,6};
    // std::cout << A;
    A.set(2, 2, 6.9);

    std::cout << "A" << A;
    Matrix B{A};
    // Matrix B{3, 5};
    std::cout << "B" << B;

    Matrix C = A;
    std::cout << "C" << C;
}

//          Assignment 5 - Operators
void testAddition() {
    // Create A
    Matrix A{2, 2};
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    // Create B
    Matrix B{2, 2};
    B.set(0, 0, 4);
    B.set(0, 1, 3);
    B.set(1, 0, 2);
    B.set(1, 1, 1);

    // Create C
    Matrix C{2, 2};
    C.set(0, 0, 1);
    C.set(0, 1, 3);
    C.set(1, 0, 1.5);
    C.set(1, 1, 2);
    
    // Print the matrices
    std::cout << "A:" << A << "B: " << B << "C: " << C << std::endl;

    // Do a calculation
    A += B + C;

    // Print the matrices after the calculation
    std::cout << "A:" << A << "B: " << B << "C: " << C << std::endl;
}