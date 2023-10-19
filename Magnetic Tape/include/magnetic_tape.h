#ifndef MAGNETIC_TAPE_H
#define MAGNETIC_TAPE_H

#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>

#define DEFAULT_TAPE_BLOCK_SIZE 512

/// @brief Struct that describes the Magnetic Tape
typedef struct MagneticTape_t MagneticTape;

/**
 * @brief Initialize a new magnetic tape with a specified capacity
 * @param tape Pointer to the magnetic tape
 * @param capacity Maximum capacity of the magnetic tape
 * @return Ptr to allocated tape
 */
MagneticTape *initMagneticTape(size_t capacity);

/**
 * @brief Write a block of data to the magnetic tape
 * @param tape Pointer to the magnetic tape
 * @param data Data to be written to the block
 */
void writeBlock(MagneticTape *tape, const uint8_t data[DEFAULT_TAPE_BLOCK_SIZE]);

/**
 * @brief Read a block of data from the magnetic tape
 * @param tape Pointer to the magnetic tape
 * @param data Buffer to store the read data
 * @return True if a block was successfully read, false if the tape is empty
 */
bool readBlock(MagneticTape *tape, uint8_t data[DEFAULT_TAPE_BLOCK_SIZE]);

/**
 * @brief Prints all blocks of the tape
 * @param tape Pointer to the magnetic tape
 * @param format format to print
 */
void printTape(MagneticTape *tape, const char *restrict format);

/**
 * @brief Free the entire magnetic tape and release allocated memory
 * @param tape Pointer to the magnetic tape to be destroyed
 */
void destroyMagneticTape(MagneticTape *tape);

#endif // !MAGNETIC_TAPE_H
