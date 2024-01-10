/*DAY 7 of 31*/
/*Bitwise Rotation*/

/*Bitwise rotation is an operation that shifts the bits of a
 * binary number to the left or right, and wraps the shifted bits around the number.
 * Also known as a circular shift 
 *  the bits that are shifted out from one end are brought back to the other end.
 */

/*Left Bitwise Rotation (<<):*/
/*bits are shifted to the left, and the bits that are shifted out from
the leftmost side are brought back to the rightmost side*/

/*
 * leftRotate - rotates bits to the left
 * @value: the binary number
 * @n: number of positions to rotate
 *
 * Return: the shifted binary no
 */
unsigned int leftRotate(unsigned int value, int n)
{
	return ((value << n) | (value >> (32 - n)));
}

/*Right Bitwise Rotation*/

/**
 * rightRotate - Perform bitwise right rotation on a 32-bit unsigned integer.
 * @value: The input unsigned integer to be rotated.
 * @n: The number of positions to rotate.
 *
 * Return: The result after right rotation.
 */
unsigned int rightRotate(unsigned int value, int n)
{
    /* Assuming 32-bit integers */
    /* Shift right by n positions and use bitwise OR to bring in the rotated bits */
    return (value >> n) | (value << (32 - n));
}

/*Creating a Hashing Function using left bitwise rotation*/
/**
 * hashFunction - Perform a basic bitwise hashing on an unsigned integer key.
 * @key: The input key to be hashed.
 *
 * Return: The resulting hash value.
 */
unsigned int hashFunction(unsigned int key)
{
	/* Perform a basic bitwise hashing using left rotation */
        return ((key << 5) | (key >> 27));  /*Rotate left by 5 positions*/
}

/*Configuring GPIO Pins in a Microcontroller using right bitwise rotation*/
/**
 * configurePinAsOutput - Configure a specific pin as an output in a GPIO configuration register.
 * @configRegister: The GPIO configuration register.
 * @pinNumber: The number of the pin to be configured.
 *
 * Return: The updated GPIO configuration register.
 */
unsigned int configurePinAsOutput(unsigned int configRegister, int pinNumber)
{
	return configRegister | (1 << pinNumber);
}
