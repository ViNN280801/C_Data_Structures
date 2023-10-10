#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "../include/singly_linked_list.h"

struct Node
{
    int data;
    struct Node *next;
};

struct SinglyLinkedList_t
{
    struct Node *head;
    int size;
};

SinglyLinkedList *initSinglyLinkedList()
{
    SinglyLinkedList *list = (SinglyLinkedList *)calloc(1, sizeof(SinglyLinkedList));
    if (!list)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

bool isEmpty(SinglyLinkedList *list) { return list->size == 0; }

void insertAtBeginning(SinglyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)calloc(1, sizeof(struct Node));
    if (!newNode)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void insertAtEnd(SinglyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)calloc(1, sizeof(struct Node));
    if (!newNode)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(list))
        list->head = newNode;
    else
    {
        struct Node *current = list->head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }

    list->size++;
}

void insertAfterPosition(SinglyLinkedList *list, int data, int position)
{
    if (position < 1 || position > list->size + 1)
    {
        fprintf(stderr, "Invalid position for insertion: %s\n", strerror(errno));
        return;
    }

    if (position == 1)
        insertAtBeginning(list, data);
    else if (position == list->size + 1)
        insertAtEnd(list, data);
    else
    {
        struct Node *newNode = (struct Node *)calloc(1, sizeof(struct Node));
        if (!newNode)
        {
            fprintf(stderr, "Can't allocate memory for a new node: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        newNode->data = data;
        struct Node *current = list->head;
        for (int i = 1; i < position - 1; i++)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
        list->size++;
    }
}

void deleteElement(SinglyLinkedList *list, int data)
{
    if (isEmpty(list))
    {
        fprintf(stderr, "The list is empty, and no elements to delete: %s\n", strerror(errno));
        return;
    }
    struct Node *current = list->head;
    if (current->data == data)
    {
        list->head = current->next;
        free(current);
        list->size--;
        return;
    }
    while (current->next)
    {
        if (current->next->data == data)
        {
            struct Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            list->size--;
            return;
        }
        current = current->next;
    }
}

int search(SinglyLinkedList *list, int data)
{
    struct Node *current = list->head;
    int position = 1;
    while (current)
    {
        if (current->data == data)
            return position;
        current = current->next;
        position++;
    }
    return -1;
}

void display(SinglyLinkedList *list)
{
    if (isEmpty(list))
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = list->head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int size(SinglyLinkedList *list) { return list->size; }

void destroySinglyLinkedList(SinglyLinkedList *list)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
        temp = NULL;
    }

    free(list);
    list = NULL;
}
