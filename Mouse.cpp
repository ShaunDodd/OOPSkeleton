// Mouse.cpp: implementation of the Mouse class
//
//////////////////////////////////////////////////////////////////////

#include "Mouse.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mouse::Mouse(): symbol_( MOUSE), x_(0), y_(0),    
                alive_( true), escaped_( false), 
				mouseDX_(0), mouseDY_(0) {
	positionInMiddleOfGrid(); 
}

//////////////////////////////////////////////////////////////////////
// Public functions
//////////////////////////////////////////////////////////////////////

int Mouse::getX() const {
	return x_;
}
int Mouse::getY() const {
	return y_;
}
char Mouse::getSymbol() const {
	return symbol_;
}
bool Mouse::isAtPosition( int x, int y) const {
	return (x_ == x) && (y_ == y);
}
bool Mouse::isAlive() const {
	return alive_;
}
bool Mouse::hasEscaped() const {
	return escaped_;
}
bool Mouse::hasReachedAHole( Underground hs) const {
	for ( int hNo(1); hNo <= 3; ++hNo)
		if ( isAtPosition( hs.getHoleNo(hNo).getX(), hs.getHoleNo(hNo).getY()))
			return true;
	return false;
}
void Mouse::die() {
	alive_ = false;
}
void Mouse::escapeIntoHole() 
{
	escaped_ = true;
}
void Mouse::scamper( char k) { //move mouse in required direction
  //pre: Key is an arrow representing the direction in which the mouse moves
	//find direction indicated by key
	switch( k)               //...depending on the selected key...
	{
		case LEFT:           //when LEFT arrow pressed...
			mouseDX_ = -1;    //decrease the X coordinate
			mouseDY_ = 0;
			break;
		case RIGHT:          //when RIGHT arrow pressed...
			mouseDX_ = +1;    //increase the X coordinate
			mouseDY_ = 0;
			break;
		case UP:             //when UP arrow pressed...
			mouseDX_ = 0;
			mouseDY_ = -1;    //decrease the Y coordinate
			break;
		case DOWN:           //when DOWN arrow pressed...
			mouseDX_ = 0;
			mouseDY_ = +1;    //increase the Y coordinate
			break;
	}
	//update mouse coordinates if move is possible
	if ( ((x_ + mouseDX_) >= 1) && ((x_ + mouseDX_) <= SIZE) &&
		 ((y_ + mouseDY_) >= 1) && ((y_ + mouseDY_) <= SIZE) )
	{
		updatePosition( mouseDX_, mouseDY_);		//go in that direction
	}
}

//////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////

void Mouse::updatePosition( int dx, int dy) {
	x_ += dx;
	y_ += dy;
}
void Mouse::positionInMiddleOfGrid()
{
	x_ = SIZE /2;
	y_ = SIZE /2;
}
