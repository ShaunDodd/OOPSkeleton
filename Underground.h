// Underground.h: interface for the Underground class
//
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made & justification (if needed)
//---------------------------------------------------------------------
// 15.11.10   Pascale		Need to be amended for Assignment 1 [Q1 to 4 & 7]
//                          Declare class data and function members private where possible.
//                          Declare const instances, parameters and class functions (wherever possible).
//                          Create constructors with their initialisation list in same order as declaration list
//                          Place code in separate module
//                   		Check design and implementation of relationships to other classes
//                   		Follow UML design.
//							etc.
//---------------------------------------------------------------------
#if !defined(UndergroundH)
#define UndergroundH

#include <cassert>

#include "constants.h"

class Hole { 
	public:
		//constructors
		Hole();
		Hole( int x, int y);
		//assessors
		int getX() const;
		int getY() const;
		char getSymbol() const;
		bool isAtPosition( int x, int y);
	private:
		//data members
		char symbol_;
		int x_, y_;
};

class Underground {
public:
	Hole getHoleNo( int no) const;
	void setHoleNoAtPosition( int no, int x, int y);
	bool isValidHoleNumber( int n) const;
	Hole hole1_, hole2_, hole3_;
};

#endif // !defined(UndergroundH)
