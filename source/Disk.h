#ifndef DISK_H
#define DISK_H

// Represents a disk on a tower.
class Disk
{
	public:

		// Constructor for when provided a disk number.
		Disk(unsigned int number);

		// Returns the integer ID of the disk.
		unsigned int get_disk_number(void);

		// Allows for less-than comparison between disks.
		bool operator<(Disk& comparison_value);

		// Allows for greater-than comparison between disks.
		bool operator>(Disk& comparison_value);

	protected:

		// The integer ID of the disk. A disk may only stack upon another disk with a larger disk number.
		unsigned int disk_number;
};

#endif // DISK_H