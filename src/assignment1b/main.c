/************************************************************** * Class: CSC-615-01 Spring 2020
* Name: Nathan Fain
* Student ID: 922295956
* Github ID: NathanFAIN
* Project: Assignment 1 - Traffic Light
* File: main.c
*
* Description: Code for the assignment1b program.
* **************************************************************/


#include "tools.h"

#define BCM2708_PERI_BASE   0x20000000
#define GPIO_BASE           (BCM2708_PERI_BASE + 0x200000)
#define BLOCK_SIZE          (4 * 1024)

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

volatile unsigned int *gpio;

#define INP_GPIO(g) *(gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio+((g)/10)) |=  (1<<(((g)%10)*3))

#define GPIO_SET *(gpio+7)
#define GPIO_CLR *(gpio+10)

typedef enum pin_value_s {
    LOW,
    HIGH
} pin_value_t;

#define RED_PIN 16
#define ORANGE_PIN 20
#define GREEN_PIN 21

void setup_io(void)
{
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        fprintf(stderr, "can't open /dev/mem\n");
        exit(-1);
    }

    void *gpio_map = mmap(
        NULL,
        BLOCK_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        fd,
        GPIO_BASE
    );

    close(fd);

    if (gpio_map == MAP_FAILED) {
        fprintf(stderr, "mmap error : %s\n", strerror(errno));
        exit(-1);
    }

    gpio = (volatile unsigned *)gpio_map;
}

void init_pin(unsigned int pin)
{
    INP_GPIO(pin);
    OUT_GPIO(pin);
}

void digital_write(unsigned int pin, pin_value_t value)
{
    if (value == HIGH) {
        GPIO_SET = 1 << pin;
    } else if (value == LOW) {
        GPIO_CLR = 1 << pin;
    }
}

int main(void)
{
    setup_io();
    init_pin(RED_PIN);
    init_pin(ORANGE_PIN);
    init_pin(GREEN_PIN);
    for (size_t index = 0; index < 3; index++) {
        digital_write(GREEN_PIN, HIGH);
        usleep(6000000);
        digital_write(GREEN_PIN, LOW);
        digital_write(ORANGE_PIN, HIGH);
        usleep(1500000);
        digital_write(ORANGE_PIN, LOW);
        digital_write(RED_PIN, HIGH);
        usleep(5000000);
        digital_write(RED_PIN, LOW);
    }
    return (0);
}