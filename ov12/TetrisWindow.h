#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "GUI.h"
#include <atomic>

class TetrisWindow : public AnimationWindow {

public:
    TetrisWindow(int dispXpos, int dispYpos, int dispWidth, int dispHeight);
    void run();
    


private:
    // Some Game constants
    static constexpr int gridWidth = 10;
    static constexpr int gridHeight = 60;
    static constexpr int blockSize = 30;




    // The game grid
    vector<vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;
    
    // Generate random Tetrino
    void handleInput();
    void generateRandomTetromino();

    // Draw
    void drawCurrentTetromino(TetrisWindow& win);

    void moveTetrominoDown() {currentTetromino.moveDown();}

    // Game logic
    // THis function moves the blocks from the current Tetromino
    // to the gridMatrix
    void fastenTetromino();

};
