#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "GUI.h"
#include <atomic>

class TetrisWindow : public AnimationWindow {

public:
    TetrisWindow();
    void run();
    


private:

    void handleInput();

};
