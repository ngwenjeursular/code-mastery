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

/**
 * isPowerOfTwo - Check if a number is a power of two.
 * @num: The number to be checked.
 *
 * Return: 1 if the number is a power of two, 0 otherwise.
 */
int isPowerOfTwo(unsigned int num)
{
    	/* A power of two has exactly one bit set to 1 */
    	return ((num != 0) && ((num & (num - 1)) == 0));
}

/**
 * swapWithoutTemp - Swap two values without using a temporary variable.
 * @a: Pointer to the first value.
 * @b: Pointer to the second value.
 */
void swapWithoutTemp(int *a, int *b)
{
     	*a = *a ^ *b;
    	*b = *a ^ *b;
    	*a = *a ^ *b;
}

/**
 * findMSBPosition - Find the position of the most significant bit.
 * @num: The number to be analyzed.
 *
 * Return: The position of the most significant bit, or -1 if no bit is set.
 */
int findMSBPosition(unsigned int num)
{
	int position, i;

    	if (num == 0)
        	return -1; /* No bit is set*/

    	position = 0;

    	/* Iterate over each bit position from left to right*/
    	for (i = sizeof(num) * 8 - 1; i >= 0; --i)
	{
        /*Check if the current bit is set*/
        	if ((num >> i) & 1)
        	{
           	 position = i;
            	break;
        	}
    	}

    	return (position);
}

/**
 * extractLowestSetBit - Extract the position of the lowest set bit.
 * @num: The number to be analyzed.
 *
 * Return: The position of the lowest set bit, or -1 if no bit is set.
 */
int extractLowestSetBit(unsigned int num)
{
	int position;
	unsigned int i;

    	if (num == 0)
        	return -1; /* No bit is set*/

    	/*Use bitwise AND with the two's complement to isolate the rightmost set bit*/
    	position = (num & -num);

    	/*Find the position of the rightmost set bit*/
    	for (i = 0; i < sizeof(num) * 8; ++i)
	{
        	if ((position >> i) & 1)
            	return (i);
    	}

    	return (-1); /*Should not reach here*/
}

/*I'm going to create a simple example that applies some bitwise tricks in the real world.
 * I'll simulate a system where users have different permissions, and
 * I'll use bitwise operations to manage and check those permissions efficiently.
 */

/*Function to check if a user has a specific permission*/
int hasPermission(unsigned int userPermissions, unsigned int permissionToCheck)
{
    	return ((userPermissions & permissionToCheck) != 0);
}

/*Function to grant a permission to a user*/
/**
 * grantPermission - Grant a permission to a user.
 * @userPermissions: Pointer to the permissions of the user.
 * @permissionToAdd: The permission to add.
 */
void grantPermission(unsigned int* userPermissions, unsigned int permissionToAdd)
{
    	*userPermissions |= permissionToAdd;
}

/*Function to revoke a permission from a user*/
/**
 * revokePermission - Revoke a permission from a user.
 * @userPermissions: Pointer to the permissions of the user.
 * @permissionToRemove: The permission to remove.
 */
void revokePermission(unsigned int *userPermissions, unsigned int permissionToRemove)
{
     	*userPermissions &= ~permissionToRemove;
}
