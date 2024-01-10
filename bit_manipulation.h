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

#endif /*BIT_MANIPULATION_H*/
