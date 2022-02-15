/************************************************************** * Class: CSC-615-01 Spring 2020
* Name: Nathan Fain
* Student ID: 922295956
* Github ID: NathanFAIN
* Project: Assignment 1 - Traffic Light
* File: main.c
*
* Description:
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

// I/O access
volatile unsigned int *gpio;

// GPIO setup macros. Always use INP_GPIO(x) before using OUT_GPIO(x) or SET_GPIO_ALT(x,y)
#define INP_GPIO(g) *(gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio+((g)/10)) |=  (1<<(((g)%10)*3))
#define SET_GPIO_ALT(g,a) *(gpio+(((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))

#define GPIO_SET *(gpio+7)  // sets   bits which are 1 ignores bits which are 0
#define GPIO_CLR *(gpio+10) // clears bits which are 1 ignores bits which are 0

#define GPIO_PULL *(gpio+37) // Pull up/pull down
#define GPIO_PULLCLK0 *(gpio+38) // Pull up/pull down clock

void setup_io()
{
    int  fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        printf("can't open /dev/mem \n");
        exit(-1);
    }

    void *gpio_map = mmap(
        NULL,             //Any adddress in our space will do
        BLOCK_SIZE,       //Map length
        PROT_READ|PROT_WRITE,// Enable reading & writting to mapped memory
        MAP_SHARED,       //Shared with other processes
        fd,           //File to map
        GPIO_BASE         //Offset to GPIO peripheral
    );

    close(fd);

    if (gpio_map == MAP_FAILED) {
        printf("mmap error %d\n", (int)(long)gpio_map);//errno also set!
        exit(-1);
    }

    gpio = (volatile unsigned *)gpio_map;
}

int main(void)
{
    setup_io();

    // Set GPIO pins 7-11 to output
    for (int pin = 7; pin <=11; pin++) {
        INP_GPIO(pin); // must use INP_GPIO before we can use OUT_GPIO
        OUT_GPIO(pin);
    }

    for (size_t index = 0; index < 10; index++) {
        for (int pin = 7; pin <= 11; pin++) {
            GPIO_SET = 1 << pin;
        }
        sleep(1);
        for (int pin = 7; pin <= 11; pin++) {
            GPIO_CLR = 1 << pin;
        }
        sleep(1);
    }

  return (0);

}