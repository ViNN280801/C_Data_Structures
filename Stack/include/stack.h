#ifndef STACK_H
#define STACK_H

#define EMPTY_VALUE -1

/// @brief Structure to represent the stack
typedef struct Stack_t Stack;

/**
 * @brief Initialize a new stack with a specified capacity
 * @param capacity Maximum capacity of the stack
 * @return A pointer to the initialized stack
 */
Stack *initStack(int capacity);

/**
 * @brief Check if the stack is empty
 * @param stack Pointer to the stack
 * @return True if the stack is empty; otherwise, false
 */
bool isEmpty(Stack *stack);

/**
 * @brief Check if the stack is full
 * @param stack Pointer to the stack
 * @return True if the stack is full; otherwise, false
 */
bool isFull(Stack *stack);

/**
 * @brief Push an item onto the stack
 * @param stack Pointer to the stack
 * @param item Item to be pushed onto the stack
 */
void push(Stack *stack, int item);

/**
 * @brief Pop the top item from the stack
 * @param stack Pointer to the stack
 * @return The popped item or -1 if the stack is empty
 */
int pop(Stack *stack);

/**
 * @brief Get the top item without removing it from the stack
 * @param stack Pointer to the stack
 * @return The top item or -1 if the stack is empty
 */
int peek(Stack *stack);

/**
 * @brief Getter for size of the stack
 * @return Size of the stack (count of elements)
 */
int size(Stack *stack);

/**
 * @brief Getter for capacity of the stack
 * @return Capacity of the stack (reserved count of elements in the stack)
 */
int capacity(Stack *stack);

/**
 * @brief Destroy the stack and free allocated memory
 * @param stack Pointer to the stack to be destroyed
 */
void destroyStack(Stack *stack);

#endif // !STACK_H
