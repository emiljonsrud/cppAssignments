#include "Matrix.h"

//      PRIVATE



//      PUBLIC

//      Con- and de-structors
Matrix::Matrix(int nRows, int nColumns)  : height{nRows}, width{nColumns} {
    assert(nRows > 0 && nColumns > 0);    
    //  Allocate storage for the rows (which will be an array of array pointers)
    //  this array is initially filled with nullpointers
    matrix = new double*[nRows];

    for (int i = 0; i < nRows; i++) {
        // Allocate the column array and fill it with zeros, then 
        // assign it to the i'th position of matrix (along row-axis)
        // double* column = 
        *(matrix + i) =  new double[nColumns]{0.0};
    }
    // matrix = rows;
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
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    // Spørsmål til studass:
    // Om jeg bruker delete[] **matrix, sletter jeg alle tabellene
    // inni matrix også?

    // Deallocate the rows pointing to columns
    // delete[] matrix;  <-- Denne fører til leak, hvorfor?
    delete[] matrix;
    matrix = nullptr;
    height = 0;
    width = 0;
}
Matrix::Matrix(const Matrix &rhs) : height{rhs.height}, width{rhs.width} {
    // Allocate memory for the new matrix
    this->matrix = new double*[rhs.getRows()];

    // Iterate through the rows of the matrix
    for(int i = 0; i < rhs.getRows(); i++) {

        // Allocate new memory for each column
        *(matrix + i) = new double[rhs.getColumns()]{};

        // Iterate through the values of the columns
        for (int j = 0; j < rhs.getColumns(); j++) {
            *(*(matrix + i) + j) = *(*(rhs.matrix + i) + j);
        }
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
Matrix Matrix::operator=(const Matrix &rhs) {
    // Swap funker ikke
    // Matrix C{3, 3};
    // Matrix D{3};
    // std::swap(C, D);


    // Intuiosjonen min sier at dette fører til memory leak, men 
    // programmet klager ikke. Er det en leak her?
    this->height = rhs.getRows();
    this->width = rhs.getColumns();

    // Allocate memory for the new matrix
    this->matrix = new double*[rhs.getRows()];

    // Iterate through the rows of the matrix
    for(int i = 0; i < rhs.getRows(); i++) {

        // Allocate new memory for each column
        *(matrix + i) = new double[rhs.getColumns()]{};

        // Iterate through the values of the columns
        for (int j = 0; j < rhs.getColumns(); j++) {
            *(*(matrix + i) + j) = *(*(rhs.matrix + i) + j);
        }
    }
    return *this;
}
Matrix Matrix::operator+=(const Matrix &rhs) {
    assert(this->height = rhs.height);
    assert(this->width = rhs.width);
    // Spm. til studass:    ^ hvorfor '.' her, men '->' på this
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            this->matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];            
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix &rhs) {
    assert(this->height = rhs.height);
    assert(this->width = rhs.width);
    
    Matrix tempMatrix{*this};
    return tempMatrix+=rhs;
}