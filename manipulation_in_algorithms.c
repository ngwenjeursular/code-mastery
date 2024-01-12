/*Day 9*/
/*looking at bitwise manipulation in algorithms*/

#include "bit_manipulation.h"

/*main - entry point
 *
 * Return: 0 on Success
 */
int main(void)
{
	/*code to find the single non-repeated element in an array using bitwise XOR*/
	int arr[] = {2, 4, 7, 2, 4, 7, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	int singleNonRepeated;
	unsigned char grayscaleImage[] = {10, 25, 200, 100, 50};
	int imageSize;
	int set[] = {1, 2, 3};
	int setSize = sizeof(set) / sizeof(set[0]);
	unsigned int i;


	singleNonRepeated = findSingleNonRepeated(arr, size);

	printf("The single non-repeated element is: %d\n", singleNonRepeated);

	/*counting set bits example*/
	imageSize = sizeof(grayscaleImage) / sizeof(grayscaleImage[0]);
	/*Simulate image processing using set bits count*/
	processImage(grayscaleImage, imageSize);

	/*Generate and print the power set*/
	generatePowerSet(set, setSize);

	/*In Gray code*/
	for (i = 0; i < 8; ++i)
	{
    		printf("Decimal: %u\tBinary: ", i);
    		printBinary2(i, 3);  // Assuming a 3-bit representation for simplicity
    		printf("\tGray Code: ");
    		printBinary2(decimalToGray(i), 3);
    		printf("\n");
	}


	return (0);
}
