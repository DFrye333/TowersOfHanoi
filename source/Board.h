#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#include "Tower_ID.h"
#include "Tower.h"

// Represents the Towers of Hanoi board, containing a number of towers.
class Board
{
	public:

		// Constructor for when provided the number of towers and number of disks required.
		Board(int num_disks);

		// Destructor should destroy all towers and the disks that they contain.
		~Board();

		// Sets each disk's next move.
		bool move(Tower_ID source, Tower_ID destination);

		// Returns the number of towers on the board.
		const unsigned int get_number_towers(void);

		// Returns the number of disks on the board.
		unsigned int get_number_disks(void);

	protected:

		// The number of towers on the board (three by default).
		static const unsigned int NUMBER_TOWERS = 3;

		// The number of disks on the board.
		unsigned int number_disks;

		// The array of towers on the board.
		Tower* towers;
};

#endif // BOARD_H