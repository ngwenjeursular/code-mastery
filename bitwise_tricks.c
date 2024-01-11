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
	unsigned int num1 = 16, num2 = 12, num3 = 1;
	int num_one = 5, num_two = 10;
	unsigned int num_1 = 0,  num_2 = 12,  num_3 = 128;
	unsigned int no_1 = 0, no_2 = 12, no_3 = 128;
	unsigned int userPermissions = 0;
	
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
	printf("\n");
	/*check if a number is a power of two*/
	printf("%d is %s power of two.\n", num1, isPowerOfTwo(num1) ? "a" : "not a");
    	printf("%d is %s power of two.\n", num2, isPowerOfTwo(num2) ? "a" : "not a");
    	printf("%d is %s power of two.\n", num3, isPowerOfTwo(num3) ? "a" : "not a");
	printf("\n");

	/*Swapping two values without using a temporary variable*/
	printf("Before swap: num_one = %d, num_two = %d\n", num_one, num_two);
	printf("\n");

	swapWithoutTemp(&num_one, &num_two);
	printf("After swap: num_one = %d, num_two = %d\n", num_one, num_two);
	printf("\n");

	/*Finding the most significant bit (MSB)*/
	printf("MSB position of %d: %d\n", num_1, findMSBPosition(num_1));
    	printf("MSB position of %d: %d\n", num_2, findMSBPosition(num_2));
    	printf("MSB position of %d: %d\n", num_3, findMSBPosition(num_3));
	printf("\n");

	/*Extracting the lowest set bit*/
	printf("Lowest set bit position of %d: %d\n", no_1, extractLowestSetBit(no_1));
    	printf("Lowest set bit position of %d: %d\n", no_2, extractLowestSetBit(no_2));
    	printf("Lowest set bit position of %d: %d\n", no_3, extractLowestSetBit(no_3));
	
	/*Grant read and write permissions to the user*/
	grantPermission(&userPermissions, READ_PERMISSION);
    	grantPermission(&userPermissions, WRITE_PERMISSION);

	/*Check if the user has execute permission*/
	if (hasPermission(userPermissions, EXECUTE_PERMISSION))
		printf("User has execute permission.\n");
	else
		printf("User does not have execute permission.\n");

	/*Revoke write permission from the user*/
	revokePermission(&userPermissions, WRITE_PERMISSION);

	/*Check if the user has write permission after revocation*/
	if (hasPermission(userPermissions, WRITE_PERMISSION))
		printf("User still has write permission.\n");
	else
		printf("User no longer has write permission.\n");

    	return (0);
}
