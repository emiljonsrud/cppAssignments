#pragma once
#include "Graph.h"


enum class TetrominoType{J, L, T, S, Z, O, I, NONE};

class Tetromino {
public:
    static constexpr int blockSize {30};

    Tetromino(Point startingPoint, TetrominoType tetType);
    
    void rotateClockwise();
    void rotateCounterClockwise();


   
private: 
    int matrixSize;
    Point topLeftCorner;
    vector<vector<TetrominoType>> blockMatrix;
};  
