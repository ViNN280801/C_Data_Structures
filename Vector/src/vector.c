#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "../include/vector.h"

struct Vector_t
{
    int *array;   // Ptr to array
    int size;     // Current size of the array
    int capacity; // Maximum count of elements (reserved space)
};

Vector *initVector(int capacity)
{
    Vector *vector = (Vector *)calloc(1, sizeof(Vector));
    if (!vector)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    vector->array = (int *)calloc(capacity, sizeof(int));
    if (!vector->array)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    vector->size = 0;
    vector->capacity = capacity;
    return vector;
}

bool isEmpty(Vector *vector) { return vector->size == 0; }

bool resize(Vector *vector, int newCapacity)
{
    int *newArray = (int *)realloc(vector->array, newCapacity * sizeof(int));
    if (!newArray)
        return false; // Resize failed

    vector->array = newArray;
    vector->capacity = newCapacity;
    return true;
}

bool push_back(Vector *vector, int value)
{
    if (vector->size == vector->capacity)
    {
        // Resize the vector when capacity is reached
        size_t newCapacity = (vector->capacity * 2);
        if (!resize(vector, newCapacity))
        {
            fprintf(stderr, "Can't add more space to vector: %s\n", strerror(errno));
            return false; // Resize failed
        }
    }

    vector->array[vector->size] = value;
    vector->size++;
    return true; // Successfully inserted element to the end of the vector
}

bool insert(Vector *vector, int value, int index)
{
    if (index > vector->size)
    {
        fprintf(stderr, "Index out of bounds: %s\n", strerror(errno));
        return false;
    }

    if (vector->size == vector->capacity)
    {
        // Resize the vector when capacity is reached
        size_t newCapacity = (vector->capacity * 2);
        if (!resize(vector, newCapacity))
        {
            fprintf(stderr, "Can't add more space to vector: %s\n", strerror(errno));
            return false; // Resize failed
        }
    }

    // Shift elements to make space for the new value
    for (int i = vector->size; i > index; i--)
        vector->array[i] = vector->array[i - 1];

    vector->array[index] = value;
    vector->size++;
    return true; // Successfully inserted element at the specified position
}

int get(Vector *vector, int index)
{
    if (index < 0 || index >= vector->size)
        return EMPTY_VALUE; // Index out of bounds or vector is empty
    return vector->array[index];
}

int size(Vector *vector) { return vector->size; }

int capacity(Vector *vector) { return vector->capacity; }

int *data(Vector *vector) { return vector->array; }

void print(Vector *vector)
{
    for (int i = 0; i < vector->size; i++)
        printf("%d ", vector->array[i]);
    printf("\n");
}

void destroyVector(Vector *vector)
{
    vector->size = 0;
    vector->capacity = 0;

    if (vector)
    {
        if (vector->array)
        {
            free(vector->array);
            vector->array = NULL;
        }
        free(vector);
        vector = NULL;
    }
}
