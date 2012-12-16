// Cat.h: interface for the Cat class 
//
//////////////////////////////////////////////////////////////////////

#if !defined(CatH)
#define CatH

#include "constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Cat {
	public:
		char symbol_;
		Mouse* p_mouse_;
		RandomNumberGenerator rng_;
		Cat();
		~Cat();
		bool isAtPosition( int x, int y);  
		bool hasCaughtMouse() ;
		void spotMouse( Mouse* p_mouse);
		void chaseMouse();
		void updatePosition( int dx, int dy);
		void positionAtRandom();
		int x_, y_;
};

#endif // !defined(CatH)
