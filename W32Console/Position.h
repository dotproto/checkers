#ifndef __POSITION_H_INLCUDE__
#define __POSITION_H_INLCUDE__

#include <iostream>

using namespace std;

// Position in standardized notation form.
// http://en.wikipedia.org/wiki/English_draughts#notation
class Position
{
public:
	Position(int input);
	void Set(int input);
	int Get();
private: 
	int myPosition;
	static const int lowerBound = 1;
	static const int upperBound = 32;
	int clampToBounds(int& value);
};

#endif