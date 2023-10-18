#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "../include/binary_search_tree.h"

struct TreeNode
{
    int data;        // Data that node stores
    TreeNode *left;  // Ptr to the left child
    TreeNode *right; // Ptr to the right child
};

struct BinarySearchTree
{
    TreeNode *root; // Ptr to the main node - root node of the Binary Tree
    size_t size;    // Count of elements
};

BinarySearchTree *initBinarySearchTree()
{
    BinarySearchTree *tree = (BinarySearchTree *)calloc(1, sizeof(BinarySearchTree));
    if (!tree)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

bool isEmpty(BinarySearchTree *tree) { return tree->size == 0; }

static TreeNode *createTreeNode(int data)
{
    TreeNode *node = (TreeNode *)calloc(1, sizeof(TreeNode));
    if (!node)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static void insertNode(TreeNode **root, int data)
{
    if (!*root)
        *root = createTreeNode(data);
    else if (data < (*root)->data)
        insertNode(&(*root)->left, data);
    else if (data > (*root)->data)
        insertNode(&(*root)->right, data);
}

void insert(BinarySearchTree *tree, int data)
{
    insertNode(&(tree->root), data);
    tree->size++;
}

static TreeNode *findMinHelper(TreeNode *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

int findMin(BinarySearchTree *tree) { return findMinHelper(tree->root)->data; }

static TreeNode *findMaxHelper(TreeNode *node)
{
    while (node->right != NULL)
        node = node->right;
    return node;
}

int findMax(BinarySearchTree *tree) { return findMaxHelper(tree->root)->data; }

static TreeNode *deleteNodeHelper(TreeNode *root, int data)
{
    if (!root)
        return root;

    if (data < root->data)
        root->left = deleteNodeHelper(root->left, data);
    else if (data > root->data)
        root->right = deleteNodeHelper(root->right, data);
    else
    {
        if (!root->left)
        {
            TreeNode *temp = root->right;
            if (root)
                free(root);
            root = NULL;
            return temp;
        }
        else if (!root->right)
        {
            TreeNode *temp = root->left;
            if (root)
                free(root);
            root = NULL;
            return temp;
        }

        TreeNode *temp = findMinHelper(root->right);
        root->data = temp->data;
        root->right = deleteNodeHelper(root->right, temp->data);
    }
    return root;
}

void deleteNode(BinarySearchTree *tree, int data)
{
    tree->root = deleteNodeHelper(tree->root, data);
    if (tree->root)
        tree->size--;
}

static int searchNode(TreeNode *root, int data)
{
    if (!root)
        return EMPTY_VALUE;
    if (root->data == data)
        return 0;
    else if (data < root->data)
    {
        int result = searchNode(root->left, data);
        return result >= 0 ? result + 1 : EMPTY_VALUE;
    }
    else
    {
        int result = searchNode(root->right, data);
        return result >= 0 ? result + 1 : EMPTY_VALUE;
    }
}

int search(BinarySearchTree *tree, int data) { return searchNode(tree->root, data); }

static void displayInOrderNode(TreeNode *root)
{
    if (root)
    {
        displayInOrderNode(root->left);
        printf("%d ", root->data);
        displayInOrderNode(root->right);
    }
}

void displayInOrder(BinarySearchTree *tree)
{
    displayInOrderNode(tree->root);
    printf("\n");
}

static void preOrderTraversal(TreeNode *node)
{
    if (node)
    {
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void displayPreOrder(BinarySearchTree *tree)
{
    if (isEmpty(tree))
    {
        printf("Binary Search Tree is empty\n");
        return;
    }
    preOrderTraversal(tree->root);
    printf("\n");
}

static void postOrderTraversal(TreeNode *node)
{
    if (node)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("%d ", node->data);
    }
}

void displayPostOrder(BinarySearchTree *tree)
{
    if (isEmpty(tree))
    {
        printf("Binary Search Tree is empty\n");
        return;
    }
    postOrderTraversal(tree->root);
    printf("\n");
}

static void destroyTree(TreeNode *root)
{
    if (!root)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    if (root)
        free(root);
    root = NULL;
}

void destroyBinarySearchTree(BinarySearchTree *tree)
{
    destroyTree(tree->root);
    if (tree)
        free(tree);
    tree = NULL;
}
