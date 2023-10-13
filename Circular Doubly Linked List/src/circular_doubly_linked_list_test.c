#include <stdio.h>

#include "../include/circular_doubly_linked_list.h"

int main()
{
    CircularDoublyLinkedList *list = initCircularDoublyLinkedList();

    // Insert elements at the beginning
    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtBeginning(list, 30);

    // Insert elements at the end
    insertAtEnd(list, 40);
    insertAtEnd(list, 50);
    insertAtEnd(list, 60);

    // Insert elements after a specific position
    insertAfterPosition(list, 25, 2);
    insertAfterPosition(list, 55, 5);

    // Display the list
    printf("Circular Doubly Linked List: ");
    display(list);

    // Search for an element
    int searchValue = 30;
    int position = search(list, searchValue);
    if (position != EMPTY_VALUE)
        printf("%d found at position %d\n", searchValue, position);
    else
        printf("%d not found in the list\n", searchValue);

    // Delete an element
    deleteElement(list, 20);

    // Display the list after deletion
    printf("Circular Doubly Linked List after deletion: ");
    display(list);

    // Get the size of the list
    int listSize = size(list);
    printf("Size of the list: %d\n", listSize);

    // Destroy the list
    destroyCircularDoublyLinkedList(list);

    return 0;
}
