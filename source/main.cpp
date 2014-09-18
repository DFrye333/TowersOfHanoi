/******************************************************************************
Towers of Hanoi
---------------

Assumes three stacks and an arbitrary number of disks.

	1. Assign all disks a long-term goal (the final stack it should be sitting 
on, canonically Stack 3).
	2. Determine stack that needs goal assignment. One and only one stack 
should be eligible at a time. Which stack:
		a. Has a top disk?
		b. Its top disk has an open spot to move to?
		c. Its top disk did not just take a turn moving?
	The stack that meets all of these criteria is the stack to choose for goal 
   assignment.
	3. Starting from the bottom of the stack and working up, assign each disk 
a short-term goal (the next move it should make). The lowest disk's short-term 
goal should be to move atop the next-largest disk. The largest disk's 
next-largest disk is an empty stack (preferring its long-term goal stack) or, 
if no stacks are empty, its long-term goal stack. Successive disks up a stack 
should be assigned alternating goal stacks.
	4. Moving from the top of the stack downward, move the stack's disks to 
their short-term goal states until the stack's top is not eligible for a move.
	5. Repeat from Step 2 until all disks are on their long-term goal stack.
******************************************************************************/

#include "TowersOfHanoi.h"

int main(int argc, char* argv[])
{
	unsigned int number_disks = 3;

	TowersOfHanoi towers_of_hanoi(number_disks);

	towers_of_hanoi.solve();
}