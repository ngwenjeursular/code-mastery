/*DAY 10*/
/*Advanced hacks and tricks*/

/*Counting Trailing zeroes*/
/**
 * countTrailingZeros - Count the number of trailing zeros (rightmost set bit position).
 * @num: The input number.
 *
 * Return: The position of the rightmost set bit (0-indexed).
 */
int countTrailingZeros(unsigned int num)
{
	return num & -num;
}

/*Finding the log base 2 of a number*/

/**
 * logBase2 - Find the logarithm base 2 of a number.
 * @num: The input number.
 *
 * Return: The logarithm base 2 of the number.
 */
int logBase2(unsigned int num)
{
	if (num == 0)
    	{
        	/* Logarithm is undefined for 0 */
        	return -1;
    	}

    	/* Using countTrailingZeros to find the logarithm base 2 */
    	return (countTrailingZeros(num));
}

/*Reversing bits in a number*/
/**
 * reverseBits - Reverse the bits in a given number.
 * @num: The input number.
 *
 * Return: The number with reversed bits.
 */
unsigned int reverseBits(unsigned int num)
{
    unsigned int reversed = 0;
    int bitsCount = sizeof(num) * 8;
    int i;

    for (i = 0; i < bitsCount; ++i)
    {
        /* Shift the reversed number to the left */
        reversed <<= 1;
        /* Add the rightmost bit of num to reversed */
        reversed |= num & 1;
        /* Shift num to the right */
        num >>= 1;
    }

    return (reversed);
}

/**
 * countSetBitsSparse - Count the number of set bits in a sparse binary number.
 * @num: The input number.
 *
 * Return: The count of set bits.
 */
int countSetBitsSparse(unsigned int num)
{
	int count = 0;

    	while (num != 0)
	{
        	/* Increment count for each set bit */
        	count += num & 1;
        	/* Right shift num to check the next bit */
        	num >>= 1;
    	}

    	return (count);
}
