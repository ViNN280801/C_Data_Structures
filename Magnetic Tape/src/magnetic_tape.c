#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/magnetic_tape.h"

struct TapeBlock
{
    uint8_t data[DEFAULT_TAPE_BLOCK_SIZE]; // Data storage in the block
    struct TapeBlock *next;                // Ptr to the next tape block
};

struct MagneticTape_t
{
    struct TapeBlock *head; // Ptr to the head of the tape
    struct TapeBlock *tail; // Ptr to the head of the tail
    size_t size;            // Current count of elements in the tape
    size_t capacity;        // Reserved space in the tape
};

MagneticTape *initMagneticTape(size_t capacity)
{
    MagneticTape *tape = (MagneticTape *)calloc(1, sizeof(MagneticTape));
    if (!tape)
    {
        fprintf(stderr, "Memory allocation for MagneticTape object failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    tape->head = NULL;
    tape->tail = NULL;
    tape->size = 0;
    tape->capacity = capacity;

    return tape;
}

void writeBlock(MagneticTape *tape, const uint8_t data[DEFAULT_TAPE_BLOCK_SIZE])
{
    if (tape->size >= tape->capacity)
    {
        fprintf(stderr, "Magnetic tape is full. Cannot write more data: %s\n", strerror(errno));
        return;
    }

    struct TapeBlock *newBlock = (struct TapeBlock *)calloc(1, sizeof(struct TapeBlock));
    if (!newBlock)
    {
        fprintf(stderr, "Memory allocation for TapeBlock failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memcpy(newBlock->data, data, sizeof(newBlock->data));
    newBlock->next = NULL;

    if (!tape->tail)
    {
        tape->head = newBlock;
        tape->tail = newBlock;
    }
    else
    {
        tape->tail->next = newBlock;
        tape->tail = newBlock;
    }

    tape->size++;
    tape->capacity = tape->size * 2;
}

bool readBlock(MagneticTape *tape, uint8_t data[DEFAULT_TAPE_BLOCK_SIZE])
{
    if (tape->size == 0)
    {
        fprintf(stderr, "Magnetic tape is empty. Cannot read data\n");
        return false;
    }

    struct TapeBlock *block = tape->head;
    for (int i = 0; i < DEFAULT_TAPE_BLOCK_SIZE; i++)
        data[i] = block->data[i];
    tape->head = block->next;

    if (block)
        free(block);
    block = NULL;

    tape->size--;
    tape->capacity = tape->size * 2;

    return true;
}

void printTape(MagneticTape *tape, const char *restrict format)
{
    struct TapeBlock *current = tape->head;
    while (current)
    {
        for (int i = 0; i < DEFAULT_TAPE_BLOCK_SIZE; i++)
            printf(format, current->data[i]);
        printf("\n");

        current = current->next;
    }
    if (current)
        free(current);
    current = NULL;
}

void destroyMagneticTape(MagneticTape *tape)
{
    struct TapeBlock *current = tape->head;
    while (current)
    {
        struct TapeBlock *temp = current;
        current = current->next;
        if (temp)
            free(temp);
        temp = NULL;
    }

    tape->head = NULL;
    tape->tail = NULL;
    tape->size = 0;
    tape->capacity = 0;

    if (current)
        free(current);
    current = NULL;

    if (tape)
        free(tape);
    tape = NULL;
}
