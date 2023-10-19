#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

#include "../include/magnetic_tape.h"

int main()
{
    srand((unsigned long)time(NULL));

    MagneticTape *tape = initMagneticTape(10);

    for (int i = 0; i < 10; i++)
    {
        uint8_t data[DEFAULT_TAPE_BLOCK_SIZE];
        for (int j = 0; j < DEFAULT_TAPE_BLOCK_SIZE; j++)
            data[j] = (uint8_t)(rand() % 256);
        writeBlock(tape, data);
    }

    // First approach of print all tape that not delete blocks
    printTape(tape, "0x%02X\t");

    // Second approach of print all tape that delete block by block
    uint8_t readData[DEFAULT_TAPE_BLOCK_SIZE];
    while (readBlock(tape, readData))
    {
        printf("Read:\n");
        for (int i = 0; i < DEFAULT_TAPE_BLOCK_SIZE; i++)
            printf("%lld\t", (long long)readData[i]);
        printf("\n");
    }

    destroyMagneticTape(tape);

    return 0;
}
