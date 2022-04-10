#pragma once
#include "Graph.h"


enum class TetrominoType{J, L, T, S, Z, O, I, NONE};

class Tetromino {
public:
    static constexpr int blockSize {30};

    Tetromino(Point startingPoint, TetrominoType tetType);
    Tetromino() : topLeftCorner({0, 0}), matrixSize{0} {}

    //#     Movement
    void rotateClockwise();
    void rotateCounterClockwise();
    void moveDown() {topLeftCorner = Point{topLeftCorner.x, topLeftCorner.y+1};}
    void moveLeft() {topLeftCorner = Point{topLeftCorner.x-1, topLeftCorner.y};}
    void moveRight() {topLeftCorner = Point{topLeftCorner.x+1, topLeftCorner.y};}

    //#     Div
    bool blockExist(int row, int column) const;
    TetrominoType getBlock(int row, int column);
   
private: 
    int matrixSize;
    Point topLeftCorner;
    vector<vector<TetrominoType>> blockMatrix;
};  
