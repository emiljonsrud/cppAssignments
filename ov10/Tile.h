#pragma once
#include "GUI.h"


// De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged }; 

class Tile : public Fl_Button
{
	Cell state = Cell::closed;
	
	void set_label(string s) { this->copy_label(s.c_str());}
	void set_label_color(Color c) {this->labelcolor(c.as_int());}

	//	Member variables
	bool isMine = false;

public:
	Tile(Point pos, int size) 
		 :Fl_Button(pos.x, pos.y, size, size, "") {};

	void open();
	void flag();
	

	//	Gets
	Cell getState() const { return state; };
	bool getIsMine(){return isMine;}
	
	//	Sets
	void setIsMine(bool m){isMine = m;}
	void setAdjMines(const int n);

};
