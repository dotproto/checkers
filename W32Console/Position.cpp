// Position in standardized notation form.
// http://en.wikipedia.org/wiki/English_draughts#notation

#include <iostream>
#include "Position.h"
using namespace std;

Position::Position(int input)
{
	Set(input);
};

void Position::Set(int input)
{
	myPosition = clampToBounds(input);
	return;
};

int Position::Get()
{
	return myPosition;
};

int Position::clampToBounds(int& value)
{
	if (value < lowerBound)
	{
		clog << "WARNING: Position '" << value << "' is below " << lowerBound << "." << endl;
		clog << "Value will be clamped to " << lowerBound << ".";
		value = lowerBound;
	}

	if (value > upperBound)
	{
		clog << "WARNING: Position '" << value << "' is above " << upperBound << "." << endl;
	    clog << "Value will be clamped to " << upperBound << ".";
		value = upperBound;
	}

	return value;
};