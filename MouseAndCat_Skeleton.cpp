//--------------------------------
//include standard libraries
#include <iostream>		//for output and input: cout <<
#include <conio.h>		//for _getch()
#include <string>		//for string
#include <sstream>		//for streamstring

using namespace std;

//include class modules
#include "Mouse.h"
#include "Cat.h"
#include "Underground.h"
#include "Interface.h"

class MouseAndCatGame
{
	public:
		Mouse  mouse_;
		Cat cat_;
		Underground underground_;
		Interface* p_ui;

		int key_;
		void setUp( Interface* pui);
		void run();
		string prepareGrid();
		bool isArrowKeyCode( int keycode);
		void applyRules();
		int findHoleNumberAtPosition( int x, int y);
		bool hasEnded( char key);
		string prepareEndMessage();
};

void MouseAndCatGame::setUp( Interface* pui) {
	//prepare game
	//set up the holes
	underground_.setHoleNoAtPosition( 1,  4,  3);
	underground_.setHoleNoAtPosition( 2, 15, 10);
	underground_.setHoleNoAtPosition( 3,  7, 15);
	//mouse state already set up in its contructor
	//set up cat
	cat_.spotMouse( &mouse_);
	p_ui = pui;
}
void MouseAndCatGame::run() {
	p_ui->drawGridOnScreen( prepareGrid());
	key_ = p_ui->getKeyPressFromUser();
	while ( ! hasEnded( key_))
	{
		if ( isArrowKeyCode( key_))
		{
			mouse_.scamper( key_);
			cat_.chaseMouse();
			p_ui->drawGridOnScreen( prepareGrid());
			applyRules();
		}
		key_ = p_ui->getKeyPressFromUser();
	}
	p_ui->showResultsOnScreen( prepareEndMessage());
}
string MouseAndCatGame::prepareGrid(){
	//prepare a string that holds the grid information
	ostringstream os;
	for ( int row( 1); row <= SIZE; ++row)	//for each row (vertically)
	{
		for ( int col( 1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			if (( row == cat_.y_) && (col == cat_.x_))
				os << cat_.symbol_;	//show cat
			else
				if (( row == mouse_.getY()) && (col == mouse_.getX()))
					os << mouse_.getSymbol();	//show mouse
				else
				{
					int holeNo( findHoleNumberAtPosition( col, row));
					if (  holeNo != 0)
						os << underground_.getHoleNo( holeNo).getSymbol();	//show hole
					else
						os << FREECELL;	//show free grid cell
				}
		} //end of col-loop
		os << endl;
	} //end of row-loop
	return os.str();
} //end prepareGrid

bool MouseAndCatGame::isArrowKeyCode( int keycode) {
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}
int MouseAndCatGame::findHoleNumberAtPosition( int x, int y) {
	for ( int hNo(1); hNo <= 3; ++hNo)
		if ( underground_.getHoleNo(hNo).isAtPosition( x, y))
			return hNo;		//number of the hole
	return 0;				//not a hole
}
void MouseAndCatGame::applyRules() {
	if ( cat_.hasCaughtMouse())
		mouse_.die();
	else
		if ( mouse_.hasReachedAHole( underground_))
			mouse_.escapeIntoHole();
}
bool MouseAndCatGame::hasEnded( char key) {
	return (( key == 'Q') || ( ! mouse_.isAlive()) || ( mouse_.hasEscaped()));
}
string MouseAndCatGame::prepareEndMessage() {
	ostringstream os;
	if ( mouse_.hasEscaped())
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";
	else
		if ( !mouse_.isAlive())
			os << "\n\nEND OF GAME: THE CAT ATE THE MOUSE!";
		else
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
	return os.str();
}

//using OO approach
//---------------------------------
int main()
{
	Interface ui;
	MouseAndCatGame game;

	game.setUp( &ui);
	game.run();

	system( "PAUSE");
	return 0;
}