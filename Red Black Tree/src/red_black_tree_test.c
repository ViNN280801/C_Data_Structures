#include <stdio.h>

#include "../include/red_black_tree.h"

int main()
{
    RedBlackTree *tree = initRedBlackTree();

    int values[] = {7, 3, 18, 10, 22, 8, 11, 26};
    int numValues = sizeof(values) / sizeof(values[0]);

    // Insert values into the tree
    for (int i = 0; i < numValues; i++)
        insert(tree, values[i]);

    printf("In-order traversal:\n");
    inOrderTraverse(tree);

    printf("Pre-order traversal:\n");
    preOrderTraverse(tree);

    printf("Post-order traversal:\n");
    postOrderTraverse(tree);

    int searchData = 10;
    if (search(tree, searchData))
        printf("%d found in the tree\n", searchData);
    else
        printf("%d not found in the tree\n", searchData);

    printf("Count of elements before deletion: %d\n", size(tree));

    int deleteData = 18;
    deleteNode(tree, deleteData);
    printf("After deleting %d:\n", deleteData);

    printf("Count of elements after deletion: %d\n", size(tree));

    inOrderTraverse(tree);

    printf("Min value: %d\n", minVal(tree));
    printf("Max value: %d\n", maxVal(tree));

    destroyRedBlackTree(tree);

    return 0;
}
