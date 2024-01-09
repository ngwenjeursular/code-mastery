/* Day 6 of Code mastery*/
/* Bitwise shifts*/


/*Left Bitwise Shift (<<): */
/*The left shift effectively multiplies the number by 2^n (where n is the number of positions shifted).*/
/*example*/

#include "bit_manipulation.h"

/*
 * left_bitwise_shift - shifts bits to the left
 *
 * Return: void
 */
void left_bitwise_shift(void)
{
	int x, result;

	x = 5;
	result = x << 1;

	printf("%d\n", result);  /* Output: 10*/
}

/*Right Bitwise Shift (>>)*/
/*The right shift effectively divides the number by 2^n (where n is the number of positions shifted).*/
/*example*/

/*
 * right_bitwise_shift - shifts bits to the right
 *
 * Return: void
 */
void right_bitwise_shift(void)
{
	int y, result;

	y = 16;
	result = y >> 2;

	printf("%d\n", result);  /* Output: 4*/
}

/*
 * displayBinaryClock - displays a simulation of a binary clock
 * @hours: hours
 * @minutes: mins
 * @seconds: seconds
 *
 * Return: void
 */
void displayBinaryClock(int hours, int minutes, int seconds)
{
	int i;

	printf("Binary Clock: %02d:%02d:%02d\n", hours, minutes, seconds);

	/*Display hours*/
	printf("Hours:   ");
	for (i = 5; i >= 0; --i)
		printf("%d", (hours >> i) & 1);
	printf("\n");

	/*Display minutes*/
	printf("Minutes: ");
	for (i = 5; i >= 0; --i)
		printf("%d", (minutes >> i) & 1);
	printf("\n");

	/*Display seconds*/
	printf("Seconds: ");
	for (i = 5; i >= 0; --i)
		printf("%d", (seconds >> i) & 1);
	printf("\n\n");
}
