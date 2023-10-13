#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/circular_doubly_linked_list.h"

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct CircularDoublyLinkedList_t
{
    struct Node *head;
    int size;
};

CircularDoublyLinkedList *initCircularDoublyLinkedList()
{
    CircularDoublyLinkedList *list = (CircularDoublyLinkedList *)calloc(1, sizeof(CircularDoublyLinkedList));
    if (!list)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;
    return list;
}

bool isEmpty(CircularDoublyLinkedList *list) { return list->size == 0; }

void insertAtBeginning(CircularDoublyLinkedList *list, int data)
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
        node->next = node;
        node->prev = node;
        list->head = node;
    }
    else
    {
        node->next = list->head;
        node->prev = list->head->prev;
        list->head->prev->next = node;
        list->head->prev = node;
        list->head = node;
    }
    list->size++;
}

void insertAtEnd(CircularDoublyLinkedList *list, int data)
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
        node->next = node;
        node->prev = node;
        list->head = node;
    }
    else
    {
        node->next = list->head;
        node->prev = list->head->prev;
        list->head->prev->next = node;
        list->head->prev = node;
    }
    list->size++;
}

void insertAfterPosition(CircularDoublyLinkedList *list, int data, int position)
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
        node->prev = current;
        current->next->prev = node;
        current->next = node;

        list->size++;
    }
}

void deleteElement(CircularDoublyLinkedList *list, int data)
{
    if (isEmpty(list))
    {
        fprintf(stderr, "The list is empty, and no elements to delete: %s\n", strerror(errno));
        return;
    }

    struct Node *current = list->head;

    do
    {
        if (current->data == data)
            break;
        current = current->next;
    } while (current != list->head);

    if (current == list->head)
    {
        if (list->size == 1)
            list->head = NULL;
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            list->head = current->next;
        }
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
    list->size--;
}

int search(CircularDoublyLinkedList *list, int data)
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

    return EMPTY_VALUE;
}

void display(CircularDoublyLinkedList *list)
{
    if (isEmpty(list))
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = list->head;

    do
    {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("... (circular)\n");
}

int size(CircularDoublyLinkedList *list) { return list->size; }

void destroyCircularDoublyLinkedList(CircularDoublyLinkedList *list)
{
    if (list)
    {
        struct Node *current = list->head, *next = NULL;

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
