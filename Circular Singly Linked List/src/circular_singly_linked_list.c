#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/circular_singly_linked_list.h"

struct Node
{
    int data;
    struct Node *next;
};

struct CircularSinglyLinkedList_t
{
    struct Node *head;
    int size;
};

CircularSinglyLinkedList *initCircularSinglyLinkedList()
{
    CircularSinglyLinkedList *list = (CircularSinglyLinkedList *)calloc(1, sizeof(CircularSinglyLinkedList));
    if (!list)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;
    return list;
}

bool isEmpty(CircularSinglyLinkedList *list) { return list->size == 0; }

void insertAtBeginning(CircularSinglyLinkedList *list, int data)
{
    struct Node *node = (struct Node *)calloc(1, sizeof(struct Node));
    if (!node)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    node->data = data;
    if (isEmpty(list))
        node->next = node; // Points to itself in an empty list
    else
    {
        node->next = list->head;
        struct Node *current = list->head;
        while (current->next != list->head)
        {
            current = current->next;
        }
        current->next = node;
    }
    list->head = node;
    list->size++;
}

void insertAtEnd(CircularSinglyLinkedList *list, int data)
{
    struct Node *node = (struct Node *)calloc(1, sizeof(struct Node));
    if (!node)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    node->data = data;
    if (isEmpty(list))
    {
        node->next = node; // Points to itself in an empty list
        list->head = node;
    }
    else
    {
        node->next = list->head;
        struct Node *current = list->head;
        while (current->next != list->head)
        {
            current = current->next;
        }
        current->next = node;
    }
    list->size++;
}

void insertAfterPosition(CircularSinglyLinkedList *list, int data, int position)
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
        struct Node *node = (struct Node *)calloc(1, sizeof(struct Node));
        if (!node)
        {
            fprintf(stderr, "Can't allocate memory for a new node: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        node->data = data;

        struct Node *current = list->head;
        for (int i = 1; i < position - 1; i++)
            current = current->next;

        node->next = current->next;
        current->next = node;
        list->size++;
    }
}

void deleteElement(CircularSinglyLinkedList *list, int data)
{
    if (isEmpty(list))
    {
        fprintf(stderr, "The list is empty, and no elements to delete: %s\n", strerror(errno));
        return;
    }

    struct Node *current = list->head;
    struct Node *prev = NULL;

    // Search for the data to delete
    do
    {
        if (current->data == data)
            break;
        prev = current;
        current = current->next;
    } while (current != list->head);

    // If the data to delete is in the head node, update head
    if (current == list->head)
    {
        if (list->size == 1)
            list->head = NULL;
        else
        {
            list->head = current->next;
            prev = list->head;
            while (prev->next != current)
                prev = prev->next;
            prev->next = list->head;
        }
    }

    // Update the next pointer of the previous node to skip the current node
    if (prev)
        prev->next = current->next;

    free(current);
    current = NULL;
    
    list->size--;
}

int search(CircularSinglyLinkedList *list, int data)
{
    if (isEmpty(list))
    {
        fprintf(stderr, "The list is empty: %s\n", strerror(errno));
        return EMPTY_VALUE;
    }

    struct Node *current = list->head;
    int position = 1;

    do
    {
        if (current->data == data)
            return position;
        current = current->next;
        position++;
    } while (current != list->head);

    // Data not found
    return EMPTY_VALUE;
}

void display(CircularSinglyLinkedList *list)
{
    if (isEmpty(list))
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = list->head;

    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("... (circular)\n");
}

int size(CircularSinglyLinkedList *list) { return list->size; }

void destroyCircularSinglyLinkedList(CircularSinglyLinkedList *list)
{
    if (list)
    {
        struct Node *current = list->head;
        struct Node *next = NULL;

        do
        {
            next = current->next;
            free(current);
            current = next;
        } while (current != list->head);

        free(list);
        list = NULL;
    }
}
