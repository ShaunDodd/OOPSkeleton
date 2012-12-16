// Interface.h: interface for the Interface class
//
//////////////////////////////////////////////////////////////////////
#if !defined(InterfaceH)
#define InterfaceH

//include standard libraries
#include <iostream>		//for output and input: cout <<
#include <conio.h>		//for _getch()
#include <string>		//for string

using namespace std;


class Interface {
	public:
		int getKeyPressFromUser() const;
		void drawGridOnScreen( const string& gridData) const ;
		void showResultsOnScreen( const string& message) const ;
};

#endif // !defined(InterfaceH)