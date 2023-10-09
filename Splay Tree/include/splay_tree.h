#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

// Struct for the nodes in the splay-tree
typedef struct Node_t Node;

// Splay-tree structure, which includes a pointer to the root node
typedef struct SplayTree_t SplayTree;

/**
 * @brief Initialize a new splay-tree
 * @return A pointer to the initialized splay-tree
 */
SplayTree *init_splay_tree();

/**
 * @brief Create a new node with the given key value
 * @param key The key value for the new node
 * @return A pointer to the new node
 */
Node *create_node(int key);

/**
 * @brief Insert a new node with the given key into the splay-tree
 * @param tree Pointer to the splay-tree
 * @param key Key to be inserted into the tree
 */
void insert(SplayTree *tree, int key);

/**
 * @brief Perform an in-order traversal of the splay-tree, starting from the specified root
 * @param tree Pointer to the splay-tree
 */
void in_order_traverse(SplayTree *tree);

/**
 * @brief Perform a pre-order traversal of the splay-tree, starting from the specified root
 * @param tree Pointer to the splay-tree
 */
void pre_order_traverse(SplayTree *tree);

/**
 * @brief Perform a post-order traversal of the splay-tree, starting from the specified root
 * @param tree Pointer to the splay-tree
 */
void post_order_traverse(SplayTree *tree);

/**
 * @brief Search for a node with the given key
 * @param tree Pointer to the splay-tree
 * @param key Key to search for
 * @param comparisons Pointer to an integer to store the number of comparisons made
 * @return A pointer to the found node, or NULL if the key is not found
 */
Node *search(SplayTree *tree, int key, int *comparisons);

/**
 * @brief Calculate the memory usage of the splay tree
 * @param tree Pointer to the splay-tree
 * @return The memory usage in bytes
 */
size_t splay_tree_memory_usage(SplayTree *tree);

/**
 * @brief Destroy the splay-tree object and free associated memory
 * @param tree Pointer to the splay-tree to destroy
 */
void destroy_splay_tree(SplayTree *tree);

#endif // !SPLAY_TREE_H
