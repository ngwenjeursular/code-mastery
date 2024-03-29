#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#include <stdio.h>
#include <time.h>

/*Define permission flags*/
#define READ_PERMISSION  (1 << 0)
#define WRITE_PERMISSION (1 << 1)
#define EXECUTE_PERMISSION (1 << 2)

/*color masks*/
#define RED_MASK   0xFF0000
#define GREEN_MASK 0x00FF00
#define BLUE_MASK  0x0000FF

void left_bitwise_shift(void);
void right_bitwise_shift(void);

void displayBinaryClock(int hours, int minutes, int seconds);
unsigned int leftRotate(unsigned int value, int n);
unsigned int rightRotate(unsigned int value, int n);
unsigned int hashFunction(unsigned int key);
unsigned int configurePinAsOutput(unsigned int configRegister, int pinNumber);
unsigned int setBit(unsigned int num, int pos);
void printBinary(unsigned int num);
unsigned int clearBit(unsigned int num, int pos);
unsigned int toggleBit(unsigned int num, int pos);
int isBitSet(unsigned int num, int pos);
int countSetBits(unsigned int num);
int isPowerOfTwo(unsigned int num);
void swapWithoutTemp(int *a, int *b);
int findMSBPosition(unsigned int num);
int extractLowestSetBit(unsigned int num);
int hasPermission(unsigned int userPermissions, unsigned int permissionToCheck);
void grantPermission(unsigned int *userPermissions, unsigned int permissionToAdd);
void revokePermission(unsigned int *userPermissions, unsigned int permissionToRemove);

/*Bitwise manipulation in algorithms*/
int findSingleNonRepeated(int arr[], int size);
int countSetBits2(unsigned char pixel);
void processImage(unsigned char image[], int size);

void generatePowerSet(int set[], int setSize);
unsigned int decimalToGray(unsigned int num);
void printBinary2(unsigned int num, int bits);


/*Advanced bit hacks*/
int countTrailingZeros(unsigned int num);
int logBase2(unsigned int num);
unsigned int reverseBits(unsigned int num);
int countSetBitsSparse(unsigned int num);

#endif /*BIT_MANIPULATION_H*/
