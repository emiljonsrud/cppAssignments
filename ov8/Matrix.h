#pragma once

#include <iostream>

class Matrix {
private:
    int height;
    int width;

    double** matrix;
public:
    Matrix(int nRows, int nColumns);    //contructor
    explicit Matrix(int nRows);         
    virtual ~Matrix();                  //destructor

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
    double* operator[](int row);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);


};

