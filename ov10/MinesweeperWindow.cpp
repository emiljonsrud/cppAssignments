#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}, remainingFlags{mines},
	winScreen(
		boardOffsetX - winScreenWidth,
		boardOffsetY + 2*pad + dispH,
		winScreenWidth,
		dispH
	),
	flagScreen(
		boardOffsetX - flagScreenWidth,
		boardOffsetY + pad,
		flagScreenWidth,
		dispH,
		"Remaining mines"
	),
	quitBtn(
		boardOffsetX - btnW,   // X-pos
		boardOffsetY + 3*pad + 2*dispH,	// Y-pos
		btnW,           // Button width
		dispH,           // Button height
		"Quit"
	),
	restartBtn(
		boardOffsetX - btnW,   // X-pos
		boardOffsetY + 4*pad + 3*dispH,	// Y-pos
		btnW,           // Button width
		dispH,           // Button height
		"Restart"
	)
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->callback(cb_click, this);
			add(tiles.back().get());
		}
	}

	// Place mines at random positions
	placeMines(mines);
	
	// Add output screens
	add(winScreen); 
	add(flagScreen);

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());

	// Update the game with values
	updateGame();
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	Tile* cell = at(xy).get();

	// Open the cell if it is closed
	if(cell->getState() == Cell::closed && !endGame) {
		cell->open();
	} else {
		return;
	}

	// Check if the cell is a bomb
	if(!cell->getIsMine()) {
		// Find the number of adjacent tiles that are mines
		std::vector<Point> adjPoints = adjacentPoints(xy);
		int numMines = countMines(adjPoints);

		// Set number of mines on the cell
		if(numMines > 0) {
			cell->setAdjMines(numMines);
		} else if (numMines == 0) {
			// Iterate the adjacent tiles
			for(Point p : adjPoints) {
				// Recursivly open tiles with no neighboring mines
				openTile(p);
			}
		}
	}
	checkLost(xy);
}

void MinesweeperWindow::flagTile(Point xy) {
	
	// Flagg/deflag the tile
	at(xy).get()->flag();

	// Check the updated state of the cell
	switch(at(xy).get()->getState()) {
	case Cell::closed:
		remainingFlags++;
		break;
	case Cell::flagged:
		if (remainingFlags == 0) {break;}
		else {remainingFlags--;}
		break;
	default:
		break;
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	// Abort the click if the game if ended
	if(endGame) {return;}
	
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}
	updateGame();
}



int MinesweeperWindow::countMines(vector<Point> points) const {

	// The number of cells that are mines
	int numMines{0};

	// Iterate through the cells
	for(Point p : points) {
		if(at(p).get()->getIsMine()) {
			numMines++;
		}
	}
	return numMines;
}




//#		Game logic

void MinesweeperWindow::checkLost(Point xy) {
	
	// If the cell is a bomb, the player has lost
	if(at(xy).get()->getIsMine()) {
		std::cout << "Player lost" << std::endl;
		this->winScreen.value("You lost");
		endGame = true;
		markAllMines("X");
		std::cout << "Player has lost" << std::endl;
	}

}

void MinesweeperWindow::checkWin() {
	// Find the number of remaining cells
	int remainingCells {0};
	for(shared_ptr<Tile> tile : tiles) {
		switch(tile.get()->getState()) {
			case Cell::closed:
				remainingCells++;
				break;
			case Cell::flagged:
				remainingCells++;
				break;
			default:
				break;
		}
	}	
	if(remainingCells == mines && !endGame) {
		winScreen.value("You won!");
		std::cout << "Player won" << std::endl;
		endGame = true;
		markAllMines("@<");
	}
}

void MinesweeperWindow::updateGame() {
	checkWin();
	if (endGame) {
		// Add end of game buttons
		add(quitBtn);
		quitBtn.callback(cb_quit, this);

		add(restartBtn);
		restartBtn.callback(cb_restart, this);

		// Show buttons if they are hidden
		restartBtn.show();
		quitBtn.show();
		
		return;
	}

	flagScreen.value(std::to_string(remainingFlags).c_str());

	if (remainingFlags > 0) {
		winScreen.value("");
	} else {
		winScreen.value("No more flags");
	}
}



//##		Utility
void MinesweeperWindow::markAllMines(string mark) {
	for (std::shared_ptr<Tile> tile : tiles) {
		if(tile.get()->getIsMine()) {
			tile.get()->markTile(mark);
		}
	}
}
void MinesweeperWindow::placeMines(int numMines) {
	int remainingMines = numMines;
	while(remainingMines > 0) {
		// Select a random cell
		int randPos = std::rand()%(height*width);
		
		// Place a mine if the cell does not have a mine
		if (!tiles.at(randPos).get()->getIsMine()) {
			tiles.at(randPos).get()->setIsMine(true);
			remainingMines--;
		}
	}
}
void MinesweeperWindow::resetBoard() {
	// Iterate through all the tiles and reset them
	for (std::shared_ptr<Tile> tile : tiles) {
		tile.get()->value(0);
		tile.get()->setIsMine(false);
		tile.get()->setState(Cell::closed);
		tile.get()->markTile("");
	}
	// Place mines on random tiles
	placeMines(mines);

	// Update endGame
	this->endGame = false;

	// Hide end game buttons
	this->quitBtn.hide();
	this->restartBtn.hide();

	updateGame();
}