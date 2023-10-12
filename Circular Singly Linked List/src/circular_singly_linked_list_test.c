#include <stdio.h>

#include "../include/circular_singly_linked_list.h"

int main()
{
    CircularSinglyLinkedList *list = initCircularSinglyLinkedList();

    printf("Inserting elements at the beginning:\n");
    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtBeginning(list, 30);
    display(list);

    printf("\nInserting elements at the end:\n");
    insertAtEnd(list, 40);
    insertAtEnd(list, 50);
    insertAtEnd(list, 60);
    display(list);

    printf("\nInserting elements at specific positions:\n");
    insertAfterPosition(list, 99, 2);
    insertAfterPosition(list, 77, 5);
    display(list);

    printf("\nSearching for elements:\n");
    int pos = search(list, 20);
    printf("Position of 20: %d\n", pos);

    pos = search(list, 77);
    printf("Position of 77: %d\n", pos);

    printf("\nDeleting elements:\n");
    deleteElement(list, 30);
    deleteElement(list, 77); // Non-existing element
    display(list);

    printf("\nList size: %d\n", size(list));

    destroyCircularSinglyLinkedList(list);

    return 0;
}
