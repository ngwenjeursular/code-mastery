/*DAY 9*/

/*common scenarios where bitwise manipulation is frequently applied in algorithms:*/
/*Scenario 1: Finding the Single Non-Repeated Element*/
/*As an example,  Let's write code to find the single 
 * non-repeated element in an array using bitwise XOR. */

#include "bit_manipulation.h"

/**
 * findSingleNonRepeated - Find the single non-repeated element in the array.
 * @arr: The input array.
 * @size: The size of the array.
 *
 * Return: The single non-repeated element.
 */
int findSingleNonRepeated(int arr[], int size)
{
	int result = 0, i;

	for (i = 0; i < size; i++)
		result ^= arr[i];

	return (result);
}

/*Scenario 2: Counting Set Bits (Hamming Weight)*/
/*As an example: where counting set bits can be used as a basic metric for image brightness. */
/*Consider a grayscale image where each pixel value represents the intensity.
 * We can use the count of set bits in each pixel's binary representation as a
 *  measure of brightness.*/

/*First we write a function to count set bits*/
/**
 * countSetBits - Count the number of set bits in an integer.
 * @pixel: The input integer representing pixel intensity.
 *
 * Return: The count of set bits.
 */
int countSetBits2(unsigned char pixel)
{
	int count = 0;

    	while (pixel != 0)
	{
        	count += pixel & 1;
        	pixel >>= 1;
    	}

    	return (count);
}

/*Next we write a function to simulate image processing using set bits count*/
/**
 * processImage - Simulate image processing using set bits count.
 * @image: The array representing the grayscale image.
 * @size: The size of the image array.
 */
void processImage(unsigned char image[], int size)
{
	int i, brightness ;

	for (i = 0; i < size; i++)
	{
        	brightness = countSetBits2(image[i]);

        	printf("Pixel %d - Brightness: %d\n", i, brightness);
    	}
}

/*Scenario 3: Generating a power set*/
/*Generating the power set of a set is a common problem in computer science 
 * and involves finding all possible subsets of a given set*/

/*Below: C program to generate the power set of a set of integers.*/
/**
 * generatePowerSet - Generate and print the power set of a given set.
 * @set: The array representing the original set.
 * @setSize: The size of the set.
 */
void generatePowerSet(int set[], int setSize)
{
	/*The total number of possible subsets is 2^setSize*/
    	int totalSubsets = 1 << setSize;
    	int i, j;

    	printf("Power Set:\n");

    	/* Outer loop to iterate through all subsets*/
    	for (i = 0; i < totalSubsets; i++)
    	{
        	printf("{ ");

        	/*Inner loop to check each bit in i*/
        	for (j = 0; j < setSize; j++)
        	{
            		/*If the jth bit of i is set, include the corresponding element in the subset*/
            		if (i & (1 << j))
				printf("%d ", set[j]);
            	}	
        }

        printf("}\n");
}

/*Scenario 4: Gray code*/
/*is a binary numeral system where two successive values differ in only one bit.
 *  Unlike traditional binary representation, where adjacent values can differ 
*   significantly, Gray code ensures that the transition between consecutive 
*   values involves changing only a single bit.*/

/**
 * decimalToGray - Convert decimal to Gray code.
 * @num: The decimal number to be converted.
 *
 * Return: Gray code representation of the decimal number.
 */
unsigned int decimalToGray(unsigned int num)
{
	return (num ^ (num >> 1));
}

#include <stdio.h>

/**
 * printBinary2 - Print binary representation of a decimal number.
 * @num: The decimal number to be converted.
 * @bits: The number of bits to consider for representation.
 */
void printBinary2(unsigned int num, int bits)
{
	int i;

	for (i = bits - 1; i >= 0; --i)
        	printf("%d", (num >> i) & 1);
}

