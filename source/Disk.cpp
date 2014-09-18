#include "Disk.h"

// Constructor for when provided a disk number.
Disk::Disk(unsigned int number)
{
	disk_number = number;
}

// Returns the integer ID of the disk.
unsigned int Disk::get_disk_number(void)
{
	return disk_number;
}

// Allows for less-than comparison between disks.
bool Disk::operator<(Disk& comparison_value)
{
	return this->disk_number < comparison_value.disk_number;
}

// Allows for greater-than comparison between disks.
bool Disk::operator>(Disk& comparison_value)
{
	return this->disk_number > comparison_value.disk_number;
}