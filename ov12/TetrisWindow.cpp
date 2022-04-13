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
    const unsigned int framesPerTetronimoMove = 40;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            moveTetrominoDown();
           
        }
        drawCurrentTetromino(*this);
        handleInput();
        
        drawGridMatrix(*this);
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

    if(hasCrashed()) {correctAttemptedMove(5);}
    
    
    
    if(currentBKeyState && !lastBKeyState) {
        // cout << "Pressed B" << endl;
        cout << to_string(hasCrashed()) << endl;
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

//#     DRAW
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
void TetrisWindow::drawGridMatrix(TetrisWindow& win) {
    for(int i = 0; i < gridHeight; i++) {
        for(int j = 0; j < gridWidth; j++) {
            if(gridMatrix.at(i).at(j) != TetrominoType::NONE) {
                win.draw_rectangle(
                    Point{j*blockSize, i*blockSize},
                    blockSize, blockSize,
                    tetromineToColor.at(gridMatrix.at(i).at(j))
                );
            }
        }
    }
}



// Game logic
void TetrisWindow::fastenTetromino() {
    // Find the relative index postion
    int gridI = currentTetromino.getPosition().y / blockSize;
    int gridJ = currentTetromino.getPosition().x / blockSize;

    
    for(int i = gridI; i - gridI < currentTetromino.getMatrixSize(); i++) {
        for(int j = gridJ; j - gridJ < currentTetromino.getMatrixSize(); j++) {
            int tetI = i-gridI;
            int tetJ = j-gridJ;
            
            if(currentTetromino.blockExist(tetJ, tetI)) {
                gridMatrix.at(i).at(j) = currentTetromino.getBlock(tetI, tetJ);
            }
        }
    }

}

bool TetrisWindow::hasCrashed() {

    // Find the relative index postion
    int gridOffsetI = currentTetromino.getPosition().y / blockSize;
    int gridOffsetJ = currentTetromino.getPosition().x / blockSize;

    // Iterate though all the blocks in the Tetromino matrix
    for(int gridI = gridOffsetI; gridI - gridOffsetI < currentTetromino.getMatrixSize(); gridI++) {
        for(int gridJ = gridOffsetJ; gridJ - gridOffsetJ < currentTetromino.getMatrixSize(); gridJ++) {
            int tetI = gridI - gridOffsetI;
            int tetJ = gridJ - gridOffsetJ;
            
            // bool isBlock = currentTetromino.blockExist(tetI, tetJ)

            // We are only interested in this coordinate if a tetromino block is present
            if(currentTetromino.blockExist(tetJ, tetI)) {
                // Check if the block has crashed into the border
                if(gridJ >= gridWidth or gridJ < 0) {return true;}
                // Check if the block has crashed into the bottom
                if(gridI >= gridHeight) {return true;}

                // Check if the block has crashed into another tetromino
                if(gridMatrix.at(gridI).at(gridJ) != TetrominoType::NONE) {return true;}
            }
        }
    }
    // If none of the blocks have colided, the tetromino has not crashed
    return false;  
}

void TetrisWindow::correctAttemptedMove(int maxIter) {
    // Set a hard-cap for maxIter, to avoid infinate runtime
    // if(maxIter > 10) {return;}

    // Start by attempting to move the tetromino right
    for(int i = 0; i < maxIter; i++) {
        currentTetromino.moveRight();
        if(!hasCrashed()) {
            cout << "Corrected " << to_string(i) << "steps to the right." << endl;
            return;
        }
    }
    
    
    // If this fails, attempt twice as many left moves
    // as the tetromino is to the right
    for(int i = -maxIter; i < maxIter; i++) {
        currentTetromino.moveLeft();
        if(!hasCrashed()) {
            cout << "Corrected " << to_string(i) << "steps to the left." << endl;
            return;
        }
    }

    // Move the tetromino back to original postition
    for(int i = -maxIter; i != 0; i++) {
        currentTetromino.moveRight();
    }
    
    // Finally attempt to move up
    for(int i = 0; i < maxIter; i++) {
        currentTetromino.moveUp();
        if(!hasCrashed()){
            cout << "Corrected " << to_string(i) << "steps to upwards." << endl;
            return;
        };
    }
    
    // If the tetromino still has not been correcte, the 
    // function is called again recursivley, with one more 
    // allowed iteration
    // correctAttemptedMove(maxIter++);
}
