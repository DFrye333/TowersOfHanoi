#ifndef TOWERSOFHANOI_H
#define TOWERSOFHANOI_H

#include "Board.h"

// Represents an instance of the Towers of Hanoi puzzle.
class TowersOfHanoi
{
	public:

		// Constructor for when given the number of disks on the board.
		TowersOfHanoi(unsigned int num_disks);

		// Calls a recursive solve method to solve the puzzle.
		void solve(void);

	protected:

		// Recursively solves the puzzle.
		void solve(const unsigned int num_disks, const Tower_ID source, const Tower_ID destination);

		// Determine which tower is the intermediate tower, given a source and a destination tower.
		Tower_ID determine_intermediate(const Tower_ID source, const Tower_ID destination);

		// A board containing towers and disks.
		Board* board;

		// The number of moves made so far. A "long long" probably is not necessary here...
		unsigned long long moves;

		// The minimum number of moves required to complete the puzzle. Ideally, this AI agent always completes the puzzle in the minimum number of moves.
		unsigned long long minimum_moves;
};

#endif // TOWERSOFHANOI_H