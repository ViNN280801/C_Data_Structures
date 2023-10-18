#include <stdio.h>

#include "../include/binary_search_tree.h"

int main()
{
    BinarySearchTree *tree = initBinarySearchTree();

    // Check if the tree is initially empty
    if (isEmpty(tree))
        printf("Binary Search Tree is initially empty\n");
    else
        printf("Error: Binary Search Tree is not empty initially\n");

    // Insert elements into the tree
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 3);
    insert(tree, 7);
    insert(tree, 12);
    insert(tree, 18);

    // Display elements in different traversal orders
    printf("In-order traversal: ");
    displayInOrder(tree);
    printf("Pre-order traversal: ");
    displayPreOrder(tree);
    printf("Post-order traversal: ");
    displayPostOrder(tree);

    // Search for elements in the tree
    int searchData = 12,
        position = search(tree, searchData);
    if (position >= 0)
        printf("%d found at position %d in the tree\n", searchData, position);
    else
        printf("%d not found in the tree\n", searchData);

    // Delete elements from the tree
    int deleteData = 15;
    deleteNode(tree, deleteData);
    printf("Deleted %d from the tree\n", deleteData);

    printf("Min element = %d\n", findMin(tree));
    printf("Max element = %d\n", findMax(tree));

    // Display the tree after deletion
    printf("In-order traversal after deletion: ");
    displayInOrder(tree);

    // Destroy the tree and free allocated memory
    destroyBinarySearchTree(tree);

    return 0;
}
