#ifndef TOWER_H
#define TOWER_H

#include "Disk.h"

#include <deque>		// Required for std::deque

// Represents a tower on the Towers of Hanoi board, containing a number of disks.
class Tower
{
	public:

		// Place a disk atop the tower.
		bool push_disk(Disk* disk);

		// Remove the top disk from the tower.
		void pop_disk(void);

		// Show the disk currently atop the tower.
		Disk* top_disk(void);

		// Returns whether or not the tower is empty of disks.
		bool is_empty(void);

	protected:

		// The deque used to implement the tower "stack".
		std::deque<Disk*> stack;
};

#endif // TOWER_H