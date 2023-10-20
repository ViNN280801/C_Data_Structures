#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>

/// @brief Structure to represent a node of the Red-Black Tree
typedef struct Node_t Node;

/// @brief Structure to represent the Red-Black Tree
typedef struct RedBlackTree_t RedBlackTree;

/**
 * @brief Initialize a new Red-Black Tree
 * @return A pointer to the initialized Red-Black Tree
 */
RedBlackTree *initRedBlackTree();

/**
 * @brief Insert a node into the Red-Black Tree
 * @param tree A pointer to the Red-Black Tree
 * @param data The data to insert into the tree
 */
void insert(RedBlackTree *tree, int data);

/**
 * @brief Search for a node in the Red-Black Tree
 * @param tree A pointer to the Red-Black Tree
 * @param data The data to search for
 * @return True if the data is found, otherwise false
 */
bool search(RedBlackTree *tree, int data);

/**
 * @brief Delete a node from the Red-Black Tree
 * @param tree A pointer to the Red-Black Tree
 * @param data The data to delete from the tree
 */
void deleteNode(RedBlackTree *tree, int data);

/**
 * @brief Display the Red-Black Tree in order
 * @param tree A pointer to the Red-Black Tree
 */
void inOrderTraverse(RedBlackTree *tree);

/**
 * @brief Perform a pre-order traversal of the Red Black Tree
 * @param tree Pointer to the Red Black Tree
 */
void preOrderTraverse(RedBlackTree *tree);

/**
 * @brief Perform a post-order traversal of the Red Black Tree
 * @param tree Pointer to the Red Black Tree
 */
void postOrderTraverse(RedBlackTree *tree);

/**
 * @brief Finder of minimal value in the Red Black Tree
 * @param tree Pointer to the Red Black Tree
 * @return Minimal value
 */
int minVal(RedBlackTree *tree);

/**
 * @brief Finder of maximal value in the Red Black Tree
 * @param tree Pointer to the Red Black Tree
 * @return Maximal value
 */
int maxVal(RedBlackTree *tree);

/**
 * @brief Get the size of the Red-Black Tree
 * @param tree A pointer to the Red-Black Tree
 * @return The size of the tree
 */
int size(RedBlackTree *tree);

/**
 * @brief Destroy the Red-Black Tree and free memory
 * @param tree A pointer to the Red-Black Tree
 */
void destroyRedBlackTree(RedBlackTree *tree);

#endif // !RED_BLACK_TREE_H
