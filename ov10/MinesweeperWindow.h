#pragma once
#include "AnimationWindow.h"
#include "Tile.h"

enum class MouseButton { left = FL_LEFT_MOUSE, right = FL_RIGHT_MOUSE }; 

// Minesweeper GUI
class MinesweeperWindow : public AnimationWindow
{
public:
	// storrelsen til hver tile
	static constexpr int cellSize = 30;
	MinesweeperWindow(int x, int y, int width, int height, int mines, const string& title);
private:
	const int width;		// Bredde i antall tiles
	const int height;		// Hoyde i antall tiles
	const int mines;		// Antall miner
	bool endGame = false;			
	int remainingFlags;
	vector<shared_ptr<Tile>> tiles; // Vektor som inneholder alle tiles

	// FLTK-widget paramaters
	const int boardOffsetX = width*cellSize;
	const int boardOffsetY = height*cellSize;
	static constexpr int dispH = 30;
	static constexpr int pad = 15;
	static constexpr int padX = 140;

	Fl_Output winScreen;
	static constexpr int winScreenWidth = 100;

	Fl_Output flagScreen;
	static constexpr int flagScreenWidth = 40;

	Fl_Button quitBtn;
	Fl_Button restartBtn;
	static constexpr int btnW = 60;

	


	// hoyde og bredde i piksler
	int Height() const { return height * cellSize; } 
	int Width() const { return width * cellSize; }


	// Sjekker at et punkt er paa brettet
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x< Width() && xy.y >= 0 && xy.y < Height(); }
	// Returnerer en tile gitt et punkt
	shared_ptr<Tile>& at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const shared_ptr<Tile>& at(Point xy) const { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

    //aapne og flagge rute
	void openTile(Point xy);
	void flagTile(Point xy);

	//#		Callbacks
	static void cb_click(Fl_Widget*, void* pw) { static_cast<MinesweeperWindow*>(pw)->click(); };
	void click();
	static void cb_quit(Fl_Widget*, void* pw) {static_cast<MinesweeperWindow*>(pw)->hide();};
	static void cb_restart(Fl_Widget*, void* pw) {static_cast<MinesweeperWindow*>(pw)->resetBoard();};

	//#		Game logic
	void checkWin();
	void checkLost(Point xy);
	void updateGame();
	
	//#		Utility
	// Returnerer en vektor med nabotilene rundt en tile, der hver tile representeres som et punkt
	vector<Point> adjacentPoints(Point xy) const;
	// tell miner basert paa en liste tiles
	int countMines(vector<Point> coords) const;
	// Marks mines with a given string
	void markAllMines(string mark);
	// Places a given amount of mines on the board
	void placeMines(int numMines);
	// Resets the board
	void resetBoard();
};
