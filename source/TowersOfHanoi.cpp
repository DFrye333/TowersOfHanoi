#include "TowersOfHanoi.h"

// Constructor for when given the number of disks on the board.
TowersOfHanoi::TowersOfHanoi(unsigned int num_disks)
{
	// Initialize a new board with the required number of disks.
	board = new Board(num_disks);

	// The minimum number of moves possible to make in solving a puzzle with num_disks disks is (2 ^ (num_disks) - 1).
	minimum_moves = (1 << num_disks) - 1;

	// Initialize the number of moves made to zero.
	moves = 0;
}

// Calls a recursive solve method to solve the puzzle.
void TowersOfHanoi::solve(void)
{
	// Solve the puzzle!
	solve(board->get_number_disks(), LEFT, RIGHT);

	// Print final solution statistics.
	std::cout << "Done! Finished in " << moves << " moves (with a minimum of " << minimum_moves << " moves)." << std::endl;
}

// Recursively solves the puzzle.
void TowersOfHanoi::solve(const unsigned int num_disks, const Tower_ID source, const Tower_ID destination)
{
	// Entire stack of disks has been moved.
	if (num_disks == 0)
	{
		return;
	}

	// Move the stack of disks above the current disk.
	solve(num_disks - 1, source, determine_intermediate(source, destination));

	// Move the current disk.
	if (board->move(source, destination))
	{
		++moves;
	}

	// Move the stack of disks back atop the current disk.
	solve(num_disks - 1, determine_intermediate(source, destination), destination);
}

// Determine which tower is the intermediate tower, given a source and a destination tower.
Tower_ID TowersOfHanoi::determine_intermediate(const Tower_ID source, const Tower_ID destination)
{
	return (Tower_ID)(~(source + destination) % board->get_number_towers());
}