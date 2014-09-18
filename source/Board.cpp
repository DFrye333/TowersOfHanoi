#include "Board.h"

// Constructor for when provided the number of towers and number of disks required.
Board::Board(int num_disks)
{
	number_disks = num_disks;

	// Allocate tower array.
	towers = new Tower[NUMBER_TOWERS];

	// Initialize disk position at left-most tower (Tower 0).
	for (unsigned int i = 0; i < number_disks; ++i)
	{
		towers[LEFT].push_disk(new Disk((number_disks - i - 1)));
	}
}

// Destructor should destroy all towers and the disks that they contain.
Board::~Board()
{
	// Deallocate all disks from all towers.
	for (int i = LEFT; i < NUMBER_TOWERS; ++i)
	{
		// Deallocate all disks from tower.
		while (towers[i].top_disk() != NULL)
		{
			// Deallocate tower's top disk.
			Disk* toDelete = towers[i].top_disk();
			towers[i].pop_disk();
			delete toDelete;
		}
	}

	// Deallocate tower array.
	if (towers != NULL)
	{
		delete[] towers;
		towers = NULL;
	}
}

// Sets each disk's next move.
bool Board::move(Tower_ID source, Tower_ID destination)
{
	if (towers[destination].push_disk(towers[source].top_disk()))
	{
		std::cout << "Moving " << towers[source].top_disk()->get_disk_number() + 1 << " from Tower " << source + 1 << " to " << destination + 1 << std::endl;
		towers[source].pop_disk();
		return true;
	}

	return false;
}

// Returns the number of towers on the board.
const unsigned int Board::get_number_towers(void)
{
	return NUMBER_TOWERS;
}

// Returns the number of disks on the board.
unsigned int Board::get_number_disks(void)
{
	return number_disks;
}