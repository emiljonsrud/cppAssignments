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
            moveTetrominoDown();
           
        }
        drawCurrentTetromino(*this);
        handleInput();

        next_frame();
    }
}


void TetrisWindow::handleInput() {

    // Movement keys
    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;
    static bool lastDownKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;

    // Auilararty keys
    static bool lastBKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);

    bool currentBKeyState = is_key_down(KeyboardKey::B);
    
    if(currentZKeyState && !lastZKeyState) {
        currentTetromino.rotateCounterClockwise();
    }

    if(currentUpKeyState && !lastUpKeyState) {currentTetromino.rotateClockwise();}
    if(currentDownKeyState && !lastDownKeyState) {currentTetromino.moveDown();}
    if(currentLeftKeyState && !lastLeftKeyState) {currentTetromino.moveLeft();}
    if(currentRightKeyState && !lastRightKeyState) {currentTetromino.moveRight();}
    
    if(currentBKeyState && !lastBKeyState) {
        cout << "Pressed B" << endl;
        fastenTetromino();
    }


    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
    lastDownKeyState = currentDownKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;

    lastBKeyState = currentBKeyState;
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
            if(currentTet != TetrominoType::NONE) {
                win.draw_rectangle(p, blockSize, blockSize, tetromineToColor.at(currentTet));
            }
        }
    }
} 


// Game logic
void TetrisWindow::fastenTetromino() {
    // Find the relative index postion
    int gridI = currentTetromino.getPosition().x / blockSize;
    int gridJ = currentTetromino.getPosition().y / blockSize;

    
    for(int i = gridI; i - gridI < currentTetromino.getMatrixSize(); i++) {
        for(int j = gridJ; j - gridJ < currentTetromino.getMatrixSize(); j++) {
            int tetI = i-gridI;
            int tetJ = j-gridJ;
            
            if(currentTetromino.getBlock(tetI, tetJ) != TetrominoType::NONE) {
                gridMatrix.at(j).at(i) = currentTetromino.getBlock(tetI, tetJ);
            }
        }
    }
}

