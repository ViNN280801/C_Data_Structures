#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/red_black_tree.h"

typedef enum COLOR
{
    RED,
    BLACK
} color_t;

struct Node_t
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
    color_t color;
};

struct RedBlackTree_t
{
    Node *root;
    int size;
};

RedBlackTree *initRedBlackTree()
{
    RedBlackTree *tree = (RedBlackTree *)calloc(1, sizeof(RedBlackTree));
    if (!tree)
    {
        fprintf(stdout, "Can't allocate memory for the Red Black Tree: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    if (!newNode)
    {
        fprintf(stdout, "Can't allocate memory for the node of the Red Black Tree: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->color = RED;
    return newNode;
}

void leftRotate(RedBlackTree *tree, Node *temp)
{
    Node *right = temp->right;
    temp->right = right->left;
    if (temp->right)
        temp->right->parent = temp;
    right->parent = temp->parent;
    if (!temp->parent)
        tree->root = right;
    else if (temp == temp->parent->left)
        temp->parent->left = right;
    else
        temp->parent->right = right;
    right->left = temp;
    temp->parent = right;
}

void rightRotate(RedBlackTree *tree, Node *temp)
{
    Node *left = temp->left;
    temp->left = left->right;
    if (temp->left)
        temp->left->parent = temp;
    left->parent = temp->parent;
    if (!temp->parent)
        tree->root = left;
    else if (temp == temp->parent->left)
        temp->parent->left = left;
    else
        temp->parent->right = left;
    left->right = temp;
    temp->parent = left;
}

Node *BST(Node *trav, Node *temp)
{
    if (!trav)
        return temp;

    if (temp->data < trav->data)
    {
        trav->left = BST(trav->left, temp);
        trav->left->parent = trav;
    }
    else if (temp->data > trav->data)
    {
        trav->right = BST(trav->right, temp);
        trav->right->parent = trav;
    }

    return trav;
}

void fixup(RedBlackTree *tree, Node *pt)
{
    Node *parent_pt = NULL,
         *grand_parent_pt = NULL;

    while (pt != tree->root && pt->color == RED && pt->parent->color == RED)
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left)
        {
            Node *uncle_pt = grand_parent_pt->right;

            if (uncle_pt && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->right)
                {
                    pt = parent_pt;
                    leftRotate(tree, pt);
                    parent_pt = pt->parent;
                }

                rightRotate(tree, grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }
        else
        {
            Node *uncle_pt = grand_parent_pt->left;

            if (uncle_pt && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->left)
                {
                    pt = parent_pt;
                    rightRotate(tree, pt);
                    parent_pt = pt->parent;
                }

                leftRotate(tree, grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }
    }

    tree->root->color = BLACK;
}

void insert(RedBlackTree *tree, int data)
{
    Node *newNode = createNode(data);

    if (!tree->root)
    {
        // If the tree is empty, the new node becomes the root and is colored black
        newNode->color = BLACK;
        tree->root = newNode;
    }
    else
        tree->root = BST(tree->root, newNode);

    // Call fixup to adjust the tree to maintain Red-Black Tree properties
    fixup(tree, newNode);

    tree->size++;
}

Node *findMin(Node *root)
{
    while (root->left)
        root = root->left;
    return root;
}

int minVal(RedBlackTree *tree) { return findMin(tree->root)->data; }

Node *findMax(Node *root)
{
    while (root->left)
        root = root->right;
    return root;
}

int maxVal(RedBlackTree *tree) { return findMax(tree->root)->data; }

Node *deleteNodeHelper(RedBlackTree *tree, Node *root, int data)
{
    if (!root)
        return root;

    if (data < root->data)
        root->left = deleteNodeHelper(tree, root->left, data);
    else if (data > root->data)
        root->right = deleteNodeHelper(tree, root->right, data);
    else
    {
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;

            if (!temp)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            if (temp)
                free(temp);
            temp = NULL;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNodeHelper(tree, root->right, temp->data);
        }
    }

    if (!root)
        return root;

    if (root->color == BLACK)
        fixup(tree, root);

    return root;
}

void deleteNode(RedBlackTree *tree, int data)
{
    if (!tree || !tree->root)
        return;

    tree->root = deleteNodeHelper(tree, tree->root, data);

    if (tree->root)
        tree->root->color = BLACK;
    tree->size--;
}

bool searchHelper(Node *root, int data)
{
    if (!root)
        return false;
    if (root->data == data)
        return true;
    if (data < root->data)
        return searchHelper(root->left, data);
    return searchHelper(root->right, data);
}

bool search(RedBlackTree *tree, int data)
{
    if (!tree || !tree->root)
        return false;
    return searchHelper(tree->root, data);
}

void inOrderTraverseHelper(Node *root)
{
    if (!root)
        return;
    inOrderTraverseHelper(root->left);
    printf("%d ", root->data);
    inOrderTraverseHelper(root->right);
}

void preOrderTraverseHelper(Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preOrderTraverseHelper(root->left);
    preOrderTraverseHelper(root->right);
}

void postOrderTraverseHelper(Node *root)
{
    if (!root)
        return;
    postOrderTraverseHelper(root->left);
    postOrderTraverseHelper(root->right);
    printf("%d ", root->data);
}

void inOrderTraverse(RedBlackTree *tree)
{
    inOrderTraverseHelper(tree->root);
    printf("\n");
}

void preOrderTraverse(RedBlackTree *tree)
{
    preOrderTraverseHelper(tree->root);
    printf("\n");
}

void postOrderTraverse(RedBlackTree *tree)
{
    postOrderTraverseHelper(tree->root);
    printf("\n");
}

int size(RedBlackTree *tree)
{
    if (tree)
        return tree->size;
    return 0;
}

void destroyRedBlackTreeHelper(Node *root)
{
    if (!root)
        return;
    destroyRedBlackTreeHelper(root->left);
    destroyRedBlackTreeHelper(root->right);
    if (root)
        free(root);
    root = NULL;
}

void destroyRedBlackTree(RedBlackTree *tree)
{
    if (tree)
    {
        destroyRedBlackTreeHelper(tree->root);
        if (tree)
            free(tree);
        tree = NULL;
    }
}
