#pragma once

class Matrix {
private:
    int height;
    int width;

    double** matrix = new double*[0];
public:
    Matrix(int nRows, int nColumns);    //contructor
    explicit Matrix(int nRows);         
    virtual ~Matrix();                  //destructor

    //  Gets
    double get(int row, int col) const {
        return *(*(matrix + col) + row);
    }
    int getRows() const {
        return height;
    }
    int getColumns() const {
        return width;
    }

    //  Sets
    void set(int row, int col, double value) {
        *(*(matrix + col) + row) = value;
    }

    //  Operators
    double* operator[](const int row) {
    return *(matrix + row);
    }
    friend std::ostream& operator<<(std::ostream& os, Matrix M);


};

