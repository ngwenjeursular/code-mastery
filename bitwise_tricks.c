#include "bit_manipulation.h"

/**
 * main - The main function.
 *
 * Return: Always 0.
 */
int main(void)
{
    	unsigned int num = 12;  /* Binary: 1100 */
	/* Set bit at position 2 */
        unsigned int result = setBit(num, 1);
	unsigned int result_clear = clearBit(num, 2);
	unsigned int result_toggle = toggleBit(num, 2);
	int isSet = isBitSet(num, 2);
	int setBitsCount = countSetBits(num);
	
	/*Set*/
    	printf("Original number: %d (Binary: ", num);
    	printBinary(num);
    	printf(")\n");


        printf("Result after setting bit at position 2: %d (Binary: ", result);
	printBinary(result);
	printf(")\n");
	
	printf("\n");
	/*clear*/
	printf("Original number: %d (Binary: ", num);
	printBinary(num);
	printf(")\n");

	printf("Result after clearing bit at position 2: %d (Binary: ", result_clear);
	printBinary(result_clear);
	printf(")\n");
	
	printf("\n");
	/*Toggle*/
	printf("Original number: %d (Binary: ", num);
    	printBinary(num);
    	printf(")\n");

    	printf("Result after toggling bit at position 2: %d (Binary: ", result_toggle);
    	printBinary(result_toggle);
    	printf(")\n");

	printf("\n");
	/*isSet*/
	printf("Original number: %d (Binary: ", num);
   	printBinary(num);
    	printf(")\n");

    	printf("Is bit at position 2 set? %s\n", isSet ? "Yes" : "No");
	
	/*counting set bits*/
	printf("Number: %d (Binary: ", num);
    	printBinary(num);
    	printf(")\n");

    	printf("Number of set bits: %d\n", setBitsCount);


    	return (0);
}
