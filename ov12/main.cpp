#include "Tetromino.h"
#include "TetrisWindow.h"



int main()
{	
	//Random seed
	srand(unsigned(time(nullptr)));
	
    // Window constants
    static constexpr int dispHeight = 800;
    static constexpr int dispWidth = 500;
    static constexpr int dispXpos = 400;
    static constexpr int dispYpos = 100;
	TetrisWindow gameWindow(
		dispXpos,
		dispYpos,
		dispWidth,
		dispHeight
	);
	// gameWindow.activate();
	gameWindow.run();

	// return gui_main();
}
