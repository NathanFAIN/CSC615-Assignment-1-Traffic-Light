/************************************************************** * Class: CSC-615-01 Spring 2020
* Name: Nathan Fain
* Student ID: 922295956
* Github ID: NathanFAIN
* Project: Assignment 1 - Traffic Light
* File: main.c
*
* Description:
* **************************************************************/


#include <wiringPi.h>
#include "tools.h"

int main(void)
{
    wiringPiSetup();
    pinMode(27, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(29, OUTPUT);
    for (size_t index = 0; index < 2; index++) {
        digitalWrite(29, HIGH);
        delay(6000);
        digitalWrite(29, LOW);
        digitalWrite(28, HIGH);
        delay(1500);
        digitalWrite(28, LOW);
        digitalWrite(27, HIGH);
        delay(5000);
        digitalWrite(27, LOW);
    }
    return(0);
}