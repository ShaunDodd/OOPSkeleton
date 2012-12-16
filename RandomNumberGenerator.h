// RandomNumberGenerator.h: interface for the RandomNumberGenerator class
//
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made & justification (if needed)
//---------------------------------------------------------------------
// 15.11.11   Pascale		
// 
//
//NOTE:  All member functions could be declared as const as there is no class attributes 
//       (i.e.,  RandomNumberGenerator instances do not have a state)
//---------------------------------------------------------------------

#if !defined(RandomNumberGeneratorH)
#define RandomNumberGeneratorH

#include <stdlib.h>	//for srand and rand routines
#include <cassert>	//for assert
#include <ctime>	//for time used in RandomNumberGenerator::seed routines
using namespace std;

class RandomNumberGenerator
{
	public:
		//constructors
		RandomNumberGenerator();
		//assessors
		int getRandomValue( int) const;
	private:
		//supporting functions
		void seed();
};
#endif // !defined(RandomNumberGeneratorH)
