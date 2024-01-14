#include "bit_manipulation.h"

/*
 * main - entry point
 *
 * Return: 0 on Success
 */
int main(void)
{
	/**/
	int arr1[] = {1, 2, 3, 4};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = {8, 1, 2, 12, 7, 6};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int arr3[] = {4, 6};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	unsigned int num1, num2;
	int repeat, choice;

	printf("Output for arr1[]: %d\n", maxSubarrayXOR(arr1, n1));

	printf("Output for arr2[]: %d\n", maxSubarrayXOR(arr2, n2));
	printf("Output for arr3[]: %d\n", maxSubarrayXOR(arr3, n3));

	/*Bitwise calculator*/
	do {
		printf("Enter two integers: ");
		scanf("%u %u", &num1, &num2);

		/*Display menu*/
		printf("\n1. Bitwise AND\n");
		printf("2. Bitwise OR\n");
		printf("3. Bitwise XOR\n");
		printf("4. Exit\n");
		printf("Choose operation (1-4): ");

		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				{
					printf("Result (AND): %u\n", bitwiseAND(num1, num2));
            				break;
				}
			case 2:
				{
					printf("Result (OR): %u\n", bitwiseOR(num1, num2));
            				break;
				}
			case 3:
				{
					printf("Result (XOR): %u\n", bitwiseXOR(num1, num2));
            				break;
				}
			case 4:
				{
					printf("Exiting the program.\n");
            				return (0);
				}
			default:
				{
				        printf("Invalid choice. Please enter a valid option.\n");
        			}

		}

		/*Display binary representations*/
		printf("Binary Representation:\n");
        	displayBinary(num1);
        	displayBinary(num2);
        	displayBinary(bitwiseAND(num1, num2));

		printf("\n");
		printf("Do you want to perform another operation? (1 for yes, 0 for no): ");

		scanf("%d", &repeat);
		
		if (!repeat)
		{
			printf("Exiting the program.\n");
			return (0);
		}

	} while (1);




	return (0);
}
