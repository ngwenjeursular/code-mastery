#include "bit_manipulation.h"

/**
 * maxSubarrayXOR - Find the maximum XOR value of subarrays.
 * @arr: The input array.
 * @n: The size of the array.
 *
 * Return: The maximum XOR value.
 */
int maxSubarrayXOR(int arr[], int n)
{
	int max_xor = 0;
	int i, j, curr_xor;

	/*Iterate through all subarrays*/
	for (i = 0; i < n; i++)
	{
		curr_xor = 0;

        	/*Calculate XOR of subarrays starting from i*/
        	for (j = i; j < n; j++)
		{
            		curr_xor = curr_xor ^ arr[j];

            		/* Update the maximum XOR value*/
            		if (curr_xor > max_xor)
                		max_xor = curr_xor;
            	}
        }
    	return (max_xor);
}

/**
 * bitwiseAND - Perform bitwise AND operation.
 * @a: First input.
 * @b: Second input.
 *
 * Return: Result of the AND operation.
 */
unsigned int bitwiseAND(unsigned int a, unsigned int b){
	return (a & b);
}

/**
 * bitwiseOR - Perform bitwise OR operation.
 * @a: First input.
 * @b: Second input.
 *
 * Return: Result of the OR operation.
 */
unsigned int bitwiseOR(unsigned int a, unsigned int b)
{
	return a | b;
}


/**
 * bitwiseXOR - Perform bitwise XOR operation.
 * @a: First input.
 * @b: Second input.
 *
 * Return: Result of the XOR operation.
 */
unsigned int bitwiseXOR(unsigned int a, unsigned int b)
{
	return a ^ b;
}

/**
 * displayBinary - Display binary representation of an integer.
 * @num: The input number.
 */
void displayBinary(unsigned int num)
{
	int i;

	printf("Binary: ");
    	for (i = sizeof(num) * 8 - 1; i >= 0; --i)
    	{
        	printf("%d", (num >> i) & 1);
    	}
    	printf("\n");
}
