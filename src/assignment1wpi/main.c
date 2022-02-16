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

#define RED_PIN 27
#define ORANGE_PIN 28
#define GREEN_PIN 29

int main(void)
{
    wiringPiSetup();
    pinMode(RED_PIN, OUTPUT);
    pinMode(ORANGE_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    for (size_t index = 0; index < 2; index++) {
        digitalWrite(GREEN_PIN, HIGH);
        delay(6000);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(ORANGE_PIN, HIGH);
        delay(1500);
        digitalWrite(ORANGE_PIN, LOW);
        digitalWrite(RED_PIN, HIGH);
        delay(5000);
        digitalWrite(RED_PIN, LOW);
    }
    return(0);
}