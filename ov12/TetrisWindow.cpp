#include "TetrisWindow.h"

const map<TetrominoType, int> tetromineToColor {
    {TetrominoType::J,  4}, // Blue
    {TetrominoType::L, 91}, // Orange
    {TetrominoType::T, 13}, // Dark magenta
    {TetrominoType::S,  2}, // Green
    {TetrominoType::Z,  1}, // Red
    {TetrominoType::O,  3}, // Yellow
    {TetrominoType::I,  6}, // Cyan
    {TetrominoType::NONE, 7}// White
};


// Konstructor
TetrisWindow::TetrisWindow(int dispXpos, int dispYpos, int dispWidth, int dispHeight) 
: AnimationWindow{
    dispXpos,
    dispYpos,
    dispWidth,
    dispHeight,
    "Tetris"
} {


    //  Fill the grid matrix  
    for(int i = 0; i < gridHeight; i++) {
        
        // Create a new row, and fill it with NONE
        vector<TetrominoType> row;
        for(int j = 0; j < gridWidth; j++) {
            row.push_back(TetrominoType::NONE);            
        }
        // Add the row to the gridmatrix
        gridMatrix.push_back(row);
    }
  
  generateRandomTetromino();
}



void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            //moveTetrominoDown()
           
        }
        drawCurrentTetromino(*this);
     

        next_frame();
    }
}


void TetrisWindow::handleInput() {

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);

    
    if(currentZKeyState && !lastZKeyState) {
        cout << "Hello from z\n";
    }

    if(currentUpKeyState && !lastUpKeyState) {
        cout << "Hello from up\n";
    }


    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
}

void TetrisWindow::generateRandomTetromino() {
    // Create a random tetromino type
    TetrominoType randomTetType = static_cast<TetrominoType>( rand()%7 ); //there are 7 types
    Point startPos{
        (gridWidth*blockSize)/2,
        0
    };
    currentTetromino = Tetromino(startPos, randomTetType);
}

void TetrisWindow::drawCurrentTetromino(TetrisWindow& win) {
    for(int i = 0; i < currentTetromino.getMatrixSize(); i++) {
        for(int j = 0; j < currentTetromino.getMatrixSize(); j++) {
            // Define the top-left point of the current block
            Point p {
                currentTetromino.getPosition().x + blockSize*i,
                currentTetromino.getPosition().y + blockSize*j
            };
            // Find the current tet-type
            TetrominoType currentTet = currentTetromino.getBlock(i, j);
            win.draw_rectangle(p, blockSize, blockSize, tetromineToColor.at(currentTet));            
        }
    }
} 
