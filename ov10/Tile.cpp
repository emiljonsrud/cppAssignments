#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{{1, Color::blue},
								   {2, Color::red},
								   {3, Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow}};

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{{Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"}};

void Tile::open()
{
	// Check if the tile is open
	if(state == Cell::open) {return;}
	switch (state) {
	case Cell::open:
		return;
	case Cell::flagged:
		return;
	case Cell::closed:
		// Set the btn as bressed (open cell) and update state
		this->set();
		state = Cell::open;

		// If the cell is a mine label is set to a  red X
		if(isMine) {
			set_label_color(Color::red);
			set_label("X");
		}
	default:
		break;
	}
}

void Tile::flag()
{
	switch (state) {
		case Cell::flagged:
			state = Cell::closed;
			break;
		case Cell::closed:
			state = Cell::flagged;
			break;
		default:
			break;	
	}
	set_label(cellToSymbol.at(state));
}

//		Sets
void Tile::setAdjMines(const int n) {

	// Trow invalid argument if n is not in [1, 8]
	if(1 <= n && n <= 8) {
		// Set relevant label and color
		set_label_color(minesToColor.at(n));
		set_label(std::to_string(n));
	} else {
		throw std::invalid_argument("Invalid amout of mines: " + std::to_string(n));
	}
}