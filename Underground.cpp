// Underground.cpp: implementation of the Underground class
//
//////////////////////////////////////////////////////////////////////

#include "Underground.h"

//////////////////////////////////////////////////////////////////////

Hole::Hole()
{}
Hole::Hole( int x, int y) {
	symbol_ = HOLE;	
	x_ = x;
	y_ = y;
}
int Hole::getX() const {
	return x_; 
}
int Hole::getY() const {
	return y_;
}
char Hole::getSymbol() const {
	return symbol_;
}
bool Hole::isAtPosition( int x, int y) {
	return (x_ == x) && (y_ == y);
}
Hole Underground::getHoleNo( int no) const {
	assert ( isValidHoleNumber( no));	//pre: valid hole number
	switch (no) {
		case 1: return hole1_; break;
		case 2: return hole2_; break;
		case 3: return hole3_; break;
	}
}
void Underground::setHoleNoAtPosition( int no, int x, int y) {
	assert ( isValidHoleNumber( no));	//pre: valid hole number
	Hole h( x, y);
	switch (no) {
		case 1: hole1_ = h; break;
		case 2: hole2_ = h; break;
		case 3: hole3_ = h; break;
	}
}
bool Underground::isValidHoleNumber( int no) const {
	return ( no >= 1) && (no <= 3);	
}
