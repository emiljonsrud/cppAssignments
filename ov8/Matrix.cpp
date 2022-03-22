#include "Matrix.h"

#include <assert.h>
#include <iostream>
#include <iomanip>
//      PRIVATE



//      PUBLIC

//      Con- and de-structors
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
    std::cout << "Deleting matrix" << std::endl;
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
Matrix::Matrix(const Matrix &rhs) {
    // int this_rows = this->getRows();
    // int this_cols = this->getColumns();

    // int* tempWidth = new int{0};
    // int* tempHeight = new int{0};
    // *tempWidth = rhs.getColumns();
    // *tempHeight = rhs.getRows();

    this->width = rhs.getColumns(); // Dette gir: free(): double free detected in tcache 2
    this->height = rhs.getRows();   // vet ikke hvorfor
    // this->width = 3;
    // this->height = 2;

    // delete tempWidth;
    // delete tempHeight;

    

    // Allocate memory for the new matrix
    this->matrix = new double*[rhs.getRows()]{nullptr};
    for(int i = 0; i < rhs.getRows(); i++) {

        // Allocate new memory for each column
        // double* column = new double[rhs.getColumns()]{};
        // column = *(rhs.matrix + i);
        // *(*rows + i) =  column;

        *(matrix + i) = new double[rhs.getColumns()]{};
        *(matrix + i) = *(rhs.matrix + i);
    }
}


//      Get
double Matrix::get(int row, int col) const {
    return matrix[row][col];
}
//      Set
void Matrix::set(int row, int col, double value) {
    // *(*(matrix + col) + row) = value;
    double* ptr = &matrix[row][col];
    *ptr = value;
}


//      Operators
std::ostream& operator<<(std::ostream& os, const Matrix& M) {
    //  Denne kaller på dekontruktøren??? Hvorfor det
    //  Det løste seg med en '&', hvorfor det
    os << '\n';
    for (int i = 0; i < M.getRows(); i++) {
        for (int j = 0; j< M.getColumns(); j++) {
            os << std::setw(4) << std::setfill(' ');
            os << M.get(i, j);
        }
        os << std::endl;
    }
    return os;
}
double* Matrix::operator[](int row) {
    assert(row <= height);
    return *(matrix + row);
}
