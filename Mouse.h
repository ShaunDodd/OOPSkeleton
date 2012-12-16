// Mouse.h: interface for the Mouse class
//
//////////////////////////////////////////////////////////////////////

#if !defined(MouseH)
#define MouseH

#include "constants.h"
#include "Underground.h"

class Mouse {
	public:
		//constructor
		Mouse::Mouse();
		//assessors
		int getX() const;
		int getY() const;
		char getSymbol() const;
		bool isAtPosition( int x, int y) const;
		bool isAlive() const;
		bool hasEscaped() const;
		bool hasReachedAHole( Underground hs) const;
		//mutators
		void die();
		void escapeIntoHole();
		void scamper( char k);
		//data members
		char symbol_;
	private:
		//data members
		int  x_, y_;
		bool alive_;
		bool escaped_;
		int mouseDX_;
		int mouseDY_;
		//supporting functions
		void positionInMiddleOfGrid();
		void updatePosition( int dx, int dy);
};

#endif // !defined(MouseH)
