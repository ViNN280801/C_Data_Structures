#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/doubly_linked_list.h"

struct Node
{
    int data;          // Data included in the node, represented as integer
    struct Node *prev; // Ptr to the previous node
    struct Node *next; // Ptr to the next node
};

struct DoublyLinkedList_t
{
    struct Node *head; // Ptr to the head of the list
    int size;          // Count of elements in the list
};

DoublyLinkedList *initDoublyLinkedList()
{
    DoublyLinkedList *list = (DoublyLinkedList *)calloc(1, sizeof(DoublyLinkedList));
    if (!list)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

bool isEmpty(DoublyLinkedList *list) { return list->size == 0; }

void insertAtBeginning(DoublyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)calloc(1, sizeof(struct Node));
    if (!newNode)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head)
        list->head->prev = newNode;

    list->head = newNode;
    list->size++;
}

void insertAtEnd(DoublyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)calloc(1, sizeof(struct Node));
    if (!newNode)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (isEmpty(list))
        list->head = newNode;
    else
    {
        struct Node *current = list->head;
        while (current->next)
            current = current->next;
        newNode->prev = current;
        current->next = newNode;
    }

    list->size++;
}

void deleteElement(DoublyLinkedList *list, int data)
{
    struct Node *current = list->head;
    while (current)
    {
        if (current->data == data)
        {
            if (current->prev == NULL)
            {
                list->head = current->next;
                if (current->next)
                    current->next->prev = NULL;
            }
            else
            {
                current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;
            }
            free(current);
            current = NULL;
            list->size--;
            return;
        }
        current = current->next;
    }
}

void display(DoublyLinkedList *list)
{
    struct Node *current = list->head;
    while (current)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int size(DoublyLinkedList *list) { return list->size; }

void destroyDoublyLinkedList(DoublyLinkedList *list)
{
    struct Node *current = list->head;
    while (current)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
        temp = NULL;
    }
    free(list);
    list = NULL;
}
