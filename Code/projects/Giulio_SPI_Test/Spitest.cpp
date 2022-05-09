#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "SPI.h"
#include <Gpio.h>
#include <Utilities.h> // for OUTPUT

const int busSpeedHz = 100000;
const int csDelay = 0; // how long to delay after the last bit transfer before deselecting the device

const int wordLength = 16;
Gpio switchLatch;
Gpio ledLatch;
const int switchLatchPin = 46; //65; // P2.17
const int ledLatchPin = 44; //27; // P2.19
int switchArray[16];

int poll();

int main()
{
    switchLatch.open(switchLatchPin, OUTPUT);
    ledLatch.open(ledLatchPin, OUTPUT);

    if (SPI_DEV1_init(0, busSpeedHz, SPI_SS_LOW,
                      csDelay, wordLength,
                      SPI_MODE3) == -1)
        printf("(Main)spidev1.0 initialization failed\r\n");

    else
        printf("(Main)spidev1.0 initialized - READY\r\n");

    while (1)
    {
        if(poll())
            break;
        usleep(100000);
    }
}


int poll()
{
    switchLatch.write(1);
    switchLatch.write(0);

    uint16_t outputs = 0xff00; // assign the value you want to transmit
    uint16_t inputs;
    int transmissionLength = 2; // in bytes, wordlength is set above.
    if (SPIDEV1_transfer((unsigned char*)&outputs, (unsigned char*)&inputs, transmissionLength) == 0)
    {
        // successful SPI transfer
        ledLatch.write(1);
        ledLatch.write(0);
        for (int i = 0; i < 16; i++){
            if (inputs & (1 << i)) {
                switchArray[i] = 1;
            }
            else {
                switchArray[i] = 0;
            }
        }

        printf("(Main)spidev1.0: Transaction Complete. Sent %d bytes, received: %#04x\n", transmissionLength, inputs);
        return 0;
    } else {
        fprintf(stderr, "(Main)spidev1.0: Transaction Failed\r\n");
        return 1;
    }
}
