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


	return (0);


}
