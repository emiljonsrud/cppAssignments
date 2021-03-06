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
    void moveUp() {topLeftCorner = Point{topLeftCorner.x, topLeftCorner.y-blockSize};}
    void moveDown() {topLeftCorner = Point{topLeftCorner.x, topLeftCorner.y+blockSize};}
    void moveLeft() {topLeftCorner = Point{topLeftCorner.x-blockSize, topLeftCorner.y};}
    void moveRight() {topLeftCorner = Point{topLeftCorner.x+blockSize, topLeftCorner.y};}

    // Gets
    TetrominoType getBlock(int row, int column);
    int getMatrixSize() const {return matrixSize;}
    Point getPosition() const {return topLeftCorner;}
    
    //#     Div
    bool blockExist(int row, int column) const;

   
private: 
    int matrixSize;
    Point topLeftCorner;
    vector<vector<TetrominoType>> blockMatrix;
};  