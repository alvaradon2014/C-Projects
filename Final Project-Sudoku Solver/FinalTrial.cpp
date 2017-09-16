
// EE 3223 Nayely Alvarado
// Final Project Sudoku Solver

#include <iostream>
#include <fstream>

using namespace std;

class Board
{
public:
	
	// Holds board values
	int values[9][9];

	// Holds possible values that can go into an empty block
	int keyValue[9] = {};

	// Finds value options for an empty block
	int* valueOpt(const Board &board, int row, int col);

	// Determines if the board is full, if not, index of empty space is found
	bool findEmpty(Board &board, int &row, int &col);

	// Function to (hopefully) solve board by using other class functions
	bool solvePuzzle(Board &board);

};



// Finds next empty block in board
// If found, then row and col will set the location
// If full, returns false (since there are NO empty slots)
bool Board::findEmpty(Board &board, int &row, int &col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (board.values[row][col] == 0)
				return true;
	return false;
}


// Function finds all values that can go into an empty spot
// Does this by checking: row, column, and block of empty spot
// Value options stored in KeyValue array (9 elements for 9 possible values)
int* Board::valueOpt(const Board &board, int row, int col)
{
	// Check row entries
	int j;
	for (j = 0; j < 9; j++) {
		if (board.values[row][j] != 0)
			// column contains filled spot
			// value in column can't repeat in indicated block
			// 1 indicates invalid value for block
			keyValue[board.values[row][j] - 1] = 1;
	}

	// Check column entries
	int i;
	for (i = 0; i < 9; i++) {
		if (board.values[i][col] != 0)
			// row contains filled spot
			// value in row can't repeat in indicated block
			// 1 indicates invalid value for block
			keyValue[board.values[i][col] - 1] = 1;
	}

	// Check 3x3 box entries
	int hor, vert;

	// BUT FIRST:
	// Find horizontal box location
	if ((row >= 0) && (row <= 2))
		hor = 0;
	else if ((row >= 3) && (row <= 5))
		hor = 3;
	else
		hor = 6;

	// Find vertical box location
	if ((col >= 0) && (col <= 2))
		vert = 0;
	else if ((col >= 3) && (col <= 5))
		vert = 3;
	else
		vert = 6;

	// NOW check 3x3 box entries
	for (i = hor; i < (hor + 3); i++)
		for (j = vert; j < (vert + 3); j++) {
			if (board.values[i][j] != 0)
				// box contains filled spot
				// value in box can't repeat in indicated block
				// 1 indicates invalid value for block
				keyValue[board.values[i][j] - 1] = 1;
		}

	for (i = 0; i < 9; i++) {
		if (keyValue[i] != 1)
			// array filled with values that can be placed in block
			keyValue[i] = i + 1;
		else
			// invalid options are set to 0
			keyValue[i] = 0;
	}

	return (keyValue);
}

// Function (hopefully) solves and prints board
bool Board::solvePuzzle(Board &board)
{
	int row = 0, col = 0, x = 0, y = 0;
	int *options;

	// Options set to 0 means any value can go into the specified spot


	// Check if board is full (puzzle completed)
	if (!findEmpty(board, row, col)) {
		return true;
	}


	for (int test = 1; test <= 9; test++) {
	// Fill in board with possible values, rinse, and repeat
			options = valueOpt(board, row, col);
	
			// Is test number a value option?
			if (test == *(options + (test - 1))) {
				board.values[row][col] = *(options + (test - 1));
				if (solvePuzzle(board))
					return true;
				board.values[row][col] = 0;
			}
	}

	return false;
}




int main()
{
	int row = 0;
	int col = 0;

	Board Sudoku;

	// fstream class instance 'i' for inputting data
	ifstream inFile;

	// Check if file opened, error message if unable to open
	inFile.open("TestBoard.txt");
	if (inFile.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}

	// File opened successfully!
	// Read data onto Sudoku board
	while (!inFile.eof())
	{
		// Fill in block with file data
		inFile >> Sudoku.values[row][col];

		// Move to next block, change index
		if (col == 8) {
			// End of row? Move to front of next row
			col = 0;
			row++;
		}
		else {
			// Continue down row
			col++;
		}
	}

	// Finished reading from file, close it up!
	inFile.close();

	// fstream instance of class 'o' for outputting data
	ofstream outFile;

	// Open a new text file
	outFile.open("SolnBoard");

	// Prints out given puzzle to a new text file
	outFile << "Original Board: " << endl;

	for (row = 0; row < 9; row++) {
		if ((row == 3) || (row == 6))
			outFile << "----------------------" << endl;
		for (col = 0; col < 9; col++) {
			if ((col == 3) || (col == 6))
				outFile << "| ";
			outFile << Sudoku.values[row][col] << " ";
		}
		outFile << endl;
	}


	// Solves Sudoku puzzle using class functions explained above
	if (Sudoku.solvePuzzle(Sudoku)) {

		// Prints out Board Solution to a text file
		outFile << endl << "Board Solution: " << endl;

		for (row = 0; row < 9; row++) {
			if ((row == 3) || (row == 6))
				outFile << "----------------------" << endl;
			for (col = 0; col < 9; col++) {
				if ((col == 3) || (col == 6))
					outFile << "| ";
				outFile << Sudoku.values[row][col] << " ";
			}
			outFile << endl;
		}
		// Done solving, done outputting, close the file!
		outFile.close();
	}
	else {
		outFile << "No solution could be found" << endl;
		outFile.close();
	}

	return(0);
}





