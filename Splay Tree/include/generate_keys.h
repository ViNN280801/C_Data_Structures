#ifndef GENERATE_KEYS_H
#define GENERATE_KEYS_H

// Define the maximum number of keys to generate
#define MAX_KEYS_COUNT 100

/**
 * @brief Generates keys for the test set
 * This function populates the given array with test keys
 * @param test_keys Pointer to an array where test keys will be stored
 */
void generate_test_keys(int *test_keys);

/**
 * @brief Shuffles the elements in the given array
 * This function randomly reorders the elements within the array
 * @param array Pointer to the array to be shuffled
 * @param size Size of the array
 */
void shuffle(int *array, int size);

#endif // !GENERATE_KEYS_H