#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>

#define EMPTY_VALUE -1

/// @brief Structure to represent a node in the Binary Search Tree
typedef struct TreeNode TreeNode;

/// @brief Structure to represent the Binary Search Tree
typedef struct BinarySearchTree BinarySearchTree;

/**
 * @brief Initialize a new Binary Search Tree
 * @return A pointer to the initialized Binary Search Tree
 */
BinarySearchTree *initBinarySearchTree();

/**
 * @brief Check if the Binary Search Tree is empty
 * @param tree Pointer to the Binary Search Tree
 * @return True if the tree is empty; otherwise, false
 */
bool isEmpty(BinarySearchTree *tree);

/**
 * @brief Insert a new element into the Binary Search Tree
 * @param tree Pointer to the Binary Search Tree
 * @param data Data to be inserted
 */
void insert(BinarySearchTree *tree, int data);

/**
 * @brief Finder for min element in the tree
 * @param tree Pointer to the Binary Search Tree
 * @return Minimal element in the Binary Search Tree
 */
int findMin(BinarySearchTree *tree);

/**
 * @brief Finder for max element in the tree
 * @param tree Pointer to the Binary Search Tree
 * @return Maximal element in the Binary Search Tree
 */
int findMax(BinarySearchTree *tree);

/**
 * @brief Delete a specific element from the Binary Search Tree
 * @param tree Pointer to the Binary Search Tree
 * @param data Data to be deleted
 */
void deleteNode(BinarySearchTree *tree, int data);

/**
 * @brief Search for a specific element in the Binary Search Tree
 * @param tree Pointer to the Binary Search Tree
 * @param data Data to be searched
 * @return Position of the data (1-based index) or -1 if not found
 */
int search(BinarySearchTree *tree, int data);

/**
 * @brief Display all elements in the Binary Search Tree in an in-order traversal
 * @param tree Pointer to the Binary Search Tree
 */
void displayInOrder(BinarySearchTree *tree);

/**
 * @brief Display all elements in the Binary Search Tree in an pre-order traversal
 * @param tree Pointer to the Binary Search Tree
 */
void displayPreOrder(BinarySearchTree *tree);

/**
 * @brief Display all elements in the Binary Search Tree in an post-order traversal
 * @param tree Pointer to the Binary Search Tree
 */
void displayPostOrder(BinarySearchTree *tree);

/**
 * @brief Destroy the Binary Search Tree and free allocated memory
 * @param tree Pointer to the Binary Search Tree to be destroyed
 */
void destroyBinarySearchTree(BinarySearchTree *tree);

#endif // !BINARY_SEARCH_TREE_H
