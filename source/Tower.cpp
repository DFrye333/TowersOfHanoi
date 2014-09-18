#include "Tower.h"

// Place a disk atop the tower.
bool Tower::push_disk(Disk* disk)
{
	// Ensure that new disk is smaller than the disk currently atop the tower.
	if (top_disk() == NULL || ((*top_disk()) > (*disk)))
	{
		stack.push_front(disk);
		return true;
	}

	return false;
}

// Remove the top disk from the tower.
void Tower::pop_disk(void)
{
	stack.pop_front();
}

// Show the disk currently atop the tower.
Disk* Tower::top_disk(void)
{
	if (!stack.empty())
	{
		return stack.front();
	}
	else
	{
		return NULL;
	}
}

// Returns whether or not the tower is empty of disks.
bool Tower::is_empty(void)
{
	return stack.empty();
}