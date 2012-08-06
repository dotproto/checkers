#include <iostream>
#include <vector>
using namespace std;

typedef int player;

// Position in standardized notation form.
// http://en.wikipedia.org/wiki/English_draughts#notation
class Position
{
private: 
	int myPosition;
	static const int lowerBound = 1;
	static const int upperBound = 32;

	int clampToBounds(int& value)
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
	}

public:
	void Set(int input)
	{
		myPosition = clampToBounds(input);
		return;
	};

	int Get()
	{
		return myPosition;
	};

	Position(int input)
	{
		Set(input);
	};
};

//// CONSTANTS
// Deinfe the dimensions of the playing surface (board).
const int BOARDHEIGHT = 8;
const int BOARDWIDTH  = 8;

// The "color" played by a given user. Color selection determines order of
// play and side of the board used.
enum Team
{
	black,   // "dark" color common in USA 
	red = 0, // "dark" color common in England
	white    // standard "light" color
};

// Basic information about a "draught" or piece on the board.
struct draught
{
	Team player;   // Color played by the current player (black or white)
	Position pos;  // Position of the draught.
	
	// xloc - Distance from left edge   (1 = leftmost,   BOARDHEIGHT = rightmost)
	// yloc - Distance from bottom edge (1 = bottommost, BOARDWIDTH  = topmost)
};

// Board location. Specifies the location of a draught or
// where the user would like to move a draught. 
struct location
{
	int y;  // 1 character numeric value [1-8]
	char x; // 1 character alpha value [a-hA-H]
};

// Convert position notation into board row and column coordinates.
void posToCord(int pos, int& row, int &col) {
	// Row and column converstion notes:
	// 
	// * Rows - distance from board's bottom edge.
	// * Cols - distance from board's left edge.
	//
	// Rows are straight forward, but columns have special rules that determine
	// the coordinates of valid positions.

	// Convert position to zer-based index
	pos -= 1;

	//// ROW CALCULATION
	// Row number = quotient of (position / positions per row)
	row = pos / 4;
	
	//// COL CALCULATION
	// Initial col value = remainder of (position / positions per row)
	col = pos % 4;

	// Col now represents a position offest from the right side, but we need the
	// column offset from the left side. To get this value we must 
	//
	// 1. Derive an offset of positions from the right side.
	// 2. Add additional spaces based on distance from right
	// 3. Adjust for odd/even row count.

	// Step 1. Derive offset from right (0..3)
	col = 3 - col;
	// Step 2. Adjust for additional spaces (2 spaces for every 1 unit from left)
	col *= 2;
	// Step 3. Adjust even rows (even board rows are odd due to zero-based index)
	if (row % 2 != 0) 
		col += 1;
};

bool isValidInputFormat()
{
	// Check string lenght; expecting 2 characters
	// Check string contents; expecting 1 alpha, 1 numeric
	//   Store alpha and numeric as seperate vars
	//   Convert numeric to zero-based numeric y coord value
	//   Convert alpha to zero-based numeric x coord value
	//
	// if success: return true, update x and y coords
	return true;
};

bool isValidCoord(string userInput, Position pos)
{
	// Verify that x,y coords point to a valid position
	// 
	// if success: return true, update pos with position
	return true;
};

void isValidMove(Position draughtLoc, Position targetLoc)
{};

// User enters coordinates. Specifies draught and targets.
//  - Entered as a number-leter combination (e.g. 1a 5d, etc.)
//  - May enter target as where they want to move or the piece to jump.
// System stores positions. Must properly handle coords; this includes:
//  - Convert user input to meaingful data.
//  - Convert internal data to user-understandable output.
//    - Board view
//    - Coordinate map
//    - Meaningful error messages
//  - Validate user input
//    - Draught must be a valid draught location (e.g. D2=valid, D3=invalid)
//      - convert coord to position, error if invalid
//      - valide current user owns draught, error if invalid
//    - Target may be empty space, draught to jump, or location after jump
//      - convert coord to position, error if invalid
//      - check if target is a valid position, error if not
//      - check if location is free or contains a draught
//        - if target = draught
//          - check if druaght is owned by other player, error if not
//          - check if draught is in an attackable location, error if not
//          - check if location behind draught is clear, error if not
//        - if target = free, may be a direct move or jump...
//          - check if location is 1 or 2 moves away, error if not
//          - if 1 move away and clear it is a move. execute
//          - if 1 move away and contains a draught, it is a jump.
//            - check if position after draught is clear, if not error
//          - if 2 moves away (and clear) it is a jump
//            - verify that move sequence is diagonal (e.g. 2-11 okay, 2-10 bad, 2-9 okay)
//            - verify that enemy draught appears in the interveining space, error if not
//   ^ Need to add checks to make sure target does not ignore a possible jump.

int main ()
{
	vector<draught> draughts;
	
	int pos;
	while (true)
	{
		cout << "Enter position (Ctlr-Z to exit): ";

		if (!(cin >> pos))
			break;

		int row = 0,
			col = 0;
		posToCord(pos, row, col);

		// Print results
		cout << "Row:"     << row << endl;
		cout << "Column: " << col << endl;
	}
	return 0;
}