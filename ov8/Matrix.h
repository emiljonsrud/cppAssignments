#pragma once

#include <iostream>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <utility>

class Matrix {
private:
    int height;
    int width;

    double** matrix;
public:
    // Con- and de-structors
    Matrix(int nRows, int nColumns);    //contructor
    explicit Matrix(int nRows);         //
    virtual ~Matrix();                  //destructor
    Matrix(const Matrix &rhs);

    //  Gets
    double get(int row, int col) const;
    int getRows() const {
        return height;
    }
    int getColumns() const {
        return width;
    }
    
    //  Sets
    void set(int row, int col, double value);

    //  Operators
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);

    double* operator[](int row);
    Matrix operator=(const Matrix &rhs);
    Matrix operator+=(const Matrix &rhs);

};
// template<class Matrix> void swap( Matrix& a, Matrix& b);

