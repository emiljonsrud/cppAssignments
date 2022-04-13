#include "Tetromino.h"
    
const map<TetrominoType, vector<vector<int>>> initialMatrixMap {
{
    TetrominoType::J,
    {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
    }
}, { 
    TetrominoType::L, 
    {
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
    }
}, {
    TetrominoType::T,
    {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 0}
    }
}, {
    TetrominoType::S,
    {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 0}
    }
}, {
    TetrominoType::Z,
    {
        {0, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
    }
}, {
    TetrominoType::O,
    {
        {1, 1},
        {1, 1}
    }
}, {
    TetrominoType::I, 
    {
    //Denne er representert som en 6x6 matrise for å få en bedre rotasjonsfunksjonalitet
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
    }
}
};

Tetromino::Tetromino(Point startingPoint, TetrominoType tetType) : 
topLeftCorner{startingPoint},
matrixSize{static_cast<int>(initialMatrixMap.at(tetType).size())}
{
    for(int i = 0; i < matrixSize; i++) {
        vector<TetrominoType> row;
        for (int j = 0; j < matrixSize; j++) {
            if(initialMatrixMap.at(tetType).at(i).at(j)) {
                row.push_back(tetType);
            } else {row.push_back(TetrominoType::NONE);}
        }
        blockMatrix.push_back(row);
    }
}



//#     MOVEMENT
void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}
void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}


//#     Gets
TetrominoType Tetromino::getBlock(int row, int column) {
    if(blockExist(row, column)) {
        return blockMatrix.at(row).at(column);
    } else {return TetrominoType::NONE;}
    
}

//#     DIV
bool Tetromino::blockExist(int row, int column) const {    
    // First check the bounds
    if(row >= matrixSize || column >= matrixSize) {return false;}
    else if(blockMatrix.at(row).at(column) == TetrominoType::NONE) {return false;}
    else{return true;}
}
