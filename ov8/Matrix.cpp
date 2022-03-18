#include "Matrix.h"

#include <assert.h>
#include <iostream>
#include <iomanip>
//      PRIVATE



//      PUBLIC
Matrix::Matrix(int nRows, int nColumns)  : height{nRows}, width{nColumns} {
    assert(nRows > 0 && nColumns > 0);
    
    //  Allocate storage for the rows (which will be an array of array pointers)
    //  this array is initially filled with nullpointers
    double** rows = new double*[nRows]{nullptr};
    
    for (int i = 0; i < nRows; i++) {
        // Allocate the column array and fill it with zeros, then 
        // assign it to the i'th position of matrix (along row-axis)
        double* column = new double[nColumns]{0.0};
        *(rows + i) =  column;
    }
    matrix = rows;
}
Matrix::Matrix(int nRows) : Matrix{nRows, nRows} {
    for (int i = 0; i < nRows; i++) {
        double one = 1.0;
        *(*(matrix + i) + i) = one;
    }
}
Matrix::~Matrix() {
    for (int i = 0; i < height; i++) {
        // Deallocate all the columns in the matrix
        delete[] *(matrix + i);
        *(matrix + i) = nullptr;
    }
    // Spørsmål til studass:
    // Om jeg bruker delete[] **matrix, sletter jeg alle tabellene
    // inni matrix også?

    // Deallocate the rows pointing to columns
    // delete[] matrix;  <-- Denne fører til leak, hvorfor?
}


//      Operators
std::ostream& operator<<(std::ostream& os, Matrix M) {
    os << '\n';
    for (int i = 0; i < M.getRows(); i++) {
        for (int j = 0; j< M.getColumns(); j++) {
            os << std::setw(4) << std::setfill(' ');
            os << M[i][j];
        }
        os << std::endl;
    }
    return os;
}