#include "bit_manipulation.h"

/*
 * main - entry point
 *
 * Return: 0 (Sucess)
 */
int main(void)
{
	int permissions;
	int rgbColor;
	int red, green, blue;
	time_t currentTime;
	struct tm *localTime; /*get current time*/
	int hours, minutes, seconds;
	int leftRotate_result, i, leftmostOnePosition = 31;
	unsigned int rightRotate_result, inputData, hashValue, gpioConfig;

	left_bitwise_shift();
	right_bitwise_shift();


	/*let's use the left bitwise shifting to create or Manipulate Flags or Options Represented as Bit Positions:*/
	/*Suppose you have a set of options related to user permissions:

	Bit 0: Read Permission
	Bit 1: Write Permission
	Bit 2: Execute Permission
	
	You can represent these permissions using a single integer. For instance:

	000 might represent no permissions,
	001 might represent read-only,
	011 might represent read and write, and so on.
	By using bitwise operators, you can easily manipulate and check these flags.*/
	permissions = READ_PERMISSION | WRITE_PERMISSION;
	
	/*Check if write permission is set*/
	if (permissions & WRITE_PERMISSION)
		printf("Write permission is granted.\n");
	/*Remove read permission*/
	permissions &= ~READ_PERMISSION;

	/*Check if read permission is set*/
	if (permissions & READ_PERMISSION)
		printf("Read permission is granted.\n");
	else
		printf("Read permission is not granted.\n");

	/*let's use right bitwise shifting to Extract Components of a Fixed-Width Binary Representation*/
	/*let's Consider a 24-bit RGB color representation, where the most 
	 * significant 8 bits represent red, the next 8 bits represent green,
	 * and the least significant 8 bits represent blue:*/
	
	/*bitwise AND (&) is used to mask out irrelevant bits, and
	 * then right shifts (>>) are applied to obtain the individual color components.*/


	/*Represent a color in RGB (24-bit)*/
	rgbColor = 0x1F2A3B;

	/*Extract individual color components*/
	red   = (rgbColor & RED_MASK)   >> 16;
	green = (rgbColor & GREEN_MASK) >> 8;
	blue  =  rgbColor & BLUE_MASK;

	printf("Red: %d, Green: %d, Blue: %d\n", red, green, blue);
	
	/*Lastly let's create a simple simulation of a binary clock*/
	/*we'll consider a 6-bit binary clock, where each bit 
	 * represents a unit of time (hours, minutes, and seconds).*/
	/*please note you might observe a discrepancy likely due to the time zone difference*/
	/*I'm too tired to fix it right now, see it as practice to correct it*/
	time(&currentTime);
	localTime = localtime(&currentTime);

	/*Extract hours, minutes, and seconds*/
	hours = localTime->tm_hour;
	minutes = localTime->tm_min;
	seconds = localTime->tm_sec;
	
	/*Display the binary clock*/
	displayBinaryClock(hours, minutes, seconds); /*find this function defined in practice_file_1.c*/
	
	/*Bitwise rotation*/	
	leftRotate_result  = leftRotate(0xD5, 2);

	while (!((leftRotate_result >> leftmostOnePosition) & 1) && leftmostOnePosition > 0)
	{
		leftmostOnePosition--;
	}
	for (i = leftmostOnePosition; i >= 0; --i)
		printf("%d", (leftRotate_result >> i) & 1);
	printf("\n");

	/*Right bitwise rotation*/
	rightRotate_result = rightRotate(0xD5, 2);

	while (!((rightRotate_result >> leftmostOnePosition) & 1) && leftmostOnePosition)
	{

        	leftmostOnePosition--;
	}

	/* Print the result in binary without leading zeros */
	for (i = leftmostOnePosition; i >= 0; --i)
		printf("%d", (rightRotate_result >> i) & 1);
	printf("\n");

	/*Hashing Function*/
	inputData = 0xD6;

	/*printf("%d", (hashValue >> i) & 1);*/
	hashValue = hashFunction(inputData);

	/*Print the original input and the resulting hash*/
	printf("Original Input: ");
	for (i = sizeof(inputData) * 8 - 1; i >= 0; --i)
		printf("%d", (inputData >> i) & 1);

	printf("\nHash Value:      ");
	for (i = sizeof(hashValue) * 8 - 1; i >= 0; --i)
		printf("%d", (hashValue >> i) & 1);

	printf("\n");

	/*let's say for e.g we have a microcontroller with a GPIO configuration
	 *  register where each bit represents the configuration of a specific pin.
	 *  We want to configure Pin 3 as an output. We'll use right bitwise rotation
	 */
	/*GPIO stands for: General-Purpose Input/Output (GPIO) */

	/*Initial GPIO configuration register*/
	gpioConfig = 0x00;

	/*Display the initial configuration*/
	printf("Initial GPIO Configuration: %08X\n", gpioConfig);

	/*Configure Pin 3 as an output*/
	gpioConfig = configurePinAsOutput(gpioConfig, 3);

	/*Display the updated configuration*/
	printf("Updated GPIO Configuration: %08X\n", gpioConfig);
	
	return (0);


}
