/*DAY 8*/
/*Bitwise Tricks and Techniques*/

/*common bitwise operations and tricks:
 * 	Setting a Bit
 * 	Clearing a Bit
 * 	Toggling a Bit
 * 	Checking if a Bit is Set
 * 	Counting Set Bits (Hamming Weight)
 * 	Checking Power of Two
 * 	Swapping Two Values without Temporary Variable
 * 	Finding the Most Significant Bit
 * 	Extracting the Lowest Set Bit
 */

/*Setting a bit*/
/* Setting a bit involves changing its value to 1 while leaving the other bits unchanged. */
/*Let's say you have the number num = 12 (binary 1100). You want to set the 
 * bit at position 1 (from the right, starting with 0).*/

#include "bit_manipulation.h"
/**
 * setBit - Set a specific bit at a given position.
 * @num: The original number.
 * @pos: The position of the bit to be set.
 *
 * Return: The result after setting the bit.
 */
unsigned int setBit(unsigned int num, int pos)
{
	/* Create a mask with the target bit set to 1 */
    	unsigned int mask = 1 << pos;

	/* Use bitwise OR to set the target bit */
	unsigned int result = num | mask;

     	return (result);
}

/**
 * printBinary - Print the binary representation of a number.
 * @num: The number to be printed.
 *
 * Return: void
 */
void printBinary(unsigned int num)
{
    	int i;

    	for (i = sizeof(num) * 8 - 1; i >= 0; --i)
        	printf("%d", (num >> i) & 1);
}

/**
 * clearBit - Clear a specific bit at a given position.
 * @num: The original number.
 * @pos: The position of the bit to be cleared.
 *
 * Return: The result after clearing the bit.
 */
unsigned int clearBit(unsigned int num, int pos)
{
	/* Create a mask with the target bit cleared to 0 */
	unsigned int mask = ~(1 << pos);

	/* Use bitwise AND to clear the target bit */
	unsigned int result = num & mask;

	return (result);
}

/**
 * toggleBit - Toggle a specific bit at a given position.
 * @num: The original number.
 * @pos: The position of the bit to be toggled.
 *
 * Return: The result after toggling the bit.
 */
unsigned int toggleBit(unsigned int num, int pos)
{
     	/* Create a mask with the target bit set to 1 */
    	unsigned int mask = 1 << pos;

    	/* Use bitwise XOR to toggle the target bit */
    	unsigned int result_toggle = num ^ mask;

    	return (result_toggle);
}

/*Checking if a bit is set*/
/**
 * isBitSet - Check if a specific bit at a given position is set.
 * @num: The original number.
 * @pos: The position of the bit to be checked.
 *
 * Return: 1 if the bit is set, 0 otherwise.
 */
int isBitSet(unsigned int num, int pos)
{
    /* Create a mask with the target bit set to 1 */
    unsigned int mask = 1 << pos;

    /* Use bitwise AND to check if the target bit is set */
    return ((num & mask) != 0);
}

/*Counting Set Bits */
/**
 * countSetBits - Count the number of set bits in a number using Brian Kernighan's algorithm.
 * @num: The number for which set bits are to be counted.
 *
 * Return: The count of set bits.
 */
int countSetBits(unsigned int num)
{
	int count = 0;

    	while (num != 0)
    	{
        	num = num & (num - 1);
        	count++;
    	}

    	return (count);
}
