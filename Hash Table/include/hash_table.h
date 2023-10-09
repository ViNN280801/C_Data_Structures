#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define DEFAULT_CAPACITY 100 // Default capacity of the hash table
#define EMPTY_VALUE -1       // Key -1 indicates an empty slot

// Structure for the hash table
typedef struct HashTable_t HashTable;

/**
 * @brief Initialize a new hash table with the default capacity
 * Allocates memory for a new hash table and initializes it with the default capacity
 * @return A pointer to the initialized hash table
 */
HashTable *init_hash_table();

/**
 * @brief Resize the hash table to the new specified capacity
 * This function resizes the hash table to the specified new capacity, rehashing the elements
 * @param hashTable Pointer to the hash table to be resized
 * @param new_capacity The new capacity for the hash table
 */
void resize_hash_table(HashTable *hashTable, int new_capacity);

/**
 * @brief Compute the hash value for a given key using the division method
 *
 * This function computes the hash value for a given key based on the specified capacity
 *
 * @param key The key to be hashed
 * @param capacity The capacity of the hash table
 * @return The computed hash value
 */
int hash(int key, int capacity);

/**
 * @brief Insert a key-value pair into the hash table
 * @param hashTable Pointer to the hash table
 * @param key The key to insert
 * @param value The corresponding value to be associated with the key
 */
void insert(HashTable *hashTable, int key, int value);

/**
 * @brief Search for a key in the hash table
 * Searches for a key in the hash table and returns the associated value.
 * It also counts the number of comparisons made during the search
 * @param hashTable Pointer to the hash table
 * @param key The key to search for
 * @param comparisons Pointer to store the number of comparisons made
 * @return The value associated with the key, or EMPTY_VALUE if not found
 */
int search(HashTable *hashTable, int key, int *comparisons);

/**
 * @brief Get the current size (number of elements) of the hash table
 * @param hashTable Pointer to the hash table
 * @return The size of the hash table
 */
int size(HashTable *hashTable);

/**
 * @brief Gets the current capacity (maximum number of elements) of the hash table
 * @param hashTable Pointer to the hash table
 * @return The capacity of the hash table
 */
int capacity(HashTable *hashTable);

/**
 * @brief Deletes a key from the hash table
 * @param hashTable Pointer to the hash table
 * @param key The key to be deleted
 */
void delete_key(HashTable *hashTable, int key);

/**
 * @brief Prints all elements from the hash table to the terminal
 * @param hashTable Pointer to the hash table to be printed
 */
void print_hash_table(HashTable *hashTable);

/**
 * @brief Cleans up and free memory associated with the hash table
 * Frees the memory allocated for the hash table and its elements
 * @param hashTable Pointer to the hash table to be destroyed
 */
void destroy_hash_table(HashTable *hashTable);

#endif // !HASH_TABLE_H
