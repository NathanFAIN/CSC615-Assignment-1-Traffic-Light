/************************************************************** * Class: CSC-615-01 Spring 2020
* Name: Nathan Fain
* Student ID: 922295956
* Github ID: NathanFAIN
* Project: Assignment 1 - Traffic Light
* File: main.c
*
* Description:
* **************************************************************/


#include <stdio.h>
#include <wiringPi.h>
#include "tools.h"

int main(UNUSED int ac, UNUSED char **av, UNUSED char **env)
{
    wiringPiSetup();
    pinMode(0, OUTPUT);
    while (1) {
        digitalWrite(0, HIGH);
        delay(500);
        digitalWrite(0, LOW);
        delay(500);
    }
    return (0);
}